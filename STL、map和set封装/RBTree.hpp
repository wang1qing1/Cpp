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
	T _date;//�����_date�����setʹ�ã�����K�������mapʹ�þ���pair<K,V>;������ȫ��set��map��ģ�����������
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
		//�����������ǰ�Ľ�㲻�ǣ������Һ��ӣ����������һ�����
		//���ǵ�ǰ�ڵ��������������߽�㡣
		if (_node && _node->_right)
		{
			Node* curR = _node->_right;
			while (curR->_left)
			{
				curR = curR->_left;
			}
			_node = curR;
		}
		//����������Ѿ��ǣ�ĳһ�����������ұ߽ڵ�
		//��ô�������һ����㣬���Ǵӵ�ǰ��㿪ʼ�����ң����Ǹ��׵��������Ľ��ĸ��׽��
		//������ҵĹ����У����׽�㶼�����nullptr���Ǿ�˵���Ѿ���������������
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
		//���������������ĸ��ڵ㣬���ڵ�һ���Ǻ�ɫ��
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

		//��ʼ����Ƿ�Ϊά�ֺ��������
		//1. ���ڵ��Ǻ�ɫ��
		//3. ���һ���ڵ��Ǻ�ɫ�ģ��������������ӽ���Ǻ�ɫ��
		//4. ����ÿ����㣬�Ӹý�㵽�����к��Ҷ���ļ�·���ϣ���������ͬ��Ŀ�ĺ�ɫ���

		//1.�����˫�׽ڵ����ɫ�Ǻ�ɫ��û��Υ��������κ����ʣ�����Ҫ����
		//2.�����²���ڵ��˫�׽ڵ���ɫΪ��ɫʱ����Υ��������������������һ��ĺ�ɫ�ڵ�
		//curΪ��ǰ�ڵ㣬pΪ���ڵ㣬gΪ�游�ڵ㣬uΪ����ڵ�
		while (parent && parent->_col == red)
		{
			Node* grandpar = parent->_parent;
			if (parent == grandpar->_left)
			{

				Node* uncle = grandpar->_right;
				//       g
				//   p        u(red)
				//c(��ɫ)
				if (uncle && uncle->_col == red)//uncle������Ϊ��
				{
					parent->_col = block;
					uncle->_col = block;
					grandpar->_col = red;
					//�������ϸ���
					cur = grandpar;
					parent = cur->_parent;
				}
				//       g
				//   p        u(block)
				//c(�ұߵ���)
				else //uncle�����ڻ��ߴ���Ϊ��
				{
					if (cur == parent->_left)
					{
						RotateR(grandpar);
						parent->_col = block;
						grandpar->_col = red;
					}
					//        g
					//   p        u(block)
					//      c(����˫��ת)
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
				//                   c(��ɫ)
				Node* uncle = grandpar->_left;
				if (uncle && uncle->_col == red)
				{
					parent->_col = block;
					uncle->_col = block;
					grandpar->_col = red;
					//�������ϸ���
					cur = grandpar;
					parent = cur->_parent;
				}
				else//uncle�����ڻ��ߴ���Ϊ��
				{
					//           g
					//(block)u        p
					//                   c(����)
					if (cur == parent->_right)
					{
						RotateL(grandpar);
						parent->_col = block;
						grandpar->_col = red;
					}
					//           g
					//(block)u        p
					//            c(����)
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
		//��֤������Ǻ�ɫ��
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
		else//���grandp��nullptr������parent�����Ǹ��ڵ㡣
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