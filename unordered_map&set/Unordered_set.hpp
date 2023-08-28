#pragma once
#include"hash.hpp"

template<class K>
class unordered_set
{
	struct SetKeyOfT
	{
		K operator()(const K& key)
		{
			return key;
		}
	};

	typedef typename HashZipper::HashBucket<K, K, SetKeyOfT>::const_iterator iterator;
	typedef typename HashZipper::HashBucket<K, K, SetKeyOfT>::const_iterator const_iterator;

public:

	bool insert(const K& key)
	{
		return _Hash.insert(key);
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
	HashZipper::HashBucket<K, K, SetKeyOfT> _Hash;
};