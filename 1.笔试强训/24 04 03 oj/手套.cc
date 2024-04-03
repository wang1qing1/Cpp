class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        //想覆盖一边的所有颜色，只要将除了对应颜色一个都没有的手套，
        //然后将前n-1个最多的颜色的手套加一起，然后加上剩下的一种颜色的手套一个
        //就会覆盖全部颜色
        //对于某种颜色只有一边手的手套，这种必须选择
        int left_sum = 0, left_min = INT_MAX;
        int right_sum = 0, right_min = INT_MAX;
        int sum = 0;
        for(int i=0;i<n;i++){
            
            if(left[i]*right[i]==0)
                sum += left[i] + right[i];
            else{
                left_sum += left[i];
                right_sum += right[i];
                left_min = min(left_min, left[i]);
                right_min = min(right_min, right[i]);
                }
        }   
        return sum + min(left_sum-left_min+1, right_sum-right_min+1) + 1;
    }
};