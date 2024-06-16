class Solution {
public:
    long dfs(int target)
    {
        if(target==1)return 1;
        return target+dfs(target-1);
    }
    int mechanicalAccumulator(int target) {
        return dfs(target);
    }
};


struct tmp
{
    tmp()
    {
        val+=count;
        count++;
    }
    static long val; 
    static int count; 
};
long tmp::val=0; 
int tmp::count=1; 
class Solution {
public:
    int mechanicalAccumulator(int target) {
        tmp::val=0;
        tmp::count=1;
        tmp arr[target];
        return tmp::val;

    }
};

class Solution {
public:
    int ret=0;
    bool dfs(int target)
    {
        ret+=target;
        return target>1 && dfs(target-1);
    }
    int mechanicalAccumulator(int target) {
        dfs(target);
        return ret;
    }
};