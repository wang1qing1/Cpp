#pragma once
#include<vector>
#include<map>
#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

template<class V>
class SetFind
{
public:

	SetFind(size_t n)
		:_findset(n, -1)
	{}
	//合并两个结点
	void Union(V x, V y)
	{
		int rootx = findRoot(x);
		int rooty = findRoot(y);
		if (rootx == rooty)return;
		_findset[rootx] += _findset[rooty];
		_findset[rooty] = rootx;
	}
	//寻找某一个结点的根
	size_t findRoot(V x)
	{
		while (_findset[x] >= 0)
		{
			x = _findset[x];
		}
		return x;
	}
	//数据中有多少个类
	size_t Setsize()
	{
		size_t count = 0;
		for (auto e : _findset)
		{
			if (e < 0)count++;
		}
		return count;
	}
private:
	vector<int> _findset;//存储数据关系
};

template<class V,class W>
struct Edge
{
	V _srci;//源结点
	V _dsti;//目标结点
	W _w;//边权值

	Edge(V srci,V dsti,W w)
		:_srci(srci),_dsti(dsti),_w(w)
	{}
	bool operator>(const Edge& edge)
	{
		return _w > edge._w;
	}
};

//V——结点
//W——边
//Direction 有向图or无向图
template<class V, class W,W MAXW=INT_MAX,bool Direction=false>
class Graph
{
public:
	Graph(const vector<int>& Varr)
		:_V(Varr)
	{
		_matrix.resize(_V.size(), vector<V>(_V.size(), MAXW));
		for (int i = 0; i < _V.size(); i++)
		{
			_VToindex[_V[i]] = i;
		}
	}

	int GetVEdga(const V& v)
	{
		if (_VToindex.find(v) == _VToindex.end())
		{
			throw invalid_argument("结点不存在");
			return -1;
		}
		else
		{
			return _VToindex[v];
		}
	}

	void AddEdge(const V& v1, const V& v2, const W& w)
	{
		int v1index = GetVEdga(v1);
		int v2index = GetVEdga(v2);
		_W.push_back(Edge(v1,v2,w));
		//cout << v1index << " " << v2index << endl;
		_matrix[v1index][v2index] = w;
		if (Direction == false)
		{
			_matrix[v2index][v1index] = w;
		}
	}

	void Print()
	{
		for (int i = 0; i < _matrix.size(); i++)
		{
			cout << i << "->" << "[";
			for (int j = 0; j < _matrix[i].size(); j++)
			{
				cout << " "  ;
				if (_matrix[i][j] == MAXW)
				{
					cout << "*" << " ";
				}
				else cout << _matrix[i][j] << " ";
			}
			cout << "]" << endl;
		}
	}
	void DFS()
	{

	}
	void BFS()
	{

	}
	int MinCreateTree()
	{
		priority_queue<Edge, vector<Edge>, greater<Edge>> pri_que(_W.begin(),_W.end());
		SetFind<V> setfind(pri_que.size());
		Edge e = pri_que.top();


	}


private:
	vector<int> _V;//存储结点值
	unordered_map<int, int> _VToindex;//结点值和下标的对应
	vector<vector<int>> _matrix;
	map<int, vector<Edge>> _Graphtable;//index:[何其连接的边]
	vector<Edge> _W;
};

