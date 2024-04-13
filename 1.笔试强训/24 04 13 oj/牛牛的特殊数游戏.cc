class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return string字符串vector
     */
    vector<string> specialNumber(int n) {
        vector<string> ret;
        for(int i=1;i<=n;i++)
        {
            if(i%3==0&&i%5==0)ret.push_back("Nowcoder");
            else if(i%3==0)ret.push_back("Now");
            else if(i%5==0)ret.push_back("coder");
            else ret.push_back(to_string(i));
        }
        return ret;
    }
};