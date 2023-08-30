#pragma once
#include"BitMap.hpp"


struct HashChange1
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (auto ch : str)
		{
			hash += ch;
			hash *= 31;
		}

		return hash;
	}
};


struct HashChange2
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (long i = 0; i < str.size(); i++)
		{
			size_t ch = str[i];
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}
};


struct HashChange3
{
	size_t operator()(const string& str)
	{
		size_t hash = 5381;
		for (auto ch : str)
		{
			hash += (hash << 5) + ch;
		}
		return hash;
	}
};

template<size_t N,class K=string,class Hash1= HashChange1,class Hash2=HashChange2 ,class Hash3=HashChange3>
class Bloom
{
	Hash1 hash1;
	Hash2 hash2;
	Hash3 hash3;
public:
	void set(const K key)
	{
		_bit.set(hash1(key) % (_X * N));
		_bit.set(hash2(key) % (_X * N));
		_bit.set(hash3(key) % (_X * N));
	}

	bool test(const K key)
	{
		if (!_bit.test(hash1(key) % (_X * N)))
		{
			return false;
		}
		if (!_bit.test(hash2(key) % (_X * N)))
		{
			return false;
		}
		if (!_bit.test(hash3(key) % (_X * N)))
		{
			return false;
		}
		return true;
	}

private:
	static const size_t _X = 5;
	BitSet<N*_X> _bit;
};