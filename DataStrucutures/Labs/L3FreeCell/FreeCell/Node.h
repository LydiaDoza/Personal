/************************************************************************
* Class: Node
*
* Managers:
*	Node()
*		m_next and m_prev is set to nullptr and m_data is set to default
*		value
*	Node(T data)
*		m_next and m_prev are set to nullptr and m_data is set to data
*	~Node()
*		m_next and m_prev are set to nullptr and m_data is automatically
*		set to default value
*	void operator=(const Node& node)
*		overloads assignment operator so that this* can be set
*
* Public Methods:
*	void SetNext(Node * next)
*		sets next node*
*	Node<T> * GetNext()
*		returns node* to next node in list
*
*	void SetData(T data);
*		Sets nodes m_data to data
*	T GetData();
*		Returns m_data
*
*	void SetPrev(Node<T> * prev);
*		Sets m_prev to prev
*	Node * GetPrev()
*		returns m_prev
*************************************************************************/
#ifndef NODE_H
#define NODE_H


template <typename T>
class Node
{
	template <typename T>
	friend class DoubleLinkedList;

public:
	Node();
	Node(T data);
	Node(const Node& copy);
	~Node();
	Node& operator = (const Node& node);

	void SetNext(Node * next);
	Node * GetNext() const;

	void SetData(T data);
	T GetData() const;

	void SetPrev(Node * prev);
	Node * GetPrev() const;

private:
	Node * m_next;
	Node * m_prev;
	T m_data;
};

/**********************************************************************
* Purpose:	Default Ctor
* Entry:	None
* Exit:		m_next, m_prev set to nullptr, m_data set to default value
************************************************************************/
template <typename T>
Node<T>::Node() : m_next(nullptr), m_prev(nullptr), m_data()
{}

/**********************************************************************
* Purpose:	One argument Constructor
* Entry:	Data type T data
* Exit:		m_next, m_prev set to nullptr, m_data set to data
************************************************************************/
template <typename T>
Node<T>::Node(T data) : m_next(nullptr), m_prev(nullptr), m_data(data)
{}

/**********************************************************************
* Purpose:	Copy Constructor
* Entry:	copy Node
* Exit:		this is set to node
************************************************************************/
template <typename T>
Node<T>::Node(const Node& copy) : m_next(nullptr), m_prev(nullptr)
{	*this = copy;   }

/**********************************************************************
* Purpose:	Destructor
* Entry:	None
* Exit:		m_next, m_prev set to nullptr, m_data set to default value
************************************************************************/
template <typename T>
Node<T>::~Node()
{	m_next = m_prev = nullptr;   }

/**********************************************************************
* Purpose:	Sets this to node
* Entry:	Const ref of another Node
* Exit:		This is set to node
************************************************************************/
template <typename T>
Node<T>& Node<T>::operator=(const Node<T> &rhs)
{
	if (this != &rhs)
	{
		m_data = rhs.m_data;
		m_next = rhs.m_next;
		m_prev = rhs.m_prev;
	}
	return *this;
}

/**********************************************************************
* Purpose:	Set Nodes next pointer
* Entry:	Node * next
* Exit:		m_next is set to next
************************************************************************/
template <typename T>
void Node<T>::SetNext(Node<T> * next)
{	m_next = next;   }

/**********************************************************************
* Purpose:	Returns Nodes next pointer
* Entry:	None
* Exit:		m_next pointer
************************************************************************/
template <typename T>
Node<T> * Node<T>::GetNext() const
{	return m_next;   }

/**********************************************************************
* Purpose:	Sets nodes data (ADT)
* Entry:	data (ADT T)
* Exit:		m_data set to data
************************************************************************/
template <typename T>
void Node<T>::SetData(T data)
{	m_data = data;   }

/**********************************************************************
* Purpose:	Get Node data
* Entry:	None
* Exit:		m_data
************************************************************************/
template <typename T>
T Node<T>::GetData() const
{	return m_data;   }

/**********************************************************************
* Purpose:	Set nodes previous pointer
* Entry:	prev node pointer
* Exit:		m_prev set to prev
************************************************************************/
template <typename T>
void Node<T>::SetPrev(Node<T> * prev)
{	m_prev = prev;   }

/**********************************************************************
* Purpose:	Get Node's previous pointer
* Entry:	None
* Exit:		m_prev is return
************************************************************************/
template <typename T>
Node<T> * Node<T>::GetPrev() const
{	return m_prev;   }
#endif