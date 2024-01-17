class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        int left=1;
        int right=1;
        st.push_back("/");
        while(right<path.size())
        {
            if(path[right]!='/')right++;
            else
            {
                string tmp(path.begin()+left,path.begin()+right);
                cout<<tmp<<" ";
                if(!tmp.empty())
                {
                    if(tmp=="..")
                    {
                        if(st.back()!="/")st.pop_back();
                    }
                    else if(tmp==".");
                    else
                    {
                        st.push_back(tmp);
                    }
                }
                right++;
                left=right;
            }
        }
        string tmp(path.begin()+left,path.begin()+right);
        if(!tmp.empty())
        {
            if(tmp=="..")
            {
                if(st.back()!="/")st.pop_back();
            }
            else if(tmp==".");
            else
            {
                st.push_back(tmp);
            }
        }
        string ret="/";
        for(int i=1;i<st.size();i++)
        {
            ret+=st[i];
            ret+="/";
        }
        if(ret.size()>1)ret.pop_back();

        
        return ret;
    }
};