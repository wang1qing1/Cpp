class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param taskDurations int整型vector 
     * @param capacity int整型 
     * @return int整型
     */
    int animalTaskScheduler(vector<int>& task, int capacity) {
        vector<int> work(task.begin(),task.begin()+capacity);
        int index=capacity;
        int ret=0;
        while(index<task.size())
        {
            for(int i=0;i<work.size();i++)
            {
                work[i]--;
                if(work[i]==0&&index<task.size())
                {
                    work[i]=task[index++];
                }
            }
            ret++;
        }
        while(1)
        {
            bool flag=true;
            for(int i=0;i<work.size();i++)
            {
                if(work[i]>0)
                {
                    work[i]--;
                    flag=false;
                }
            }
            if(flag)break;
            ret++;
           
        }
        return ret;
    }
};