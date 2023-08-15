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


	

	//比较小于的仿函数，控制大堆
	template<class T>
	struct less
	{
		bool operator()(const T& val1,const T& val2)
		{
			return val1 < val2;
		}
	};

	//比较大于的仿函数，控制小堆
	template<class T>
	struct greater
	{
		bool operator()(const T& val1, const T& val2)
		{
			return val1 > val2;
		}
	};

	template<class T, class Continer = vector<T>,class Compare =less<T>>
	class Priority_queue
	{
	public:
		Compare com;
		void push(const T& val)
		{
			_con.push_back(val);
			adjust_up(_con.size()-1);
		}

		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}

		const T& top()
		{
			return _con[0];
		}

		size_t size()
		{
			return _con.size();
		}


		bool empty()
		{
			return _con.empty();
		}

	private:
		//向上调整算法
		void adjust_up(size_t child)
		{
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				if (com(_con[parent] , _con[child]))
				{
					swap(_con[parent], _con[child]);

					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		//向下调整
		void adjust_down(size_t parent)
		{
			size_t child = parent * 2 + 1;
			while (child<_con.size())
			{
				if (child + 1 < _con.size() && com(_con[child],_con[child + 1]))
				{
					child++;
				}
				if (com(_con[parent] , _con[child]))
				{
					swap(_con[child], _con[parent]);
				}
				else
				{
					break;
				}
				parent = child;
				child = parent * 2 + 1;
			}
		}

	private:
		Continer _con;
	};
}

