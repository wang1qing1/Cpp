#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stdio.h>
#include<unordered_map>
using namespace std;

#define INF 0x3f3f3f3f 

template<class V,class E>
class Floyd
{
public:
	Floyd(int vsize,vector<vector<E>>& arr)
		:_Vsize(vsize),_vv(arr)
	{
		_v.resize(vsize);
		for (int i = 0; i < _Vsize; i++)
		{
			_v[i] = 'A' + i;
			_VToindex[_v[i]] = i;
		}

		short_path_floyd();
	}
	void short_path_floyd()
	{
		for (int k = 0; k < _Vsize; k++)
		{
			for (int v = 0; v < _Vsize; v++)
			{
				for (int w = 0; w < _Vsize; w++)
				{
					if (_vv[v][w] > _vv[v][k] + _vv[k][w])
					{
						_vv[v][w] = _vv[v][k] + _vv[k][w];
					}
				}
			}
		}
	}


	E GetMInPath(V v1, V v2)
	{
		return _vv[_VToindex[v1]][_VToindex[v2]];
	}

	void PrintGroup()
	{
		printf("");
		for (int i = 0; i < _Vsize; i++)
		{
			printf("%3c ", _v[i]);
		}
		cout << endl;
		for (int i = 0; i < _Vsize; i++)
		{
			cout << _v[i] << " ";
			for (int j = 0; j < _Vsize; j++)
			{
				printf("%-3d ", _vv[i][j]);
			}
			cout << endl;
		}
		
	}

private:
	int _Vsize;
	vector<vector<E>> _vv;
	vector<V> _v;
	unordered_map<V, int> _VToindex;
};

template<class V,class E>
class Dijkstra
{
public:
	Dijkstra(int vsize, vector<vector<E>>& arr)
	:_Vsize(vsize), _vv(arr)
	{
		_v.resize(vsize);
		for (int i = 0; i < _Vsize; i++)
		{
			_v[i] = 'A' + i;
			_VToindex[_v[i]] = i;
		}
		for (int i = 0; i < _Vsize; i++)
		{
			for (int j = 0; j < _Vsize; j++)
			{
				if(_vv[i][j]!=INF&&i!=j)_table[i].push_back(j);
			}
		}
	}

	int short_path_Dijkstra(V v1, V v2)
	{
		int sumpath = 0;
		int cur = _VToindex[v1];

		while (cur != _VToindex[v2])
		{
			auto& v = _table [cur];
			int minpath = INF;
			int minV=cur;
			_visited[cur] = true;
			for (auto e : v)
			{
				if (_vv[cur][e] < minpath&&_visited[e]==false)
				{
					minV = e;
					minpath = _vv[cur][e];
				}
			}
			cur = minV;
			sumpath += minpath;
		}
		return sumpath;
	}
	
	

	int _Vsize;
	vector<vector<E>> _vv;//ÁÚ½Ó¾ØÕó
	unordered_map<int, vector<int>> _table;
	unordered_map<int, bool> _visited;
	vector<V> _v;
	unordered_map<V, int> _VToindex;
};



int main()
{
	vector<vector<int>> graph(7, vector<int>(7,INF));
	for (int i = 0; i < 7; i++)graph[i][i] = 0;
	graph[0][1] = 9;
	graph[0][5] = 1;
	graph[1][0] = 9;
	graph[1][2] = 4;
	graph[1][6] = 3;
	graph[2][1] = 4;
	graph[2][3] = 2;
	graph[3][2] = 2;
	graph[3][4] = 6;
	graph[3][6] = 5;
	graph[4][3] = 6;
	graph[4][5] = 8;
	graph[4][6] = 7;
	graph[5][0] = 1;
	graph[5][4] = 8;
	graph[6][1] = 3;
	graph[6][3] = 5;
	graph[6][4] = 7;
	

	Floyd<char,int> floyd(7, graph);
	floyd.PrintGroup();

	cout << "A->D:" << floyd.GetMInPath('A', 'E');

	Dijkstra<char, int> dijkstra(7, graph);
	cout << "A->D:" << dijkstra.short_path_Dijkstra('A', 'E') << endl;;
	return 0;
}