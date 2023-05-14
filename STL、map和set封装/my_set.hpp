
#include"RBTree.hpp"

namespace ikun
{
	template<class K>
	class my_set
	{
	public:
		typedef RBTreeNode<K> Node;
		//����map/setʹ��ͬһ�������������map��set�Ľ��ֵ�ֲ�ͬ��map--pai<K,V>�ṹ��
		//set--K�ṹ�����Ը���MapOfKey/SetOfKey�º�����ͨ��ģ���������_rbtree,�Ա��ں������
		//�ڲ�ͳһ�ķ�ʽ����map/set����Kֵ��
		struct SetOfKey
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
		my_set()
		{
			;
		}
		bool insert(const K& key)
		{
			return _rbtree.Insert(key);
		}

		void Midorder()
		{
			_rbtree.Midorder();
		}

		const Node* Find(const K& key)
		{
			return _rbtree.Find(key);
		}

		~my_set()
		{
			_rbtree.~RBTree();
		}

	private:
		RBTree<K,const K, SetOfKey> _rbtree;
	};

}
