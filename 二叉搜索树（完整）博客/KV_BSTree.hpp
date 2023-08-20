#pragma once

#pragma once
#include<iostream>
using namespace std;


template<class K,class V>
struct BSTreeNode
{
	BSTreeNode(const K& key, const V& val)
		:_key(key),
		_val(val),
		_right(nullptr),
		_left(nullptr)
	{
	}

	K _key;
	V _val;
	BSTreeNode<K,V>* _right;
	BSTreeNode<K,V>* _left;
};


template<class K, class V >
class KV_BSTree
{
	typedef BSTreeNode<K,V> Node;
public:

	KV_BSTree() = default;

	KV_BSTree(const KV_BSTree<K,V>& root)
	{
		_root = _copy(root._root);
	}

	~KV_BSTree()
	{
		Destroy(_root);
	}

	bool insert(const K& key,const V& val)
	{
		//���BSTree��û�н��
		if (_root == nullptr)
		{
			_root = new Node(key,val);
			return true;
		}

		//�ҵ�����ĺ���λ�ã����丸�׽��
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		//�ж�����
		cur = new Node(key,val);
		if (key > parent->_key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}

	Node* find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else if (key > cur->_key)
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

	bool erase(const K& key)
	{
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				//׼��ɾ��
				//��ɾ����㣬��ڵ�Ϊ�գ������ұ߽�㽻������
				if (cur->_left == nullptr)
				{
					//��ʱ���ɾ�����Ǹ��ڵ���Ҫ�ı���ڵ�ָ��
					if (cur == _root)
					{
						_root = _root->_right;
					}
					else
					{
						//�жϴ�ɾ������Ǹ��׵����ӻ����Һ���
						if (cur == parent->_left)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}

					delete cur;
					return true;

				}//��ɾ����㣬��ڵ�Ϊ�գ�������߽�㽻������
				else if (cur->_right == nullptr)
				{
					//��ʱ���ɾ�����Ǹ��ڵ���Ҫ�ı���ڵ�ָ��
					if (cur == _root)
					{
						_root = _root->_left;
					}
					else
					{
						//�жϴ�ɾ������Ǹ��׵����ӻ����Һ���
						if (cur == parent->_left)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
					delete cur;
					return true;

				}
				else
				{
					//����ɾ���Ľ�����Ҷ��к���
					//��Ҫ��һ���ܴ���ɾ������λ�ý�㣬�������������������С
					//���ʺϵĽ����ǣ������������ҽ��(���ڵ�)��������������ڵ�(��С���)
					Node* MinNode = cur->_right;
					Node* MinParent = cur;
					while (MinNode->_left)
					{
						MinParent = MinNode;
						MinNode = MinNode->_left;
					}
					//�Ƚ�MinNode���ĺ��ӽ������ĸ���
					//ע��:������Ϊ���ҵ�����߽�����ΪMinNode���һ����MinParent������
					if (MinParent->_left == MinNode)
					{
						MinParent->_left = MinNode->_right;
					}
					else
					{
						MinParent->_right = MinNode->_right;
					}
					//��MinNode����ֵ��ֵ��cur
					cur->_key = MinNode->_key;
					delete MinNode;
					return true;
				}
			}
		}
		return false;
	}

	bool Rerase(const K& key)
	{
		return _Rerase(_root, key);
	}

	Node* Rfind(const K& key)
	{
		return _Rfind(_root, key);
	}

	bool Rinsert(const K& key)
	{
		return _Rinsert(_root, key);
	}

	void InOrder()
	{
		_InOrder(_root);
	}

private:

	Node* _copy(const Node* root)
	{
		if (root == nullptr)
			return nullptr;

		Node* newnode = new Node(root->_key);
		newnode->_left = _copy(root->_left);
		newnode->_right = _copy(root->_right);
		return newnode;
	}

	void Destroy(Node* root)
	{
		if (root == nullptr)
			return;

		Destroy(root->_left);
		Destroy(root->_right);
		delete root;
	}

	bool _Rerase(Node*& root, const K& key)
	{
		if (root == nullptr)
		{
			return false;
		}

		if (key < root->_key)
		{
			return _Rerase(root->_left, key);
		}
		else if (key > root->_key)
		{
			return _Rerase(root->_right, key);
		}
		else
		{
			//��ʼɾ��
			Node* cur = root;
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
				return _Rerase(root->_left, key);
			}
			delete cur;
		}

	}

	Node* _Rfind(Node*& root, const K& key)
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		if (key < root->_key)
		{
			return _Rfind(root->_left, key);
		}
		else if (key > root->_key)
		{
			return _Rfind(root->_right, key);
		}
		else
		{
			return root;
		}
	}

	bool _Rinsert(Node*& root, const K& key)
	{
		if (root == nullptr)
		{
			root = new Node(key);
			return true;
		}
		if (key < root->_key)
		{
			return _Rinsert(root->_left, key);
		}
		else if (key > root->_key)
		{
			return _Rinsert(root->_right, key);
		}
		else
		{
			return false;
		}
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << ":" << root->_val << endl;;
		_InOrder(root->_right);
	}

	Node* _root = nullptr;
};
