
#include"RBTree.hpp"

namespace ikun
{
	template<class K>
	class my_set
	{
	public:
		typedef RBTreeNode<K> Node;
		//由于map/set使用同一个红黑树，但是map和set的结点值又不同，map--pai<K,V>结构，
		//set--K结构，所以给出MapOfKey/SetOfKey仿函数，通过模板参数传给_rbtree,以便在红黑树，
		//内部统一的方式访问map/set结点的K值。
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
