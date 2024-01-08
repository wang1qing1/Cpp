class Solution {
public:
    int lengthOfLastWord(string s) {
        while(s.back()==' ')s.pop_back();//去除尾部空格
        int n=s.rfind(' ');//反向查找第一个空格，得到最后一个空格的下标
        return s.size()-1-n;//最后一个单词长度=(最后字符一个下标-最后一个空格下标)
    }
};