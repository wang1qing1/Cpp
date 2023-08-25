#pragma once
#include<iostream>
using namespace std;

enum Color
{
	RED,
	BLACK
};
template<class K,class V>
struct _RBTreeNode
{
	_RBTreeNode(pair<K,V> kv)
		:_kv(kv),
		_col(RED),
		_left(nullptr),
		_right(nullptr),
		_parent(nullptr)
	{
	}

	pair<K, V> _kv;
	Color _col;
	_RBTreeNode<K, V>* _left;
	_RBTreeNode<K, V>* _right;
	_RBTreeNode<K, V>* _parent;
};

template<class K,class V>
class RBTRee
{
	typedef _RBTreeNode<K, V> Node;
public:
	Node* find(const K key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (key < cur->_kv.first)
			{
				cur = cur->_left;
			}
			else if (key > cur->_kv.first)
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
	bool insert(pair<K, V> kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
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
		cur = new Node(kv);
		//�ҵ��˺��ʵ�λ��

		if (kv.first < parent->_kv.first)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		cur->_parent = parent;

		while ( parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			//           g(B) 
			//     p(R)       u(R) -->
			//c(R)
			if ( grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					//�������ϵ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else //u������/u������Ϊ�ڣ���ת+��ɫ
				{
					//           g(B)                   p(R)
					//     p(R)       u(B)   -->  u(B)        g(B)
					//c(R)										     u(B)
					if (cur == parent->_left)
					{
						//�ҵ���
						RotateR(grandfather);
						parent->_col = BLACK;
						//cur->_col = RED;
						grandfather->_col = RED;
					}
					else
					{
						//            g(B) 
						//     p(R)         u(B) 
						//         c(R)
						// ����˫��
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else //grandfather->_right == parent)
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else //u������/u������Ϊ�ڣ���ת+��ɫ
				{
					//      g                        p
					//   u     p       -->      g         c
					//             c       u
					if (cur == parent->_right)
					{
						//����
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//      g
						//   u     p 
						//       c
						// ����˫��
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}
	void Inorder()
	{
		_inorder(_root);
		cout << endl;
	}

	~RBTRee()
	{
		_Destrory(_root);
		_root = nullptr;
	}
	int Height()
	{
		return _Height(_root);
	}

	bool isRBTree()
	{
		return _isRBTree(_root, 0, -1);


	}


private:

	bool _isRBTree(Node* root, int blacknum, int benchmark)
	{
		if (root == nullptr)
		{
			if (benchmark == -1)
			{
				benchmark = blacknum;
				return true;
			}
			else
			{
				if (blacknum != benchmark)
				{
					cout << "black Node !=" << endl;
					return false;
				}
			}
			
		}

		if (root->_col == BLACK)
		{
			blacknum++;
		}

		if (root->_col == RED && root->_parent && root->_parent->_col == RED)
		{
			cout << "red connect " << endl;
			return false;
		}

		return _isRBTree(root->_left, blacknum, benchmark) && _isRBTree(root->_right, blacknum, benchmark);
		
	}

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

	void _Destrory(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_Destrory(root->_left);
		_Destrory(root->_right);
		delete root;
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
	}

	Node* _root = nullptr;

};