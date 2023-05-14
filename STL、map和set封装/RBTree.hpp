#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;

enum color
{
	red,
	block,
};

template<class T>
struct RBTreeNode
{
	T _date;//这里的_date如果是set使用，就是K，如果是map使用就是pair<K,V>;这里完全由set，map的模板参数决定。
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	color _col;
		RBTreeNode(const T& date)
		:_date(date),
		_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_col(red)

	{
	}
};

template<class T,class Ref,class Ptr>
class RBTree_Iterator
{
public:
	typedef RBTreeNode<T> Node;
	typedef RBTree_Iterator<T, Ref, Ptr> Self;
	RBTree_Iterator(Node*node)
		:_node(node)
	{
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	Ref operator*()
	{
		return _node->_date;
	}

	Ptr operator->()
	{
		return &_node->_date;
	}

	Self& operator++(int)
	{
		//如果迭代器当前的结点不是，且有右孩子，则中序的下一个结点
		//就是当前节点的右子树的最左边结点。
		if (_node && _node->_right)
		{
			Node* curR = _node->_right;
			while (curR->_left)
			{
				curR = curR->_left;
			}
			_node = curR;
		}
		//如果迭代器已经是，某一个子树的最右边节点
		//那么中序的下一个结点，就是从当前结点开始往上找，不是父亲的右子树的结点的父亲结点
		//如果在找的过程中，父亲结点都变成了nullptr，那就说明已经遍历完整棵树。
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_right == cur)
			{
				cur = cur->_parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}

private:
	Node* _node;
};

//set<K,K>   /   map<K,pair<K,V>>
template<class T,class K,class DateOfKey>
class RBTree
{
public:
	 DateOfKey dateofkey;
	typedef RBTreeNode<K> Node;
	typedef RBTree_Iterator<K, K&, K*> iterator;


	RBTree()
	{
	}

	iterator begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	bool Insert(const K& key)
	{
		//如果插入的整棵树的根节点，根节点一定是黑色的
		if (_root == nullptr)
		{
			_root = new Node(key);
			_root->_col = block;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (dateofkey(key) < dateofkey(cur->_date))
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (dateofkey(key) > dateofkey(cur->_date))
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key);
		if (dateofkey(key) > dateofkey(parent->_date))
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		//开始检查是否为维持红黑树特性
		//1. 根节点是黑色的
		//3. 如果一个节点是红色的，则它的两个孩子结点是黑色的
		//4. 对于每个结点，从该结点到其所有后代叶结点的简单路径上，均包含相同数目的黑色结点

		//1.如果其双亲节点的颜色是黑色，没有违反红黑树任何性质，则不需要调整
		//2.但当新插入节点的双亲节点颜色为红色时，就违反了性质三不能有连在一起的红色节点
		//cur为当前节点，p为父节点，g为祖父节点，u为叔叔节点
		while (parent && parent->_col == red)
		{
			Node* grandpar = parent->_parent;
			if (parent == grandpar->_left)
			{

				Node* uncle = grandpar->_right;
				//       g
				//   p        u(red)
				//c(变色)
				if (uncle && uncle->_col == red)//uncle存在且为红
				{
					parent->_col = block;
					uncle->_col = block;
					grandpar->_col = red;
					//继续向上更改
					cur = grandpar;
					parent = cur->_parent;
				}
				//       g
				//   p        u(block)
				//c(右边单旋)
				else //uncle不存在或者存在为黑
				{
					if (cur == parent->_left)
					{
						RotateR(grandpar);
						parent->_col = block;
						grandpar->_col = red;
					}
					//        g
					//   p        u(block)
					//      c(左右双旋转)
					else
					{
						RotateL(parent);
						RotateR(grandpar);
						cur->_col = block;
						grandpar->_col = red;
					}
					break;
				}
			}
			else
			{
				//        g
				//(red)u        p
				//                   c(变色)
				Node* uncle = grandpar->_left;
				if (uncle && uncle->_col == red)
				{
					parent->_col = block;
					uncle->_col = block;
					grandpar->_col = red;
					//继续向上更改
					cur = grandpar;
					parent = cur->_parent;
				}
				else//uncle不存在或者存在为黑
				{
					//           g
					//(block)u        p
					//                   c(左单旋)
					if (cur == parent->_right)
					{
						RotateL(grandpar);
						parent->_col = block;
						grandpar->_col = red;
					}
					//           g
					//(block)u        p
					//            c(左单旋)
					else
					{
						RotateR(parent);
						RotateL(grandpar);
						cur->_col = block;
						grandpar->_col = red;
					}
					break;
				}
			}
		}
		//保证根结点是黑色；
		_root->_col = block;
		return true;
	}

	Node* Find(const T& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (key < dateofkey(cur->_date))
			{
				cur = cur->_left;
			}
			else if (key > dateofkey(cur->_date))
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

	~RBTree()
	{
		Destroy(_root);
		_root = nullptr;
	}

	void Midorder()
	{
		_Midorder(_root);
	}

private:
	void Destroy(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		Destroy(root->_left);
		Destroy(root->_right);
		delete root;
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		subR->_left = parent;

		Node* grandp = parent->_parent;

		if (subRL)
		{
			subRL->_parent = parent;
		}
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
		}
		else//如果grandp是nullptr，代表parent结点就是根节点。
		{
			if (grandp->_left == parent)
			{
				grandp->_left = subR;
			}
			else
			{
				grandp->_right = subR;
			}
		}
		subR->_parent = grandp;
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
			 
		parent->_left = subLR;
		subL->_right = parent;

		Node* grandp = parent->_parent;

		if (subLR)
		{
			subLR->_parent = parent;
		}
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			//_root->_parent == nullptr;
		}
		else
		{
			if (grandp->_left == parent)
			{
				grandp->_left = subL;
			}
			else
			{
				grandp->_right = subL;
			}
		}
		subL->_parent = grandp;
	}
	void _Midorder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_Midorder(root->_left);
		cout << root->_date.first << ":" << root->_date.second << endl;
		_Midorder(root->_right);
	}
private:
	Node* _root;
};