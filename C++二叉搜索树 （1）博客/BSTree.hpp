
#pragma once
#include<iostream>
using namespace std;


template<class K>
struct BSTreeNode
{
	BSTreeNode(K val)
		:_val(val),
		_right(nullptr),
		_left(nullptr)
	{
	}

	K _val;
	BSTreeNode<K>* _right;
	BSTreeNode<K>* _left;
};


template<class K>
class BSTree 
{
	typedef BSTreeNode<K> Node;
public:
	
	bool insert(const K& val)
	{
		//如果BSTree还没有结点
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}

		//找到插入的合适位置，和其父亲结点
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (val < cur->_val)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (val > cur->_val)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		//判断链接
		cur = new Node(val);
		if (val > parent->_val)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}

	bool find(const K& val)
	{
		Node* cur = _root;
		while (cur)
		{
			if (val < cur->_val)
			{
				cur = cur->_left;
			}
			else if (val > cur->_val)
			{
				cur = cur->_right;
			}
			else
			{
				return true;
			}
		}
		return false;

	}

	bool erase(const K& val)
	{
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (val < cur->_val)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (val > cur->_val)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				//准备删除
				//待删除结点，左节点为空，将其右边结点交给父亲
				if (cur->_left == nullptr)
				{
					//判断待删除结点是父亲的左孩子还是右孩子
					if (cur == parent->_left)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}
					delete cur;
					return true;

				}//待删除结点，左节点为空，将其左边结点交给父亲
				else if (cur->_right == nullptr)
				{
					//判断待删除结点是父亲的左孩子还是右孩子
					if (cur == parent->_left)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_right = cur->_left;
					}
					delete cur;
					return true;

				}	
				else
				{
					//由于删除的结点左右都有孩子
					//需要找一个能代替删除结点的位置结点，即比左子树大比右子树小
					//最适合的结点就是，左子树的最右结点(最大节点)，右子树的最左节点(最小结点)
					Node* MinNode = cur->_right;
					Node* MinParent = cur;
					while (MinNode->_left)
					{
						MinParent = MinNode;
						MinNode = MinNode->_left;
					}
					//先将MinNode结点的孩子交给他的父亲
					//注意:不能因为是找的最左边结点就因为MinNode结点一定是MinParent的左孩子
					if (MinParent->_left == MinNode)
					{
						MinParent->_left = MinNode->_right;
					}
					else
					{
						MinParent->_right = MinNode->_right;
					}
					//将MinNode结点的值赋值给cur
					cur->_val = MinNode->_val;
					delete MinNode;
					return true;
				}
			}
		}
		return false;
	}

	void InOrder()
	{
		_InOrder(_root);
	}

private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_val << " " ;
		_InOrder(root->_right);
	}
	Node* _root = nullptr;
};
