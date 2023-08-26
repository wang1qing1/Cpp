#pragma once
#include<iostream>
using namespace std;

enum Color
{
	RED,
	BLACK
};
template<class T>
struct _RBTreeNode
{
	_RBTreeNode(T date)
		:_date(date),
		_col(RED),
		_left(nullptr),
		_right(nullptr),
		_parent(nullptr)
	{
	}

	T _date;
	Color _col;
	_RBTreeNode<T>* _left;
	_RBTreeNode<T>* _right;
	_RBTreeNode<T>* _parent;
};

template<class T,class Ref,class Ptr>
struct __iterator
{
	typedef _RBTreeNode< T> Node;
	typedef __iterator<T, Ref, Ptr> Self;
public:
	__iterator(Node*node)
		:_node(node)
	{
	}

	__iterator(const __iterator<T,T&,T*>& it)
		:_node(it._node)
	{
	}

	Ref operator*()
	{
		return _node->_date;
	}

	Ptr operator->()
	{
		return &_node->_date;
	}

	Self& operator++()
	{
		Node* curright = _node->_right;
		if (curright)
		{
			while (curright->_left)
			{
				curright = curright->_left;
			}
			_node = curright;
		}
		else//������Ϊ��
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	bool operator!=(Self it)
	{
		return it._node != _node;
	}

	Node* _node;
};

template<class K,class T,class KeyOfT>
class RBTRee
{
	KeyOfT keyoft;
	typedef _RBTreeNode<T> Node;
public:
	typedef __iterator<T, T&, T*> iterator;
	typedef __iterator<T,const T&,const T*> const_iterator;

	iterator begin()
	{
		Node* cur = _root;
		while (cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	const_iterator begin()const 
	{
		Node* cur = _root;
		while (cur->_left)
		{
			cur = cur->_left;
		}
		return const_iterator(cur);
	}

	const_iterator end()const
	{
		return const_iterator(nullptr);
	}


public:
	Node* find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (key < keyoft(cur->_date))
			{
				cur = cur->_left;
			}
			else if (key > keyoft(cur->_date))
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
	bool insert(T date)
	{
		if (_root == nullptr)
		{
			_root = new Node(date);
			_root->_col = BLACK;
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (keyoft(date) < keyoft(cur->_date))
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (keyoft(date) > keyoft(cur->_date))
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(date);
		//�ҵ��˺��ʵ�λ��

		if (keyoft(date) < keyoft(parent->_date))
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		cur->_parent = parent;

		while ( parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			//           g(B)                     g(R)
			//     p(R)       u(R)  -->     p(B)       u(B)
			//c(R)                     c(R)
			if ( grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					//�������ϵ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else //u������/u������Ϊ�ڣ���ת+��ɫ
				{
					//           g(B)                   p(R)
					//     p(R)       u(B)   -->  u(B)        g(B)
					//c(R)										     u(B)
					if (cur == parent->_left)
					{
						//�ҵ���
						RotateR(grandfather);
						parent->_col = BLACK;
						//cur->_col = RED;
						grandfather->_col = RED;
					}
					else
					{
						//            g(B)                   P(B)   
						//     p(R)         u(B)  --> c(R)          g(R)
						//         c(R)                                     u(B)
						// ����˫��
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else //grandfather->_right == parent,����������෴
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else //u������/u������Ϊ�ڣ���ת+��ɫ
				{
					if (cur == parent->_right)
					{
						//����
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						// ����˫��
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}

	void Inorder()
	{
		_inorder(_root);
		cout << endl;
	}

	~RBTRee()
	{
		_Destrory(_root);
		_root = nullptr;
	}
	int Height()
	{
		return _Height(_root);
	}

	bool isRBTree()
	{
		return _isRBTree(_root, 0, -1);
	}

private:
	//����ʱbenchmark��-1������û�л�׼ֵ���������һ��·��ʱ��
	//����һ��·���ĺ�ɫ�ڵ�����Ϊ��׼ֵ������·���ߵ�nullʱ�������׼ֵ�Ƚϡ�
	//blacknum��¼·���ϵĺ�ɫ�ڵ���
	bool _isRBTree(Node* root, int blacknum, int benchmark)
	{
		if (root == nullptr)
		{
			if (benchmark == -1)
			{
				benchmark = blacknum;
			}
			else
			{
				if (blacknum != benchmark)
				{
					cout << "black Node !=" << endl;
					return false;
				}
			}
			return true;
		}

		if (root->_col == BLACK)
		{
			blacknum++;
		}

		if (root->_col == RED && root->_parent && root->_parent->_col == RED)
		{
			cout << "red connect " << endl;
			return false;
		}

		return _isRBTree(root->_left, blacknum, benchmark) && _isRBTree(root->_right, blacknum, benchmark);
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		int Hleft = _Height(root->_left);
		int Hright = _Height(root->_right);
		return Hleft > Hright ? Hleft + 1 : Hright + 1;
	}

	void _Destrory(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_Destrory(root->_left);
		_Destrory(root->_right);
		delete root;
	}
	void _inorder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_inorder(root->_left);
		cout << keyoft(root->_date) <<" ";
		_inorder(root->_right);
	}
	void RotateL(Node* parent)
	{
		Node* curR = parent->_right;
		Node* curRL = curR->_left;

		//������㣬�����޸��丸�׽��ָ��
		parent->_right = curRL;
		if (curRL)//����Ϊ��
		{
			curRL->_parent = parent;
		}
		//���޸��������ڵ�֮ǰ�������������ڵ�ĸ���
		Node* pparent = parent->_parent;
		//�޸��������ڵ�
		curR->_left = parent;
		parent->_parent = curR;

		//�������ڵ��п������������ĸ��ڵ�
		if (pparent == nullptr)
		{
			_root = curR;
			_root->_parent = nullptr;
		}
		else//�������ڵ㲻���������ĸ��ڵ�
		{
			//��Ҫ�������������׵����ӻ����Һ���
			if (pparent->_left == parent)
			{
				pparent->_left = curR;
			}
			else
			{
				pparent->_right = curR;
			}
			curR->_parent = pparent;
		}
	}

	void RotateR(Node* parent)
	{
		Node* curL = parent->_left;
		Node* curLR = curL->_right;

		parent->_left = curLR;
		if (curLR)
		{
			curLR->_parent = parent;
		}

		Node* pparent = parent->_parent;

		curL->_right = parent;
		parent->_parent = curL;

		if (parent == _root)
		{
			_root = curL;
			_root->_parent = nullptr;
		}
		else
		{
			if (pparent->_left == parent)
			{
				pparent->_left = curL;
			}
			else
			{
				pparent->_right = curL;

			}
			curL->_parent = pparent;
		}
	}
private:
	Node* _root = nullptr;
};