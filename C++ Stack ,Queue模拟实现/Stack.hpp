#pragma once
#include<vector>
#include<string>
using namespace std;

namespace Sikun
{
	/*template<class T>
	class Stack
	{
	public:
		Stack()
		{}

		T top()
		{
			return _v.back();
		}
		void pop()
		{
			return _v.pop_back();
		}

		void push(const T& val)
		{
			_v.push_back(val);
		}

		size_t size()
		{
			return _v.size();
		}

		bool empty()
		{
			return _v.empty();
		}
	private:

		vector<T> _v;
	};*/

	template<class T ,class Container = vector<T>>
	class Stack
	{
	public:
		Stack()
		{}

		const T& top()
		{
			return _v.back();
		}
		void pop()
		{
			return _v.pop_back();
		}

		void push(const T& val)
		{
			_v.push_back(val);
		}

		size_t size()
		{
			return _v.size();
		}

		bool empty()
		{
			return _v.empty();
		}
	private:

		Container _v;
	};


}