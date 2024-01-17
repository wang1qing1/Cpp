class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) { 
        int n=gas.size();
        vector<int> diff(n);
       
        for(int i=0;i<n;i++) diff[i]=gas[i]-cost[i];
        for(int i=0;i<n;i++) diff.push_back(diff[i]);
        if(n==1&&diff[0]<0)return -1;
        if(n==1&&diff[0]==0)return 0;
        int ret=-1;
        for(int i=0;i<n;i++)
        {
            if(diff[i]>0)//从大于0的地方开始
            {
                int tmp=0;
                int flag=1;
                for(int j=i;j<i+n;j++)
                {
                    tmp+=diff[j];
                    if(tmp<0)
                    {
                        flag=0;//途中没油了
                        i=j;//贪心优化
                        break;
                    }
                }
                if(flag)//找到一条合适的起点
                {
                    ret=i;
                    break;
                }
            }
        }
        return ret;
    }
};