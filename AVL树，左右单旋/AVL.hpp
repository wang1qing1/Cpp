#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<cassert>
using namespace std;

template<class K,class V>
struct AVLNode
{
	AVLNode(pair<K, V> kv)
		:_kv(kv),_left(nullptr),_right(nullptr),_parent(nullptr),_bf(0)
	{
	}
	pair<K, V> _kv;
	AVLNode<K, V>* _left;
	AVLNode<K, V>* _right;
	AVLNode<K, V>* _parent;
	int _bf;
};

template<class K,class V>
class AVLTree
{
public:
	typedef AVLNode<K, V> Node;
	typedef pair<K, V> Type_Val;
	AVLTree()
		:_root(nullptr)
	{
	}

	bool insert(const Type_Val& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kv > cur->_kv)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kv < cur->_kv)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		//�ҵ���λ�ã����в���
		Node*tmp= new Node(kv);
		if (kv > parent->_kv)
		{
			parent->_right = tmp;
			tmp->_parent = parent;
		}
		else
		{
			parent->_left = tmp;
			tmp->_parent = parent;
		}
		
		Node* tmppar = tmp->_parent;
		while (tmppar)
		{
			//�����Ժ󣬸���ƽ������
			if (tmp == tmppar->_left)
			{
				tmppar->_bf--;
			}
			else
			{
				tmppar->_bf++;
			}
			//�鿴ƽ������,�Ƿ�������߼������ϵ���
			if (tmppar->_bf == -1 || tmppar->_bf == 1)
			{
				tmp = tmp->_parent;
				tmppar = tmppar->_parent;
			}
			else if (tmppar->_bf == 0)
			{
				//�Ѿ�ƽ��
				break;
			}
			else if (tmppar->_bf == 2|| tmppar->_bf == -2)
			{
				//���ֲ�ƽ��,��ʼ����
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}

	void Midorder()
	{
		_Midorder(_root);
	}
private:
	void _Midorder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_Midorder(root->_left);
		cout << root->_kv.first << " " << root->_bf << endl;;
		_Midorder(root->_right);
	}
	//�ҵ���
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		//������㣬��������
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}

		Node* pparent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		//�鿴�Ƿ��Ǹ��ڵ�
		if (pparent == nullptr)
		{
			_root = subL;
		}
		else
		{
			if (pparent->_left == parent)
			{
				pparent->_left = subL;
			}
			else
			{
				pparent->_right = subL;
			}
		}
		subL->_parent = pparent;
		//����ƽ������
		subL->_bf = parent->_bf = 0;
	}
	//����
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		Node* pparent = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (pparent == nullptr)
		{
			_root = subR;
		}
		else
		{
			if (pparent->_left == parent)
			{
				pparent->_left = subR;
			}
			else
			{
				pparent->_right = subR;
			}
		}
		subR->_parent = pparent;
		subR->_bf = parent->_bf = 0;
	}
	Node* _root;
};