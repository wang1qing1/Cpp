#pragma once
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

namespace ikun
{
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

		//递归式插入
		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}
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
		//递归试查询
		bool FindNodeR(const K& key)
		{
			return _FindNodeR(_root, key);
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
		//递归式删除
		bool EraseR(const K& key)
		{
			return 	_EraseR(_root, key);
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
						if (cur == _root)
						{
							_root = _root->_right;
						}
						else
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
					}
					else if (cur->_right == nullptr)//待删除的结点左孩子为null
					{
						if (cur == _root)
						{
							_root = _root->_left;
						}
						else
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
					}
					else//待删除的结点左右孩子都不是null
					{
						//寻找新的托管
						//1.找左树最大，右树最小
						// 找右树最小节点替代，也可以是左树最大节点替代
						//将左树最大结点的的key与cur的key替换，然后将左树做大结点的
						//左孩子连接给其父亲结点，然后释放左树最大结点
						Node* max_cur = cur->_left;
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
		SerchBinaryTree(SerchBinaryTree<K>& t)
		{
			_root = Copy(t._root);
		}
		SerchBinaryTree()
		{
		}

		~SerchBinaryTree()
		{
			Destroy(_root);
			_root = nullptr;
		}

		SerchBinaryTree<K> operator=(SerchBinaryTree<K>& T)
		{
			swap(_root, T._root);
			return *this;
		}


	private:

		Node* _root = nullptr;

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}
			if (key > root->_key)
			{
				return _EraseR(root->_right, key);
			}
			else if(key<root->_key)
			{
				return _EraseR(root->_left, key);
			}
			else//找到
			{
				Node* denode = root;
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)
				{
					root = root->_left;
					
				}
				else
				{
					Node* maxleft = root->_left;
					while (maxleft->_right)
					{
						maxleft = maxleft->_right;
					}
					swap(maxleft->_key, root->_key);
					return _EraseR(root->_left, key);
				}
				delete denode;
			}
		}

		void Destroy(Node*_root)
		{
			if (_root == nullptr)
				return;
			Destroy(_root->_left);
			Destroy(_root->_right);
			delete _root;
		}

		bool _InsertR(Node* &root, const K& key)
		{

			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}
			if (key > root->_key)
			{
				return _InsertR(root->_right, key);
			}
			else if (key < root->_key)
			{
				return _InsertR(root->_left, key);
			}
			else
			{
				return false;
			}
		}
		bool _FindNodeR(Node*root,const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}
			if(root->_key==key)
			{
				return true;
			}
			return _FindNodeR(root->_left, key) || _FindNodeR(root->_right, key);
		}


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
		Node* Copy(const Node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}
			Node* newroot = new Node(root->_key);
			newroot->_left = Copy(root->_left);
			newroot->_right = Copy(root->_right);
			return newroot;
		}
	};
}
