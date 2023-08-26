#pragma once
#include"RB_Tree.hpp"


template<class K,class V>
class map
{
	struct MapKeyOfT
	{
		K operator()(pair<K, V> date)
		{
			return date.first;
		}
	};
	
public:
	typedef typename RBTRee<K, pair<K, V>, MapKeyOfT>::iterator  iterator;
	typedef typename RBTRee<K, pair<K, V>, MapKeyOfT>::const_iterator const_iterator;

	iterator begin()
	{
		return _rbTree.begin();
	}

	const_iterator begin() const
	{
		return _rbTree.begin();
	}

	iterator end()
	{
		return _rbTree.end();
	}

	const_iterator end() const
	{
		return _rbTree.end();
	}


	bool insert(const pair<K,V>& kv)
	{
		return _rbTree.insert(kv);
	}

	void Inorder()
	{
		_rbTree.Inorder();
	}

private:
	RBTRee<K, pair<K,V>, MapKeyOfT> _rbTree;
};
