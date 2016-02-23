/************************************************************************
* Class: Node
*
* Managers:
*	Node()
*		m_right_subtree and m_left_subtree is set to nullptr and m_data 
*		is set to default value.
*	Node(T data)
*		m_right_subtree and m_left_subtree are set to nullptr and m_data 
*		is set to data
*	~Node()
*		m_next and m_prev are set to nullptr and m_data is automatically
*		set to default value
*	void operator=(const Node& node)
*		overloads assignment operator so that this* can be set
*
* Public Methods:
*	void SetParent(BSTNode<T> * parent)
*		sets m_parent to parent
*	void SetLeft(BSTNode<T> * prev);
*		Sets m_prev to prev
*	void SetRight(BSTNode<T> * right)
*		sets right node*
*	void SetData(T data);
*		Sets nodes m_data to data
*
*	BSTNode<T> * GetParent()
*		returns m_parent
*	BSTNode<T> * GetLeft()
*		returns m_prev
*	BSTNode<T> * GetRight()
*		returns node* to right subtree
*	T GetData();
*		Returns m_data
*************************************************************************/
#ifndef THREADBSTNODE_H
#define THREADBSTNODE_H

template <typename T>
class ThreadBSTNode
{
	template <typename T>
	friend class ThreadBST;

	friend class MorseTree;

public:
	ThreadBSTNode();
	ThreadBSTNode(T data);
	ThreadBSTNode(const ThreadBSTNode<T>& copy);
	~ThreadBSTNode();
	ThreadBSTNode& operator = (const ThreadBSTNode<T>& node);

	void SetParent(ThreadBSTNode<T> * parent);
	void SetLeft(ThreadBSTNode<T> * left);
	void SetRight(ThreadBSTNode<T> * right);
	void SetData(T data);

	ThreadBSTNode<T> * GetParent() const;
	ThreadBSTNode<T> * GetLeft() const;
	ThreadBSTNode<T> * GetRight() const;
	T GetData() const;
	
	bool IsSame(T data) const;

protected:
	ThreadBSTNode<T> * m_parent;
	ThreadBSTNode<T> * m_right;
	ThreadBSTNode<T> * m_left;
	T m_data;
};

/**********************************************************************
* Purpose:	Default Ctor
* Entry:	None
* Exit:		m_next, m_prev set to nullptr, m_data set to default value
************************************************************************/
template <typename T>
ThreadBSTNode<T>::ThreadBSTNode() 
	: m_parent(nullptr), m_right(nullptr), m_left(nullptr), m_data()
{ }

/**********************************************************************
* Purpose:	One argument Constructor
* Entry:	Data type T data
* Exit:		m_parent, m_next, m_prev set to nullptr, m_data set to data
************************************************************************/
template <typename T>
ThreadBSTNode<T>::ThreadBSTNode(T data) 
	: m_parent(nullptr), m_right(nullptr), m_left(nullptr), m_data(data) 
{ }

/**********************************************************************
* Purpose:	Copy Constructor
* Entry:	copy Node
* Exit:		this is set to node
************************************************************************/
template <typename T>
ThreadBSTNode<T>::ThreadBSTNode(const ThreadBSTNode<T>& copy) 
	: m_parent(nullptr), m_right(nullptr), m_left(nullptr), m_data(copy.m_data)
{ *this = copy; }

/**********************************************************************
* Purpose:	Destructor
* Entry:	None
* Exit:		m_parent, m_next, m_prev set to nullptr, m_data set to 
*			default value
************************************************************************/
template <typename T>
ThreadBSTNode<T>::~ThreadBSTNode()
{ m_parent = m_right = m_left = nullptr; }

/**********************************************************************
* Purpose:	Sets this to node
* Entry:	Const ref of another Node
* Exit:		This is set to node
************************************************************************/
template <typename T>
ThreadBSTNode<T>& ThreadBSTNode<T>::operator=(const ThreadBSTNode<T> &rhs)
{
	if (this != &rhs)
	{
		m_data = rhs.m_data;
		m_right = rhs.m_right_subtree;
		m_left = rhs.m_left_subtree;
		m_bf = rhs.m_bf;
	}
	return *this;
}

/**********************************************************************
* Purpose:	Sets m_parent to parent
* Entry: 	ThreadBSTNode * parent
* Exit:		m_parent set to parent
************************************************************************/
template <typename T>
void ThreadBSTNode<T>::SetParent(ThreadBSTNode<T> * parent)
{ m_parent = parent; }

/**********************************************************************
* Purpose:	Set nodes previous pointer
* Entry:	prev node pointer
* Exit:		m_prev set to prev
************************************************************************/
template <typename T>
void ThreadBSTNode<T>::SetLeft(ThreadBSTNode<T> * left)
{ m_left = left; }

/**********************************************************************
* Purpose:	Set Nodes next pointer
* Entry:	ThreadBSTNode * next
* Exit:		m_next is set to next
************************************************************************/
template <typename T>
void ThreadBSTNode<T>::SetRight(ThreadBSTNode<T> * right)
{ m_right = right; }

/**********************************************************************
* Purpose:	Sets nodes data (ADT)
* Entry:	data (ADT T)
* Exit:		m_data set to data
************************************************************************/
template <typename T>
void ThreadBSTNode<T>::SetData(T data)
{ m_data = data; }

/**********************************************************************
* Purpose:	Returns m_parent.
* Entry:	None.
* Exit:		m_parent is returned
************************************************************************/
template <typename T>
ThreadBSTNode<T> * ThreadBSTNode<T>::GetParent() const
{ return m_parent; }

/**********************************************************************
* Purpose:	Get Node's previous pointer
* Entry:	None
* Exit:		m_prev is return
************************************************************************/
template <typename T>
ThreadBSTNode<T> * ThreadBSTNode<T>::GetLeft() const
{ return m_left; }

/**********************************************************************
* Purpose:	Returns Nodes next pointer
* Entry:	None
* Exit:		m_next pointer
************************************************************************/
template <typename T>
ThreadBSTNode<T> * ThreadBSTNode<T>::GetRight() const
{ return m_right; }

/**********************************************************************
* Purpose:	Get Node data
* Entry:	None
* Exit:		m_data
************************************************************************/
template <typename T>
T ThreadBSTNode<T>::GetData() const
{ return m_data; }

/**********************************************************************
* Purpose:	returns true if this is same as compare
* Entry: 	BSTNode * compare
* Exit:		true or false
************************************************************************/
template <typename T>
bool ThreadBSTNode<T>::IsSame(T data) const
{ return (m_data == data); }

#endif