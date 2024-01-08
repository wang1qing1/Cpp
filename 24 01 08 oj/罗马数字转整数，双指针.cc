class Solution {
public:
    int romanToInt(string s) {
        map<char,int> hash;
        hash['I']=1;hash['V']=5;hash['X']=10;
        hash['L']=50;hash['C']=100;
        hash['D']=500; hash['M']=1000;
        int right=s.size();
        int left=right-1;
        int ret=hash[s[right]];
        while(left>=0)
        {
            if(hash[s[left]]<hash[s[right]])
            {
                ret-=hash[s[left]];
                left--;
            }
            else
            {
                ret+=hash[s[left]];
                right=left;
                left--;
            }
        }
        return ret;
    }
};