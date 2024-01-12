class Solution {
public:
    string minWindow(string s, string t) {
        int sn=s.size();
        int tn=t.size();
        if(sn<tn)return "";
        unordered_map<char,int> hasht;
        unordered_map<char,int> hashs;
        for(auto& e:t)hasht[e]++;

        int left=0;int right=0;
        int e=-1;int b=-1;int minlen=0x3f3f3f3f;
        int winsize=0;//区域大小
        int count=0;//有效字符数
        while(right<sn)
        {
            //进入窗口
            if(hashs[s[right]]++<hasht[s[right]])
            {
                count++;
            }
            //有一个覆盖区域
            while(count==tn)
            {
                if(right-left+1<minlen)
                {
                    b=left;
                    e=right;
                    minlen=right-left+1;
                }
                if(--hashs[s[left]]<hasht[s[left]])
                {
                    count--;
                }
                left++;
            }
            right++;   
        }
        return b==-1?"":string(s.begin()+b,s.begin()+e+1);
    }
};