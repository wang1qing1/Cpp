//time out!!!!!!!
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        unordered_map<int,vector<int>> hash;
        //遍历每一个位置
        for(int i=0;i<n;i++) 
        {
            for(int j=1;j<=height[i];j++)//存储每一层有柱子的位置
            {
                hash[j].push_back(i);
            }
        }
        int ret=0;
        //计算相同高度柱子间的距离，就是这一层存储水的数量
        for(auto it=hash.begin();it!=hash.end();it++)
        {
            auto [a,vv]=*it;
            for(int i=1;i<vv.size();i++)
            {
                ret+=(vv[i]-vv[i-1]-1);
            }
        }
        return ret;
    }
};