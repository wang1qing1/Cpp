class Solution {
public:
    vector<int> countBits(int n) {
    vector<int>ans;
    ans.push_back(0);//初始化
    int num = 1,m=1;
    while(num<=n) {
        for (int i = 0; i < m && num <= n; i++, num++) {//主要判断条件
            ans.push_back(ans[i] + 1);
        }
        m *= 2;//每次记得把m*=2,m就是2^x，相当于是个指标
    }
    //for (auto i : ans)cout << i << endl;
    return ans;
    }
};

class Solution {
public:
    int getBit(int num)
    {
        int ret=0;
        for(int i=0;i<=18;i++)
        {
            if(num&(1<<i))ret++;
        }
        return ret;
    }

    vector<int> countBits(int n) {
        vector<int> ret(n+1);
        for(int i=0;i<=n;i++)
        {
            ret[i]=getBit(i);
        }
        // vector<int> ret;
        // for(int i=0;i<=n;i++)
        // {
        //     ret.push_back(getBit(i));
        // }
        return ret;
    }
};