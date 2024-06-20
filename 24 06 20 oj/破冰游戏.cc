class Solution {
public:
    int iceBreakingGame(int num, int target) {
        list<int> arr(num);
        int j=0;
        for(auto& e:arr)e=j++;
        auto it=arr.begin();
        while(arr.size()>1)
        {
            for(int i=0;i<target-1;i++)
            {
                it++;
                if(it==arr.end())it=arr.begin();
            }
            it=arr.erase(it);
            if(it == arr.end())it = arr.begin();
        }
        return *(arr.begin());
    }
};