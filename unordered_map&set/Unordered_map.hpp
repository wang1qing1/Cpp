#pragma once
#include"hash.hpp"

template<class K,class V>
class unordered_map
{
	struct MapKeyOfT
	{
		K operator()(const pair<const K,V>& key)
		{
			return key.first;
		}
	};
public:
	typedef typename HashZipper::HashBucket<K, pair<const K, V>, MapKeyOfT>::iterator iterator;
	typedef typename HashZipper::HashBucket<K, pair<const K, V>, MapKeyOfT>::const_iterator const_iterator;

public:
	bool insert(const pair<K,V>& kv)
	{
		return _Hash.insert(kv);
	}

	iterator begin()
	{
		return _Hash.begin();
	}

	iterator end()
	{
		return _Hash.end();
	}

	const_iterator begin()const
	{
		return _Hash.begin();
	}

	const_iterator end()const
	{
		return _Hash.end();
	}
private:
	HashZipper::HashBucket<K, pair<const K,V>, MapKeyOfT> _Hash;
};