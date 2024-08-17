vector<vector<int>> vv;
map<pair<int, int>, int> mp;
int dfs(int n,int p,int a,int m)
{
	int sum = 0;
	for (int i = 1; i <= m; i++)
	{
		if (n == 1)return 1;
		if (vv[i][n])
		{
			sum += vv[i][n];
			p += mp[pair<int, int>(i, n)];
			if (p > a)return 0;
			int num = dfs(i, p, a,m);
			sum *= num;
		}
	}
	return sum;
}
int main()
{
	int n=3, m=6, a=3;
	vv.resize(n + 1, vector<int>(n + 1,0));
	for (int i = 0; i < m; i++)
	{
		int x=0, y=0, p=0;
		cin >> x>> y>> p;
		mp[pair<int, int>(x, y)] = p;
		vv[x][y]++;
	}

	cout << dfs(n, 0, a,n);
	
	return 0;
}