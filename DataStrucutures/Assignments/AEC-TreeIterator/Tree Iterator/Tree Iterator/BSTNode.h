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
*	void SetRight(Node * right)
*		sets right node*
*	Node<T> * GetRight()
*		returns node* to right subtree
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
#ifndef BSTNODE_H
#define BSTNODE_H


template <typename T>
class BSTNode
{
	template <typename T>
	friend class BinarySearchTree;

	template <typename T>
	friend class InOrderIterator;

	template <typename T>
	friend class PreOrder;

	template <typename T>
	friend class PostOrder;

	template <typename T>
	friend class BreadthFirst;

public:
	BSTNode();
	BSTNode(T data);
	BSTNode(const BSTNode& copy);
	~BSTNode();
	BSTNode& operator = (const BSTNode& node);

	void SetRight(BSTNode * right);
	BSTNode * GetRight() const;

	void SetData(T data);
	T GetData() const;

	void SetLeft(BSTNode * left);
	BSTNode * GetLeft() const;

	bool IsSame(T data);

private:
	BSTNode * m_right_subtree;
	BSTNode * m_left_subtree;
	T m_data;
};

/**********************************************************************
* Purpose:	Default Ctor
*
* Entry:	None
*
* Exit:		m_next, m_prev set to nullptr, m_data set to default value
************************************************************************/
template <typename T>
BSTNode<T>::BSTNode() : m_right_subtree(nullptr), m_left_subtree(nullptr), m_data()
{

}

/**********************************************************************
* Purpose:	One argument Constructor
*
* Entry:	Data type T data
*
* Exit:		m_next, m_prev set to nullptr, m_data set to data
************************************************************************/
template <typename T>
BSTNode<T>::BSTNode(T data) : m_right_subtree(nullptr), m_left_subtree(nullptr), m_data(data)
{

}


/**********************************************************************
* Purpose:	Copy Constructor
*
* Entry:	copy Node
*
* Exit:		this is set to node
************************************************************************/
template <typename T>
BSTNode<T>::BSTNode(const BSTNode& copy) : m_right_subtree(copy.m_right_subtree), m_left_subtree(copy.m_left_subtree), m_data(copy.m_data)
{
	
}


/**********************************************************************
* Purpose:	Destructor
*
* Entry:	None
*
* Exit:		m_next, m_prev set to nullptr, m_data set to default value
************************************************************************/
template <typename T>
BSTNode<T>::~BSTNode()
{
	m_right_subtree = m_left_subtree = nullptr;
}

/**********************************************************************
* Purpose:	Sets this to node
*
* Entry:	Const ref of another Node
*
* Exit:		This is set to node
************************************************************************/
template <typename T>
BSTNode<T>& BSTNode<T>::operator=(const BSTNode<T> &rhs)
{
	if (this != &rhs)
	{
		m_data = rhs.m_data;
		m_right_subtree = rhs.m_right_subtree;
		m_left_subtree = rhs.m_left_subtree;
	}

	return *this;
}

/**********************************************************************
* Purpose:	Set Nodes next pointer
*
* Entry:	Node * next
*
* Exit:		m_next is set to next
************************************************************************/
template <typename T>
void BSTNode<T>::SetRight(BSTNode<T> * right)
{
	m_right_subtree = right;
}

/**********************************************************************
* Purpose:	Returns Nodes next pointer
*
* Entry:	None
*
* Exit:		m_next pointer
************************************************************************/
template <typename T>
BSTNode<T> * BSTNode<T>::GetRight() const
{
	return m_right_subtree;
}

/**********************************************************************
* Purpose:	Sets nodes data (ADT)
*
* Entry:	data (ADT T)
*
* Exit:		m_data set to data
************************************************************************/
template <typename T>
void BSTNode<T>::SetData(T data)
{
	m_data = data;
}

/**********************************************************************
* Purpose:	Get Node data
*
* Entry:	None
*
* Exit:		m_data
************************************************************************/
template <typename T>
T BSTNode<T>::GetData() const
{
	return m_data;
}

/**********************************************************************
* Purpose:	Set nodes previous pointer
*
* Entry:	prev node pointer
*
* Exit:		m_prev set to prev
************************************************************************/
template <typename T>
void BSTNode<T>::SetLeft(BSTNode<T> * left)
{
	m_left_subtree = left;
}

/**********************************************************************
* Purpose:	Get Node's previous pointer
*
* Entry:	None
*
* Exit:		m_prev is return
************************************************************************/
template <typename T>
BSTNode<T> * BSTNode<T>::GetLeft() const
{
	return m_left_subtree;
}

/**********************************************************************
* Purpose:	returns true if this is same as compare
*
* Entry: 	BSTNode * compare
*
* Exit:		true or false
************************************************************************/
template <typename T>
bool BSTNode<T>::IsSame(T data)
{
	return (m_data == data);
}

#endif