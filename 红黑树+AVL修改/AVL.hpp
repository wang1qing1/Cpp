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
	   
	pair<K, V> _kv;              //Key/Value����
	int _bf;                     //ƽ������
	AVLTreeNode<K, V>* _left;    //����������
	AVLTreeNode<K, V>* _right;   //����������
	AVLTreeNode<K, V>* _parent;  //����˫��
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
		 cur = new Node(kv);
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

			if (parent->_bf == 1||parent->_bf==-1)//�����ϵ���ƽ������
			{
				cur = parent;
				parent = cur->_parent;
			}
			else if(parent->_bf==0)//�������ϵ���ƽ������
			{
				break;
			}
			else if (parent->_bf == 2||parent->_bf==-2)//�������ϵ���ƽ�����ӣ�ֱ����ת
			{
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);//����
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);//�ҵ���
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);//����˫��
				}
				else if (parent->_bf == -2 && cur ->_bf== 1)
				{
					RotateLR(parent);//����˫��
				}
				else
				{
					//cout << parent->_bf << ":" << /*parent->_left->_bf << ":" <<*/ parent->_right->_bf << endl;
					assert(false);//�����������
				}
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}

	void Inorder()
	{
		_inorder(_root);
		cout << endl;
	}

	bool Isbalance()
	{
		return _Isbalance(_root);
	}
	

private:
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

	bool _Isbalance(Node* root)
	{
		if (root == nullptr)
		{
			return true;
		}

		int Hleft = _Height(root->_left);
		int Hright = _Height(root->_right);

		return (Hright - Hleft <= 1) && _Isbalance(root->_left) && _Isbalance(root->_right);
	}

	void _inorder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_inorder(root->_left);
		cout << root->_kv.first << " ";
		_inorder(root->_right);
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
			curR->_parent = pparent;
		}
		//�޸�ƽ������
		curR->_bf = parent->_bf = 0;
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
		curL->_bf = parent->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* curL = parent->_left;
		Node* curLR = curL->_right;
		//��ת֮ǰ������pSubLR��ƽ�����ӣ���ת���֮��
		//��Ҫ���ݸ�ƽ�����������������ڵ��ƽ������
		int curLR_bf = curLR->_bf;

		//
		RotateL(curL);
		RotateR(parent);

		if (curLR_bf == -1)
		{
			parent->_bf = 1;
			curLR->_bf = 0;
			curL->_bf = 0;
		}
		else if (curLR_bf == 1)
		{
			parent->_bf = 0;
			curL->_bf = -1;
			curLR->_bf = 0;
		}
		else if (curLR_bf == 0)
		{
			parent->_bf = 0;
			curL->_bf = 0;
			curLR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void RotateRL(Node* parent)
	{
		Node* curR = parent->_right;
		Node* curRL = curR->_left;
		int curRL_bf = curRL->_bf;

		RotateR(curR);
		RotateL(parent);

		if (curRL_bf == -1)
		{
			parent->_bf = 0;
			curRL->_bf = 0;
			curR->_bf = 1;
		}
		else if (curRL_bf == 1)
		{
			parent->_bf = -1;
			curRL->_bf = 0;
			curR->_bf = 0;
		}
		else if (curRL_bf == 0)
		{
			parent->_bf = 0;
			curRL->_bf = 0;
			curR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	Node* _root = nullptr;
};