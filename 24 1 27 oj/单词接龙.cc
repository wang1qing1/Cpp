class Solution {
public:
    vector<char> v;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) { 
        v.resize(26,'a');
        for(int i=0;i<26;i++) v[i]='a'+i;
        unordered_set<string> hash(wordList.begin(),wordList.end());
        if(hash.find(endWord)==hash.end())return 0;
        unordered_set<string> chack;
        int ret=1;
        queue<string> q;
        q.push(beginWord);
        chack.insert(beginWord);
        while(!q.empty())
        {
            ret++;
            int size=q.size();
            for(int t=0;t<size;t++)
            {
                string top=q.front();q.pop();
                for(int i=0;i<top.size();i++)
                {
                    string tmp=top;
                    for(int j=0;j<26;j++)
                    {
                        tmp[i]=v[j];
                        if(tmp==endWord&&hash.find(tmp)!=hash.end())
                        {
                            return ret;
                        }
                        if(hash.find(tmp)!=hash.end()&&chack.find(tmp)==chack.end())
                        {
                            q.push(tmp);
                            chack.insert(tmp);
                        }  
                    }
                }
            }  
        }
        return 0;
    }
};

// 2.hot 
// 3.dot lot 
// 4.dog log
// 5.cog 

// hot 
// dot lot 
// dog 
// log 


