#pragma once
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

template<class K>
class SBTreeNode
{
public:
	SBTreeNode(K key)
		:_key(key),
		_left(nullptr),
		_right(nullptr)
	{
	}
	SBTreeNode* _left;
	SBTreeNode* _right;
	K _key;
};

template<class K>
class SerchBinaryTree
{

public:
	typedef SBTreeNode<K> Node;
	//����
	bool Insert(K key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		if (parent->_key < key)
		{
			parent->_right = new Node(key);
		}
		else
		{
			parent->_left = new Node(key);
		}
		return true;
	}

	bool FindNode(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
	//�������
	void MidOrder()
	{
		_MidOrder(_root);
		return;
	}

	//ɾ��
	bool Erase(const K& key)
	{
		Node* cur = _root;
		Node* parent_cur = nullptr;
		while (cur)
		{
			if (key > cur->_key)
			{
				parent_cur = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent_cur = cur;
				cur = cur->_left;
			}
			else//�ҵ� keyֵ
			{
				if (cur->_left == nullptr)//��ɾ���Ľ������Ϊnull
				{
					if (parent_cur->_left == cur)//��ɾ���Ľ���Ǹ��׽������
					{
						parent_cur->_left = cur->_right;
						delete cur;
					}
					else
					{
						parent_cur->_right = cur->_right;
						delete cur;
					}
				}
				else if (cur->_right == nullptr)//��ɾ���Ľ������Ϊnull
				{
					if (parent_cur->_left == cur)
					{
						parent_cur->_left = cur->_left;
						delete cur;
					}
					else
					{
						parent_cur->_right = cur->_left;
						delete cur;
					}
				}
				else//��ɾ���Ľ�����Һ��Ӷ�����null
				{
					//Ѱ���µ��й�
					//1.���������������С
					Node* max_cur = cur->_right;
					Node* parent_max_cur = cur;
					while (max_cur->_right)
					{
						parent_max_cur = max_cur;
						max_cur = max_cur->_right;
					}
					cur->_key = max_cur->_key;
					if (parent_max_cur->_left == max_cur)
					{
						parent_max_cur->_left = max_cur->_left;
					}
					else
					{
						parent_max_cur->_right = max_cur->_left;
					}
					delete max_cur;
				}
				return true;
			}
		}
		return false;
	}
private:
	Node* _root=nullptr;
	void _MidOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_MidOrder(root->_left);
		cout << root->_key << " ";
		_MidOrder(root->_right);
	}
};



