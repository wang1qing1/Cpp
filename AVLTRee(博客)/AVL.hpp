#pragma once
#include<iostream>
#include<cassert>
using namespace std;



template<class K, class V>
struct AVLTreeNode
{

	AVLTreeNode(pair<K,V> kv)
		:_kv(kv),
		_bf(0),
		_left(nullptr),
		_right(nullptr),
		_parent(nullptr)
	{
	}

	pair<K, V> _kv;
	int _bf;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
};


template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool insert(pair<K,V> kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kv.first > cur->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		//找到了合适的位置
		Node* cur = new Node(kv);
		//
		if (kv.first < parent->_kv.first)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		cur->_parent = parent;

		//调整平衡因子
		while (parent)
		{
			if (parent->_left == cur)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}

			if (parent == 1)//需向上调整平衡因子
			{
				cur = parent;
				parent = cur->_parent;
			}
			else if(parent==0)//无需向上调整平衡因子
			{
				break;
			}
			else if (parent == 2)//无需向上调整平衡因子，直接旋转
			{
				//旋转,旋转之后平衡因子已经平衡

				break;
			}
			else
			{
				assert(0);
			}
		}
		return true;
	}

	void RotateL(Node* parent)
	{
		//  a
		//     b
		//        c
		//找到需要旋转的结点
		Node* curR = parent->_right;
		Node* curRL = curR->_left;

		//调整结点，并且修改其父亲结点指针
		parent->_right = curRL;
		if (curRL)//可能为空
		{
			curRL->_parent = parent;
		}
		//在修改子树根节点之前，保存子树根节点的父亲
		Node* pparent = parent->_parent;
		//修改子树根节点
		curR->_left = parent;
		parent->_parent = curR;

		//子树根节点有可能是整棵树的根节点
		if (pparent == nullptr)
		{
			_root = curR;
			_root->_parent = nullptr;
		}
		else//子树根节点不是整棵树的根节点
		{
			//还要看子树是它父亲的左孩子还是右孩子
			if (pparent->_left == parent)
			{
				pparent->_left = curR;
			}
			else
			{
				pparent->_right = curR;
			}
		}
		//修改平衡因子
		curR->_bf = parent->_bf = 0;
	}

	void RotateR(Node* parent)
	{
		Node* curR = parent->_right;
		Node* curRL = curR->_left;

		parent->_left = curRL;
		if (curRL)
		{
			curRL->_parent = parent;
		}

		Node* pparent = parent->_parent;

		curR->_right = parent;
		parent->_parent = curR;
		
		if (pparent == nullptr)
		{
			_root = curR;
			_root->_parent = nullptr;
		}
		else
		{
			if (pparent->_left == parent)
			{
				pparent->_left = curR;
			}
			else
			{
				pparent->_right = curR;

			}
		}
		curR->_bf = parent->_bf = 0;
	}

	void RotateRL(Node* parent)
	{



	}





private:
	Node* _root = nullptr;
};