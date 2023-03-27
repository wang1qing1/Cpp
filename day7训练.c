class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        stack<char> st;
        for(int i=0;i<A.length();i++)
        {
            if(A[i]=='(')
            {
                st.push(A[i]);
            }
            else if(A[i]==')')
            {
                if(st.empty())
                {
                    return false;
                }
                char tmp=st.top();
                st.pop();
                if(tmp!='(')
                {
                    return false;
                }
            }
            else{
                return false;
            }
        }
        if(!st.empty())
        return false;
        
        return true;
    }
};

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int num=0;
    cin>>num;
    int e1=0;
    int e2=1;
    int e3;
    while(1)
    {
        e3=e1+e2;
        if(e3>num)
        {
            break;
        }
        e1=e2;
        e2=e3;
    }
    cout<<((num-e2)<(e3-num)?num-e2:e3-num);
    return  0;
    return 0;
}