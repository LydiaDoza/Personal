/***********************************************************
* Class:			HashTable
*
* Managers:
* 	HashTable()
* 		Default constructor
*	HashTable(int size, int(* hash)(K key) = nullptr)
*		2/1 arg ctor to initialize data members
*	HashTable(const HashTable & copy)
* 		Copy Ctor
*	~HashTable()
*		Destructor
* 	void operator=(const HashTable & rhs)
*		Overload the = operator
*
* Public Methods:
*	void Insert(K key, V value)
*		Insert element into table
*	void Delete(K key)
*		Delete element from table by using key
*	void SetHash(int(*hash)(K key))
*		Sets hash function and key value
*	void SetSize(int size)
*		Sets size of the vector m_table
*	V & operator[](K key)
*		Allows access to elements in table by using key
*	void Traverse(void(*visit)(V value))
*		Every element in table is visited once
************************************************************/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
using std::vector;

#include <list>
using std::list;
using std::pair;

#include "Exception.h"

template <typename K, typename V>
class HashTable
{
public:
	HashTable();
	HashTable(int size, int(*hash)(K key) = nullptr);
	HashTable(const HashTable<K, V> & copy);
	~HashTable();

	HashTable<K, V>& operator=(const HashTable<K, V> & rhs);

	void Insert(K key, V value);
	void Delete(K key);

	void SetHash(int(*hash)(K key)); // store the function ptr in data member
	void SetSize(int size);

	V & operator [] (K key);

	void Traverse(void(*visit)(const V & value));

private:
	vector<list<pair<K, V>>> m_table;
	int(*m_hash)(K key);

	void Rehash(vector<list<pair<K, V>>> temp);
};

/**************************************************************
*	Purpose: 	Default Ctor
*	Entry:		None
*	Exit:		All data members set to zero or nullptr
****************************************************************/
template <typename K, typename V>
HashTable<K, V>::HashTable() :m_table(), m_hash(nullptr) {}

/**********************************************************************
* Purpose:	2 arg ctor
* Entry: 	int size, int(*hash)(K key)
* Exit:		template <typename K, typename V>
************************************************************************/
template <typename K, typename V>
HashTable<K, V>::HashTable(int size, int(*hash)(K key)) : m_hash(hash)
{	m_table.resize(size);   }

/**************************************************************
*	Purpose:	Copy Ctor
*	Entry:		data member to be copied
*	Exit:		this is equal to copy
****************************************************************/
template <typename K, typename V>
HashTable<K, V>::HashTable(const HashTable<K, V> & copy) : m_table(copy.m_table), m_hash(copy.m_hash)
{}

/**************************************************************
*	Purpose:	Dtor
*	Entry:		None
*	Exit:		Memory deallocated, members set back to zero
*				or nullptr
****************************************************************/
template <typename K, typename V>
HashTable<K, V>::~HashTable()
{	m_hash = nullptr;   }

/**************************************************************
*	Purpose:	op equals
*	Entry:		HashTable rhs
*	Exit:		this is equal to rhs
****************************************************************/
template <typename K, typename V>
HashTable<K, V>& HashTable<K, V>::operator=(const HashTable<K, V> & rhs)
{
	if (this != &rhs)
	{
		m_table = rhs.m_table;
		m_hash = rhs.m_hash;
	}
	return *this;
}

/**********************************************************************
* Purpose:	Insert an element into hash table.
* Entry: 	K key, V value
* Exit:		Element inserted.
************************************************************************/
template <typename K, typename V>
void HashTable<K, V>::Insert(K key, V value)
{
	int index(0), size(m_table.size());

	if (size == 0)
		throw Exception("ERROR: Cannot insert into table with zero buckets.");

	index = m_hash(key) % size;

	for (pair<K, V> p : m_table[index])
		if (p.first == key)
			throw Exception("ERROR: Data already exists.");
	
	m_table[index].emplace_back(key, value);
}

/**********************************************************************
* Purpose:	Removes an element from hash table using key.
* Entry: 	K key
* Exit:		Element Deleted
************************************************************************/
template <typename K, typename V>
void HashTable<K, V>::Delete(K key)
{
	int index(m_hash(key) % m_table.size());
	bool found = false;
	// initialize to end iterator does the same thing as setting
	// it to null. Lists have a "NULL terminating iterator"
	list<pair<K, V>>::iterator toDelete = m_table[index].end();

	if (m_table[index].size() == 0)
		throw Exception("ERROR: list not populated.");

	for (list<pair<K, V>>::iterator lit = m_table[index].begin();
		lit != m_table[index].end();
		lit++)
	{
		if (lit->first == key)
		{
			found = true;
			toDelete = lit;
		}
	}

	if (!found)
		throw Exception("ERROR: key not in list.");

	m_table[index].erase(toDelete);
}

/**********************************************************************
* Purpose:	Sets hash function, recreates table to reflect new hash
*			function
* Entry: 	int(*hash)(K key)
* Exit:		Table is recreated.
************************************************************************/
template <typename K, typename V>
void HashTable<K, V>::SetHash(int(*hash)(K key))
{
	if (hash != m_hash)
	{
		vector<list<pair<K, V>>> temp = m_table;
		m_hash = hash;
		m_table.clear();
		m_table.resize(temp.size());
		Rehash(temp);
	}
}

/**********************************************************************
* Purpose:	Recreates Table using hash function
* Entry: 	vector<list<pair<K, V>>> temp
* Exit:		Table is recreated
************************************************************************/
template <typename K, typename V>
void HashTable<K, V>::Rehash(vector<list<pair<K, V>>> temp)
{
	//go through entire vector, through entire list, and apply hash fcn
	// to the key in pair
	for (list<pair<K, V>> & l : temp)
	{
		for (pair<K, V> & p : l)
		{
			m_table[m_hash(p.first) % m_table.size()].emplace_back(p);
		}
	}
}

/**********************************************************************
* Purpose:	Changes the size of table
* Entry: 	int size
* Exit:		Size reset
************************************************************************/
template <typename K, typename V>
void HashTable<K, V>::SetSize(int size)
{
	if (size < 0)
		throw Exception("ERROR: Cannot have a negative size.");

	if (size != m_table.size())
	{
		vector<list<pair<K, V>>> temp = m_table;
		m_table.clear();
		m_table.resize(size);
		Rehash(temp);
	}
}

/**********************************************************************
* Purpose:	Returns reference to element in table
* Entry: 	K key
* Exit:		Reference of element
************************************************************************/
template <typename K, typename V>
V & HashTable<K, V>::operator[](K key)
{
	int index(m_hash(key) % m_table.size());
	bool found = false;
	// initialize to end iterator does the same thing as setting
	// it to null. Lists have a "NULL terminating iterator"
	list<pair<K, V>>::iterator pear = m_table[index].end();

	if (m_table[index].size() == 0)
		throw Exception("ERROR: list not populated.");

	for (list<pair<K, V>>::iterator lit = m_table[index].begin();
		lit != m_table[index].end();
		lit++)
	{
		if (lit->first == key)
		{
			found = true;
			pear = lit;
		}
	}

	if (!found)
		throw Exception("ERROR: key not in list.");

	return pear->second;
}

/**********************************************************************
* Purpose:	Visits every element Value in table.
* Entry: 	void(*visit)(V value)
* Exit:		Every element is visited.
************************************************************************/
template <typename K, typename V>
void HashTable<K, V>::Traverse(void(*visit)(const V & value))
{
	int size(m_table.size());
	if (m_table.size() == 0)
		throw Exception("ERROR: Hash Table is empty.");

	// go through array
	for (list<pair<K, V>> & mylist : m_table)
	{
		for (pair<K, V> & mypair : mylist)
		{
			visit(mypair.second);
		}
		cout << "=================================================" << endl;
	}
}

#endif