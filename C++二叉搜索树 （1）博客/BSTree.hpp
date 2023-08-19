
#pragma once
#include<iostream>
using namespace std;


template<class K>
struct BSTreeNode
{
	BSTreeNode(K val)
		:_val(val),
		_right(nullptr),
		_left(nullptr)
	{
	}

	K _val;
	BSTreeNode<K>* _right;
	BSTreeNode<K>* _left;
};


template<class K>
class BSTree 
{
	typedef BSTreeNode<K> Node;
public:
	
	bool insert(const K& val)
	{
		//���BSTree��û�н��
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}

		//�ҵ�����ĺ���λ�ã����丸�׽��
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (val < cur->_val)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (val > cur->_val)
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
		cur = new Node(val);
		if (val > parent->_val)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}

	bool find(const K& val)
	{
		Node* cur = _root;
		while (cur)
		{
			if (val < cur->_val)
			{
				cur = cur->_left;
			}
			else if (val > cur->_val)
			{
				cur = cur->_right;
			}
			else
			{
				return true;
			}
		}
		return false;

	}

	bool erase(const K& val)
	{
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (val < cur->_val)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (val > cur->_val)
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
					//�жϴ�ɾ������Ǹ��׵����ӻ����Һ���
					if (cur == parent->_left)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}
					delete cur;
					return true;

				}//��ɾ����㣬��ڵ�Ϊ�գ�������߽�㽻������
				else if (cur->_right == nullptr)
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
					cur->_val = MinNode->_val;
					delete MinNode;
					return true;
				}
			}
		}
		return false;
	}

	void InOrder()
	{
		_InOrder(_root);
	}

private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_val << " " ;
		_InOrder(root->_right);
	}
	Node* _root = nullptr;
};
