#pragma once
#include<vector>
#include<iostream>

using namespace std;

template<size_t N>
class BitSet
{
public:
	BitSet()
	{
		_map.resize((N / 8) + 1, 0);
	}

	void set(const int num)
	{
		size_t i = num / 8;
		size_t j = num % 8;
		_map[i] |= 1 << j;
	}

	void erase(const int num)
	{
		size_t i = num / 8;
		size_t j = num % 8;
		_map[i] &= ~(1 << j);
	}

	bool test(const int num)
	{
		size_t i = num / 8;
		size_t j = num % 8;
		return _map[i] & (1 << j) ;
	}

private:
	vector<char> _map;
};

template<size_t  N>
class TowBitSet
{
public:
	void set(const int num)
	{
		size_t i = num / 8;
		size_t j = num % 8;
		if (_bitset1.test(num) == 0 && _bitset2.test(num) == 0)//00
		{
			_bitset1.erase(num);
			_bitset2.set(num);
		}
		else if (_bitset1.test(num) == 0 && _bitset2.test(num) == 1)//01
		{
			_bitset1.set(num);
			_bitset2.erase(num);
		}
		else if (_bitset1.test(num) == 1 && _bitset2.test(num) == 0)//10
		{
			_bitset1.set(num);
			_bitset2.set(num);
		}
		else//11ртио
		{
			;
		}
	}

	size_t test(const int num)
	{
		size_t i = num / 8;
		size_t j = num % 8;
		if (_bitset1.test(num) == 0 && _bitset2.test(num) == 0)//00
		{
			return 0;
		}
		else if (_bitset1.test(num) == 0 && _bitset2.test(num) == 1)//01
		{
			return 1;
		}
		else if (_bitset1.test(num) == 1 && _bitset2.test(num) == 0)//10
		{
			return 2;
		}
		else
		{
			return 3;
		}
	}
	
private:
	BitSet<N> _bitset1;
	BitSet<N> _bitset2;
};