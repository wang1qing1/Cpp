class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param words string字符串vector 
     * @param prefix string字符串 
     * @return int整型
     */
    int countWordsWithPrefix(vector<string>& words, string prefix) {
       int len=prefix.length();
       int ret=0;
       for(auto &e:words)
       {
            if(prefix==e.substr(0,len))ret++;
       }
       return ret;
    }
};