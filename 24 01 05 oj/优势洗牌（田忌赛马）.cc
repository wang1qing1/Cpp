class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> ret(n);
        vector<int> index(n);
        for(int i=0;i<n;i++)index[i]=i;
        sort(nums1.begin(),nums1.end());
        sort(index.begin(),index.end(),[&](int e1,int e2)
        {
            return nums2[e1]<nums2[e2];
        });

        int right=ret.size()-1;
        int left=0;
        int t=0;//nums1
        int q=0;//index
        while(t<n)
        {
            if(nums1[t]<=nums2[index[q]])ret[index[right--]]=nums1[t++];
            else 
            {
                ret[index[left++]]=nums1[t++];
                q++;
            }
        }
        return ret;
    }
};