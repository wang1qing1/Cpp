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
	//插入
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
	//中序遍历
	void MidOrder()
	{
		_MidOrder(_root);
		return;
	}

	//删除
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
			else//找到 key值
			{
				if (cur->_left == nullptr)//待删除的结点左孩子为null
				{
					if (parent_cur->_left == cur)//待删除的结点是父亲结点左孩子
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
				else if (cur->_right == nullptr)//待删除的结点左孩子为null
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
				else//待删除的结点左右孩子都不是null
				{
					//寻找新的托管
					//1.找左树最大，右树最小
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



