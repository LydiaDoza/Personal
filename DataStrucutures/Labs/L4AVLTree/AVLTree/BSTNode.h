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
*	void SetLeft(Node<T> * prev);
*		Sets m_prev to prev
*	Node * GetLeft()
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
	friend class AVLTree;

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
	int Height() const;

protected:
	enum balfac { RH = -1, EH = 0, LH = 1 };
	balfac m_bf;

	BSTNode * m_right;
	BSTNode * m_left;
	T m_data;
};

/**********************************************************************
* Purpose:	Default Ctor
* Entry:	None
* Exit:		m_next, m_prev set to nullptr, m_data set to default value
************************************************************************/
template <typename T>
BSTNode<T>::BSTNode() : m_right(nullptr), m_left(nullptr), m_data(), m_bf(EH)
{}

/**********************************************************************
* Purpose:	One argument Constructor
* Entry:	Data type T data
* Exit:		m_next, m_prev set to nullptr, m_data set to data
************************************************************************/
template <typename T>
BSTNode<T>::BSTNode(T data) : m_right(nullptr), m_left(nullptr), m_data(data), m_bf(EH)
{}

/**********************************************************************
* Purpose:	Copy Constructor
* Entry:	copy Node
* Exit:		this is set to node
************************************************************************/
template <typename T>
BSTNode<T>::BSTNode(const BSTNode& copy) 
	: m_right(copy.m_right), m_left(copy.m_left), m_data(copy.m_data), m_bf(copy.m_bf)
{}

/**********************************************************************
* Purpose:	Destructor
* Entry:	None
* Exit:		m_next, m_prev set to nullptr, m_data set to default value
************************************************************************/
template <typename T>
BSTNode<T>::~BSTNode()
{
	m_right = m_left = nullptr;
	m_bf = EH;
}

/**********************************************************************
* Purpose:	Sets this to node
* Entry:	Const ref of another Node
* Exit:		This is set to node
************************************************************************/
template <typename T>
BSTNode<T>& BSTNode<T>::operator=(const BSTNode<T> &rhs)
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
* Purpose:	Set Nodes next pointer
* Entry:	Node * next
* Exit:		m_next is set to next
************************************************************************/
template <typename T>
void BSTNode<T>::SetRight(BSTNode<T> * right)
{	m_right = right;	}

/**********************************************************************
* Purpose:	Returns Nodes next pointer
* Entry:	None
* Exit:		m_next pointer
************************************************************************/
template <typename T>
BSTNode<T> * BSTNode<T>::GetRight() const
{	return m_right;	  }

/**********************************************************************
* Purpose:	Sets nodes data (ADT)
* Entry:	data (ADT T)
* Exit:		m_data set to data
************************************************************************/
template <typename T>
void BSTNode<T>::SetData(T data)
{	m_data = data;   }

/**********************************************************************
* Purpose:	Get Node data
* Entry:	None
* Exit:		m_data
************************************************************************/
template <typename T>
T BSTNode<T>::GetData() const
{	return m_data;   }
/**********************************************************************
* Purpose:	Set nodes previous pointer
* Entry:	prev node pointer
* Exit:		m_prev set to prev
************************************************************************/
template <typename T>
void BSTNode<T>::SetLeft(BSTNode<T> * left)
{	m_left = left;   }

/**********************************************************************
* Purpose:	Get Node's previous pointer
* Entry:	None
* Exit:		m_prev is return
************************************************************************/
template <typename T>
BSTNode<T> * BSTNode<T>::GetLeft() const
{	return m_left;   }

/**********************************************************************
* Purpose:	returns true if this is same as compare
* Entry: 	BSTNode * compare
* Exit:		true or false
************************************************************************/
template <typename T>
bool BSTNode<T>::IsSame(T data)
{	return (m_data == data);   }

/**********************************************************************
* Purpose:	returns height of node in tree
* Entry:	none
* Exit:		Height of node in tree
************************************************************************/
template <typename T>
int BSTNode<T>::Height() const
{
	// node exists? call height on it, else int equals -1
	int left = m_left ? m_left->Height() : -1;
	int right = m_right ? m_right->Height() : -1;

	return (right > left ? right : left) + 1;
}

#endif