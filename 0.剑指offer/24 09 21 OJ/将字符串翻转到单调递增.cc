class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        vector<int> left(n), right(n);
        // 统计左侧有多少1
        for (int i = 1; i < n; ++i) {
            left[i] = left[i - 1] + (s[i - 1] == '1');
        }
        // 统计右侧有多少0
        for (int j = n - 2; j >= 0; --j) {
            right[j] = right[j + 1] + (s[j + 1] == '0');
        }
        // 统计总共有多少1，最多全部1变0
        int ans = 0;
        for(int i = 0; i < n; ++i) ans += s[i] == '1';

        for(int i = 0; i < n; ++i){
            //查找从哪个位置开始，将这个位置前全部置为0，之后(包含自己)全部置为1总代价最小
            ans = min(ans, left[i] + right[i]);
        }
        return ans;
    }
};
