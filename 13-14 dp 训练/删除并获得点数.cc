class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int arr[10001] = { 0 };

        //Êý¾ÝÓ³Éä
        for (auto e : nums)
        {
            arr[e] += e;
        }

        vector<int> f(10001, 0);
        vector<int> g(10001, 0);

        f[0] = arr[0];

        for (int i = 1; i < 10001; i++)
        {
            f[i] = g[i - 1] + arr[i];
            g[i] = max(g[i - 1], f[i - 1]);
        }

        return max(f[10000], g[10000]);
    }
};