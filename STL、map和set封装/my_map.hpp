#pragma once
#include"RBTree.hpp"

namespace ikun
{
	template<class K, class V>
	class my_map
	{
	public:
		typedef RBTreeNode<pair<const K, V>> Node;
		typedef RBTree_Iterator<pair<const K, V>, pair<const K, V>&, pair<const K, V>*> iterator;
		struct MapOfKey
		{
			const K& operator()( const pair<K,V>& kv)
			{
				return kv.first;
			}
		};
		iterator begin()
		{
			return _rbtree.begin();
		}

		iterator end()
		{
			return _rbtree.end();
		}

		bool insert(const pair<K,V>& kv)
		{
			return _rbtree.Insert(kv);
		}
		void Midorder()
		{
			_rbtree.Midorder();
		}

		~my_map()
		{
			_rbtree.~RBTree();
		}

		Node* Find(const K& key)
		{
			return _rbtree.Find(key);
		}

	private:
		RBTree<K, pair<const K, V>, MapOfKey> _rbtree;
	};
}
