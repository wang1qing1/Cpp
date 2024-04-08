class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) 
    {
        int num=numbers[0];
        int count=1;
        for(int i=1;i<numbers.size();i++)
        {
            if(numbers[i]==num)count++;
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