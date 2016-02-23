/***********************************************************
* Class:			MorseTree
*
*	<---- DAH(-)		(.)DIT---->
*
* Managers:
* 	MorseTree()
* 		Default constructor
*	MorseTree(const MorseTree & copy)
* 		Copy Ctor
*	~MorseTree()
*		Destructor
* 	void operator=(const MorseTree & rhs)
*		Overload the = operator
*
* Public Methods:
*	Insert(string data, string morsecode)
*		calls private insert,
************************************************************/
#ifndef MORSETREE_H
#define MORSETREE_H

#include "ThreadBST.h"
#include "ThreadBSTNode.h"

#include<vector>
using std::vector;

#include <string>
using std::string;


class MorseTree : public ThreadBST < char >
{
public:
	MorseTree();
	//use the parent classes 
	MorseTree(const MorseTree & copy);
	~MorseTree();

	// use the parent class's op =
	MorseTree& operator=(const MorseTree & rhs);

	void Insert(const char & data, const string & morsecode);
	string Decode(const string & morse) const;
	string Encode(const string & msg) const;

protected:
	vector<ThreadBSTNode<char>*> m_alphabet;

	void Insert(const char & data, const string & morsecode, ThreadBSTNode<char>* &root);
	string Decode(const string & morse, ThreadBSTNode<char>* root) const;
	string Encode(const string & msg, ThreadBSTNode<char> * root) const;
};

/**************************************************************
*	Purpose: 	Default Ctor
*	Entry:		None
*	Exit:		All data members set to zero or nullptr
****************************************************************/
MorseTree::MorseTree() : ThreadBST<char>()
{}

/**********************************************************************
* Purpose:	copy ctor
* Entry: 	const MorseTree & copy
* Exit:		this is equal to copy
************************************************************************/
MorseTree::MorseTree(const MorseTree & copy)
{
	*this = copy;
}

/**************************************************************
*	Purpose:	Dtor
*	Entry:		None
*	Exit:		Memory deallocated, members set back to zero
*				or nullptr
****************************************************************/
MorseTree::~MorseTree()
{
	Purge();
	m_root = nullptr;
	m_count = 0;
}

/**************************************************************
*	Purpose:	op equals
*	Entry:		MorseTree rhs
*	Exit:		this is equal to rhs
****************************************************************/
MorseTree& MorseTree::operator=(const MorseTree & rhs)
{
	if (this != &rhs)
	{
		Purge();
		m_root = Copy(rhs.m_root);
		m_alphabet = rhs.m_alphabet;
		m_count = rhs.m_count;
	}

	return *this;
}

/**********************************************************************
* Purpose:	Calls private Insert
* Entry: 	T data, T morsecode
* Exit:		Node inserted.
************************************************************************/
void MorseTree::Insert(const char & data, const string & morsecode)
{
	Insert(data, morsecode, m_root);
}

/**********************************************************************
* Purpose:	Recursively inserts null nodes until node with data is
*			inserted
* Entry: 	T data, T morsecode, ThreadBSTNode<T>* &root
* Exit:		Node inserted.
************************************************************************/
void MorseTree::Insert(const char & data, const string & morsecode, ThreadBSTNode<char>* &root)
{
	//this insures that a blank node is left behind
	if (root == nullptr)
		root = new ThreadBSTNode<char>();

	if (morsecode.length() == 0)
	{
		root->m_data = data;
		m_alphabet.push_back(root);
	}
	else
	{
		if (morsecode[0] == '.')
		{
			Insert(data, &morsecode[1], root->m_right);
			root->m_right->m_parent = root;
		}
		else
		{
			Insert(data, &morsecode[1], root->m_left);
			root->m_left->m_parent = root;
		}
	}
}

/**********************************************************************
* Purpose:	Decodes string of morse code
* Entry: 	string morse
* Exit:		void
************************************************************************/
string MorseTree::Decode(const string & morse) const
{
	return Decode(morse, m_root);
}

/**********************************************************************
* Purpose:
* Entry: 	string morse, ThreadBSTNode<string>* root
* Exit:		string
************************************************************************/
string MorseTree::Decode(const string &morse, ThreadBSTNode<char>* root) const
{
	string decoded;

	if (morse.length() != 0)
		if (morse[0] == '.')
			decoded = Decode(&morse[1], root->m_right);
		else
			decoded = Decode(&morse[1], root->m_left);
	else
		decoded = root->m_data;

	return decoded;
}

/**********************************************************************
* Purpose:	encodes message into morse code
* Entry: 	const string & msg
* Exit:		string
************************************************************************/
string MorseTree::Encode(const string & msg) const
{
	int msgSize = msg.length(), alphsize(m_alphabet.size());
	char cmpr = '\0';
	ThreadBSTNode<char> * travel = nullptr;
	vector<string> letters;
	string retmsg;

	for (int imsg(0); imsg < msgSize; imsg++)
	{
		bool found = false;
		string decoded;
		cmpr = msg[imsg];

		// find the node pointer containing the letter in the alphabet
		for (int ialph(0); ialph < alphsize && !found; ialph++)
		{
			if (m_alphabet[ialph]->m_data == cmpr)
			{
				travel = m_alphabet[ialph];
				found = true;
			}
		}
		// get morse code . and -
		// go up the tree until root
		while (travel->m_parent)
		{
			// <--- (-)			(.) --->
			if (travel->m_parent->m_left == travel)
				decoded.insert(0, "-");
			else /*if (travel->m_parent->m_right == travel)*/
				decoded.insert(0, ".");

			travel = travel->m_parent;
		}
		// put string of morse code in each cell
		letters.push_back(decoded);
	}

	for (unsigned int i(0); i < letters.size(); i++)
	{
		retmsg.append(letters[i]); // append morsecode to string
		retmsg.append(" ");
	}
	return retmsg;
}

#endif