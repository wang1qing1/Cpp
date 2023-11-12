class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ret(2, 0);
        int sum = 0;
        for (auto e : nums) sum ^= e;
        int pos = 0;
        for (int i = 0; i <= 31; i++)
        {
            if (sum & (1 << i))
            {
                pos = i;
                break;
            }
        }
        for (auto e : nums)
        {
            if (e & (1 << pos))  ret[0] ^= e;
            else    ret[1] ^= e;
        }
        return ret;
    }
};