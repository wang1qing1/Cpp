#pragma once

namespace Qikun
{
	template<class T,class Container=list<T>>
	class Queue
	{
	public:
		Queue()
		{
		}

		void push(const T& val)
		{
			_q.push_back(val);
		}

		void pop()
		{
			_q.pop_front();
		}

		const T& front()
		{
			return _q.front();
		}

		const T& back()
		{
			return _q.back();
		}

		size_t size()
		{
			return _q.size();
		}

		bool empty()
		{
			return _q.empty();
		}

	private:
		Container _q;

	};


}
