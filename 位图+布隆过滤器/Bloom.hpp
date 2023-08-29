#pragma once
#include"BitMap.hpp"
template<class K>
struct Hash1
{
	size_t opertor()(const K& key)
	{

	}
};

template<class K>
struct Hash2
{
	size_t opertor()(const K& key)
	{

	}
};

template<class K>
struct Hash3
{
	size_t opertor()(const K& key)
	{

	}
};

template<size_t N,class K,class Hash1,class Hash2 ,class Hash3>
class Bloom
{
	Hash1 hash1;
	Hash2 hash2;
	Hash3 hash3;
public:
	void set(const K key)
	{
		_bit.set(hash1(key));
		_bit.set(hash2(key));
		_bit.set(hash3(key));
	}

	bool test(const K key)
	{
		if (!_bit.test(hash1(key)))
		{
			return false;
		}
		if (!_bit.test(hash2(key)))
		{
			return false;
		}
		if (!_bit.test(hash3(key)))
		{
			return false;
		}
		return true;
	}


private:
	BitSet<-1> _bit;
};