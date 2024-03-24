class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) 
    {
       int count=1;
       int num=numbers[0]; 
        for(int i=1;i<numbers.size();i++)
        {
            if(num==numbers[i])count++;
            else
            {
                count--;
                if(count==0)
                {
                    num=numbers[i];
                    count=1;
                }
            } 
        }
        return num;
    }
};