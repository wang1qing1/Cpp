

//超内存！！！！！！
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int len=words[0].size();
        vector<string> ret(words.size());
        int index=0;
        ret[index]+=words[0];
        vector<int> vvpos;
        for(int right=1;right<words.size();right++)
        {
            if(words[right].size()+len+1<=maxWidth)
            {
                ret[index]+=" ";
                ret[index]+=words[right];
                len+=words[right].size()+1;
            }
            else
            {
                int pos=ret[index].find(' ');
                vvpos.push_back(pos);
                while(pos!=string::npos)vvpos.push_back(pos);
                int sizepos=vvpos.size();
                int blankcount=maxWidth-ret[index].size()-vvpos.size();
                int i=0;
                while(blankcount--)
                {
                    ret[index].insert(vvpos[i%sizepos]," ");
                    i++;
                }
                index++;
                len=words[right].size();
                ret[index]+=words[right];
                vvpos.clear();
            }
        }
        while(ret.back().empty())ret.pop_back();
        return ret;
    }
};