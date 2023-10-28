class Solution {
public:
    string minWindow(string& s, string& t) {
        int sn=s.length();
        int tn=t.length();
        if(sn<tn) return "";
        unordered_map<char,int> hashs;
        unordered_map<char,int> hasht;

        for(auto &e:t) hasht[e]++;

        int left=0,right=0;
        int count=0;
        int b=-1;int e=-1;int minlen=INT_MAX;
        while(right<sn)
        {
            //进窗口
            if(hashs[s[right]]++<hasht[s[right]]) 
            {
                count++;
            }
            while(count==tn)
            {
                //找到一个覆盖子串
                if(minlen>right-left+1)
                {
                    b=left;
                    e=right;
                    minlen=right-left+1;
                }
                //出窗口
                if(--hashs[s[left]]<hasht[s[left]]) 
                {
                    count--;
                }
                left++;
            }
            right++;
        }
        if(b==-1&&e==-1) return "";
        return string(s.begin()+b,s.begin()+e+1);
    }
};