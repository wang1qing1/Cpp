#pragma once
#include<iostream>
using namespace std;

template<class K, size_t M>
struct BTreeNode
{
	//K _keys[M - 1];
	//BTreeNode<K, M>* _subs[M];

	//�ؼ��ֵ���Ŀ�Ⱥ�������1
	// Ϊ�˷�������Ժ��ٷ��ѣ����һ���ռ�
	K _keys[M];//���洢�Ĺؼ���
	BTreeNode<K, M>* _subs[M+1];//���ӽ���ַ
	BTreeNode<K, M>* _parent;//���׽���ַ
	size_t _n; // ��¼ʵ�ʴ洢����ؼ��� 

	BTreeNode()
	{
		for (size_t i = 0; i < M; ++i)
		{
			_keys[i] = K();
			_subs[i] = nullptr;
		}

		_subs[M] = nullptr;
		_parent = nullptr;
		_n = 0;
	}
};

// �����Ǵ��ڴ��̣�K�Ǵ��̵�ַ
template<class K, size_t M>
class BTree
{
	typedef BTreeNode<K, M> Node;
public:
	pair<Node*, int> Find(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			// ��һ���ڵ��в���key
			size_t i = 0;
			while (i < cur->_n)
			{
				if (key < cur->_keys[i])
				{
					break;
				}
				else if (key > cur->_keys[i])
				{
					++i;
				}
				else//�ҵ�
				{
					return make_pair(cur, i);
				}
			}

			// ������ȥ��
			parent = cur;
			cur = cur->_subs[i];
		}
		//û�ҵ�
		return make_pair(parent, -1);
	}

	//��һ���ڵ��в���һ��key
	void InsertKey(Node* node, const K& key, Node* child)
	{
		int end = node->_n - 1;
		//�Ӻ���ǰŲ��key�����ĺ���
		while (end >= 0)
		{
			if (key < node->_keys[end])
			{
				// Ų��key�������Һ���
				node->_keys[end + 1] = node->_keys[end];
				node->_subs[end + 2] = node->_subs[end + 1];
 				--end;
			}
			else
			{
				break;
			}
		}

		//��� key �� child
		node->_keys[end + 1] = key;
		node->_subs[end + 2] = child;
		if (child)
		{
			child->_parent = node;
		}

		node->_n++;
	}

	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node;
			_root->_keys[0] = key;
			_root->_n++;

			return true;
		}

		// key�Ѿ����ڣ����������
		pair<Node*, int> ret = Find(key);
		if (ret.second >= 0)
		{
			return false;
		}

		// ���û���ҵ���find˳�������Ҫ������Ǹ�Ҷ�ӽڵ�

		// ѭ��ÿ����cur���� newkey��child
		Node* parent = ret.first;
		K newKey = key;
		Node* child = nullptr;
		while (1)
		{
			InsertKey(parent, newKey, child);
			// ���˾�Ҫ����
			// û����������ͽ���
			if (parent->_n < M)
			{
				return true;
			}
			else
			{
				size_t mid = M / 2;
				// ����һ��[mid+1, M-1]���ֵ�
				Node* brother = new Node;
				size_t j = 0;
				size_t i = mid + 1;
				for (; i <= M - 1; ++i)
				{
					// ���ѿ���key��key������
					brother->_keys[j] = parent->_keys[i];
					brother->_subs[j] = parent->_subs[i];
					if (parent->_subs[i])
					{
						parent->_subs[i]->_parent = brother;
					}
					++j;

					// ��������һ�·���۲�
					parent->_keys[i] = K();
					parent->_subs[i] = nullptr;
				}

				// �������һ���Һ��ӿ���
				brother->_subs[j] = parent->_subs[i];
				if (parent->_subs[i])
				{
					parent->_subs[i]->_parent = brother;
				}
				parent->_subs[i] = nullptr;

				brother->_n = j;
				parent->_n -= (brother->_n + 1);

				K midKey = parent->_keys[mid];
				parent->_keys[mid] = K();


				// ˵���ոշ����Ǹ��ڵ�
				if (parent->_parent == nullptr)
				{
					_root = new Node;
					_root->_keys[0] = midKey;
					_root->_subs[0] = parent;
					_root->_subs[1] = brother;
					_root->_n = 1;

					parent->_parent = _root;
					brother->_parent = _root;
					break;
				}
				else
				{
					// ת������parent->parent ȥ����parent->[mid] �� brother
					newKey = midKey;

					child = brother;
					parent = parent->_parent;
				}
			}
		}
		
		return true;
	}

	void _InOrder(Node* cur)
	{
		if (cur == nullptr)
			return;

		// �� ��  �� ��  ...  ��
		size_t i = 0;
		for (; i < cur->_n; ++i)
		{
			_InOrder(cur->_subs[i]); // ������
			cout << cur->_keys[i] << " "; // ��
		}

		_InOrder(cur->_subs[i]); // �����Ǹ�������
	}

	void InOrder()
	{
		_InOrder(_root);
	}

private:
	Node* _root = nullptr;
};

void TestBtree()
{
	int a[] = { 53, 139, 75, 49, 145, 36, 101 };
	BTree<int, 3> t;
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();
}