class Solution {
public:
    bool isAnagram(string& s, string& t) {
        map<char,int> hashs;
        map<char,int> hasht;
        int n=s.size();
        int m=t.size();
        for(int i=0;i<n||i<m;i++)
        {
            if(i<n)hashs[s[i]]++;
            if(i<m)hasht[t[i]]++;
        }
        auto sit=hashs.begin();
        auto tit=hasht.begin();
        while(sit!=hashs.end()&&tit!=hasht.end())
        {
            auto [a,b]=*sit;
            auto [i,j]=*tit;
            if(a!=i||b!=j) return false;
            sit++;
            tit++;
        }
        return  sit==hashs.end()&&tit==hasht.end()?true:false;

    }
};