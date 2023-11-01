class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left=1;int right=arr.size()-1;
        int mid;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(arr[mid]>arr[mid-1]&&arr[mid+1]>arr[mid]) left=mid+1; 
            else if(arr[mid]<arr[mid-1]&&arr[mid+1]<arr[mid]) right=mid-1;
            else break;
        }
        return mid;
    }
};