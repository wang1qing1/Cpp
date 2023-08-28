#pragma once
#include<vector>
#include<iostream>

using namespace std;

namespace HashOpenAdress
{
	enum State
	{
		EXIST,
		EMPTY,
		DELETE
	};

	template<class K, class V>
	struct HashDate
	{
		HashDate()
		{
		}
		HashDate(pair<K,V> kv)
			:_kv(kv)
		{}

		pair<K, V> _kv;
		State state = EMPTY;
	};

	template<class K, class V>
	class HashTable
	{
		typedef HashDate<K, V> Date;
	public:
		bool insert(pair<K, V> kv)
		{
			//如果插入的值已经存在
			if (find(kv.first).second)
			{
				return false;
			}

			//扩容
			//负载因子为0.7
			if (_sh.size() == 0 || _n * 10 / _sh.size() == 7)
			{
				//确定新的容量
				int newsize = _sh.size() == 0 ? 10 : _sh.size() * 2;
				//每一次扩容都要重新插入数据
				HashTable<K, V> newHash;
				newHash._sh.resize(newsize);
				for (auto e : _sh)
				{
					newHash.insert(e._kv);
				}
				_sh.swap(newHash._sh);
			}

			//开放定值法，线性探测解决冲突
			int hashi = kv.first % _sh.size();
			int i = 1; int hashn = hashi;
			while (_sh[hashn].state == EXIST)
			{
				hashn = hashi + i;
				hashn %= _sh.size();
				i++;
			}
			_sh[hashn] = Date(kv);
			_sh[hashn].state = EXIST;
			_n++;
			return true;
		}

		bool erase(const K& key)
		{
			pair<int, bool> retfind = find(key);
			if (!retfind.second)
			{
				return false;
			}
			_sh[retfind.first].state = DELETE;
			return true;
		}

		pair<int,bool> find(const K& key)
		{
			if (_sh.empty())
			{
				return pair<int, bool>(-1, false);
			}
			size_t hashi = key % _sh.size();
			int i = 1; int hashn = hashi;
			while (_sh[hashn].state!=EMPTY)
			{
				if (_sh[hashn].state == EXIST && _sh[hashn]._kv.first == key)
				{
					return pair<int,bool>(hashn,true);
				}
				hashn = hashi + i;
				hashn %= _sh.size();
				i++;
				if (hashn == hashi)
				{
					return pair<int, bool>(-1, false);
				}
			}
			return pair<int, bool>(-1, false);
		}

	private:
		vector<Date> _sh; //数据存储
		size_t _n = 0;       //存储数据的个数
	};
}


namespace HashZipper
{


	template<class K>
	struct HashChange
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};

	template<>
	struct HashChange<string>
	{
		size_t operator()(const string& key)
		{
			size_t sum = 0;
			for (auto e : key)
			{
				sum = sum * 31 + e;
			}
			return sum;
		}
	};

	template<class K, class T>
	struct HashDate
	{
		HashDate(T date)
			:_date(date),
			_next(nullptr)
		{}

		T _date;
		HashDate* _next;
	};
	template<class K, class T, class KeyOfT, class Hash>
	class HashBucket;

	template<class K, class T,class Ref,class Ptr,class KeyOfT, class Hash>
	class __HashIterator
	{
		typedef HashDate<K, T> Node;
		typedef HashBucket<K, T,KeyOfT, Hash> HB;
		typedef __HashIterator<K, T,  Ref, Ptr,KeyOfT, Hash> Self;
		typedef __HashIterator<K, T, T&, T*, KeyOfT, Hash> iterator;
	public:
		__HashIterator(Node* node, const HB* hb)
			:_node(node),
			_hb(hb)
		{
		}

		__HashIterator(const iterator& it)
			:_node(it._node),
			_hb(it._hb)
		{
		}

		Ref operator*()
		{
			return _node->_date;
		}

		Ptr operator->()
		{
			return &_node->_date;
		}

		bool operator!=(const Self& it )
		{
			return _node != it._node;
		}

		Self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				KeyOfT keyoft;
				size_t hashi = Hash()(keyoft(_node->_date)) % _hb->_table.size();
				//Node* cur = _hb->_table[++hashi];
				while (++hashi)
				{
					if (hashi == _hb->_table.size())
					{
						_node = nullptr;
						break;
					}
					if (_hb->_table[hashi])
					{
						_node = _hb->_table[hashi];
						break;
					}
				}
				
			}
			return *this;
		}

	private:
		Node* _node;
		const HB* _hb;
	};

	template<class K,class T,class KeyOfT,class Hash = HashChange<K>>
	class HashBucket
	{
		KeyOfT keyoft;
		Hash hashchange;
		typedef HashDate<K, T> Date;

		template<class K, class T,class Ref,class Ptr,class KeyOfT, class Hash>
		friend class __HashIterator;
		//template<class K, class T, const T&, const T*, class KeyOfT, class Hash>
		//friend class __HashIterator;
		
	public:
		typedef __HashIterator<K, T, T&, T*, KeyOfT, Hash> iterator;
		typedef __HashIterator<K, T,const T&,const T*,KeyOfT, Hash> const_iterator;
	public:
		iterator begin()
		{
			for (auto cur : _table)
			{
				if (cur)
				{
					return iterator(cur, this);
				}
			}
			return iterator(nullptr, this);
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}
		
		const_iterator begin()const
		{
			for (auto cur : _table)
			{
				if (cur)
				{
					return const_iterator(cur,this);
				}
			}
			return const_iterator(nullptr,this);
		}

		const_iterator end()const
		{
			return const_iterator(nullptr,this);
		}
	public:

		bool insert(T date)
		{
			//如果待插入的数据已经存在
			if (find(keyoft(date)))
			{
				return false;
			}

			//扩容
			if (_n == _table.size())
			{
				//siz_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
				size_t newsize = GetNextPrime(_table.size());
				vector<Date*> newtable;
				newtable.resize(newsize);
				for (auto& cur : _table)
				{
					while (cur)
					{
						size_t hashi = hashchange(keyoft(cur->_date)) % newtable.size();
						Date* next = cur->_next;
						cur->_next = newtable[hashi];
						newtable[hashi] = cur;
						cur = next;
					}
				}
				_table.swap(newtable);
			}
			//插入
			size_t hashi = hashchange(keyoft(date)) % _table.size();
			Date* newNode = new Date(date);
			newNode->_next = _table[hashi];
			_table[hashi] = newNode;
			_n++;
		}

		bool insert(T date) const
		{
			//如果待插入的数据已经存在
			if (find(keyoft(date)))
			{
				return false;
			}

			//扩容
			if (_n == _table.size())
			{
				//siz_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
				size_t newsize = GetNextPrime(_table.size());
				vector<Date*> newtable;
				newtable.resize(newsize);
				for (auto& cur : _table)
				{
					while (cur)
					{
						size_t hashi = hashchange(keyoft(cur->_date)) % newtable.size();
						Date* next = cur->_next;
						cur->_next = newtable[hashi];
						newtable[hashi] = cur;
						cur = next;
					}
				}
				_table.swap(newtable);
			}
			//插入
			size_t hashi = hashchange(keyoft(date)) % _table.size();
			Date* newNode = new Date(date);
			newNode->_next = _table[hashi];
			_table[hashi] = newNode;
			_n++;
		}

		Date* find(const K& key)
		{
			if (_table.empty())
			{
				return nullptr;
			}
			size_t hashi = hashchange(key) % _table.size();
			Date* cur = _table[hashi];
			while (cur)
			{
				if (keyoft(cur->_date) == key)
				{
					return cur;
				}
				cur = cur->_next;
			}
			return nullptr;
		}

		bool erase(const K& key)
		{
			if (!find(key))
			{
				return false;
			}
			size_t hashi = hashchange(key) % _table.size();
			Date* cur = _table[hashi];
			Date* prov = nullptr;

			while (cur)
			{
				if (keyoft(cur->_date) == key)
				{
					//删除
					if (prov == nullptr)
					{
						_table[hashi] = cur->_next;	
					}
					else
					{
						prov->_next = cur->_next;
					}
					delete cur;

					return true;
				}
				else
				{
					prov = cur;
					cur = cur->_next;
				}
			}
		}

		~HashBucket()
		{
			for (auto& cur : _table)
			{
				while (cur)
				{
					Date* next = cur->_next;
					delete cur;
					cur = next;
				}
				cur = nullptr;
			}
		}

	private:

		// size_t newsize = GetNextPrime(_tables.size());
		size_t GetNextPrime(size_t prime)
		{
			// SGI
			static const int __stl_num_primes = 28;
			static const unsigned long __stl_prime_list[__stl_num_primes] =
			{
				53, 97, 193, 389, 769,
				1543, 3079, 6151, 12289, 24593,
				49157, 98317, 196613, 393241, 786433,
				1572869, 3145739, 6291469, 12582917, 25165843,
				50331653, 100663319, 201326611, 402653189, 805306457,
				1610612741, 3221225473, 4294967291
			};

			size_t i = 0;
			for (; i < __stl_num_primes; ++i)
			{
				if (__stl_prime_list[i] > prime)
					return __stl_prime_list[i];
			}

			return __stl_prime_list[i];
		}

		vector<Date*> _table;
		size_t _n = 0;
	};
}