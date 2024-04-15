class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums1 int整型vector 
     * @param m int整型 
     * @param nums2 int整型vector 
     * @param n int整型 
     * @return int整型vector
     */
    vector<int> mergeArrays(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        vector<int> ret(n+m,0);
        int index=0;
        while(i<m&&j<n)
        {
            if(nums1[i]>nums2[j])ret[index++]=nums1[i++];
            else ret[index++]=nums2[j++];
        }
        while(i<m)ret[index++]=nums1[i++];
        while(j<n)ret[index++]=nums2[j++];
        while(ret.back()==0)ret.pop_back();
        return ret;

        
    }
};