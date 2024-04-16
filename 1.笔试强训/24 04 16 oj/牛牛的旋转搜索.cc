class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param arr int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int search(vector<int>& arr, int target) {
        int left=0;int right=arr.size()-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(arr[mid]==target)
            {
                int i=mid;
                while(i>0&&arr[i]==arr[i-1]) i--;
                return i;
            }
            else if(arr[left]<arr[mid])
            {
                if(target>arr[left]&&target<arr[mid])right=mid-1;
                else left=mid+1;
            }            
            else if(arr[left]>arr[mid])
            {
                if(target<arr[right]&&target>arr[mid])left=mid+1;
                else right=mid-1;
            }
            else if(arr[left]==arr[mid])
            {
                left++;
            }
            else if(arr[right]==arr[mid])
            {
                right--;
            }
        }
        return -1;
    }
};