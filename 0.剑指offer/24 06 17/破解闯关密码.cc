class Solution {
public:
    string crackPassword(vector<int>& password) {
        vector<string> vstr;
        for(auto e:password)
        {
            vstr.push_back(to_string(e));
        }
        //关键自定义排序
        sort(vstr.begin(),vstr.end(),[](string &s1,string& s2){
            return (s1+s2)<(s2+s1);
        });
        string ret;
        for(auto& e:vstr)ret+=e;
        return ret;
    }
};

// 0, 3, 30, 34, 5, 9
// 0 3 30 34 5 9
// 0 30 3 34 5 9 