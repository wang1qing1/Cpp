#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        //1.定义状态
        //2.状态转移方程
        //3.初始化
        vector<long> arr(n + 3);
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        for (int i = 3; i <= n; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
        }
        return arr[n];
    }
};

class Solution1 {
public:
    int tribonacci(int n) {
        //1.定义状态
        //2.状态转移方程
        //3.初始化
        int a = 0; int b = 1; int c = 1; int d = 0;
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        for (int i = 3; i <= n; i++)
        {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
};