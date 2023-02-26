
#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> vv(numRows);
    for (int i = 0; i < vv.size(); i++)
    {
        vv[i].reserve(i + 1);
        vv[i][0] = vv[i][vv.size()-1] = 1;
    }
    for (int i = 2; i < vv.size(); i++)
    {
        for (int j = 1; j < vv[i].size() - 1; j++)
        {
            vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
        }
    }
    return vv;
}



int main()
{
    generate(3);
    return 0;
}