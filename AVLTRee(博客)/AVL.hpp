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

		//�ҵ��˺��ʵ�λ��
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

		//����ƽ������
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

			if (parent == 1)//�����ϵ���ƽ������
			{
				cur = parent;
				parent = cur->_parent;
			}
			else if(parent==0)//�������ϵ���ƽ������
			{
				break;
			}
			else if (parent == 2)//�������ϵ���ƽ�����ӣ�ֱ����ת
			{
				//��ת,��ת֮��ƽ�������Ѿ�ƽ��

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
		//�ҵ���Ҫ��ת�Ľ��
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
		}
		//�޸�ƽ������
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