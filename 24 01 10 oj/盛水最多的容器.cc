class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int ret=0;
        while(left<right)
        {
            int v=min(height[left],height[right])*(right-left);
            if(height[left]<height[right])left++;
            else right--;
            ret=max(v,ret);
        }
        return ret;
    }
};