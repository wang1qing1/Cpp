class Solution {
public:
    int strStr(string haystack, string needle) {
        const char * pos=strstr(haystack.c_str(),needle.c_str());
        return pos==NULL?-1:pos-haystack.c_str();
    }
};