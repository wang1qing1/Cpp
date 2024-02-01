class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> v;
        int n1=0;
        int n2=0;
        while(n1<n&& n2<m)
        {
            if(nums1[n1]<nums2[n2])v.push_back(nums1[n1++]);
            else v.push_back(nums2[n2++]);
        }
        while(n1<n)v.push_back(nums1[n1++]);
        while(n2<m)v.push_back(nums2[n2++]);
        if((n+m)%2==0)return (v[(n+m)/2]+v[(n+m-2)/2]*1.0)/2;
        else return v[(n+m)/2]*1.0;
    }
};
};