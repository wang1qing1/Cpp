class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int asteroid : asteroids) {
            if (asteroid > 0 || st.empty() || st.top() < 0) {
                st.push(asteroid);
            } else {
                while (!st.empty() && st.top() > 0 && st.top() + asteroid < 0) {
                    st.pop();
                }
                if (st.empty() || st.top() < 0) {
                    st.push(asteroid);
                } else if (st.top() + asteroid == 0) {
                    st.pop();
                }
            }
        }
        vector<int> ret(st.size());
        for (int i = ret.size() - 1; i >= 0; --i) {
            ret[i] = st.top();
            st.pop();
        }
        return ret;
    }
};


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        st.push(asteroids[0]);
        vector<int> ret;

        for(int i=1;i<asteroids.size();i++)
        {
            if(asteroids[i]>0)st.push(asteroids[i]);
            else 
            {
                if(!st.empty()&&st.top()*asteroids[i]<0)
                {
                    if(abs(st.top())<abs(asteroids[i]))
                    {
                        while(!st.empty()&&st.top()>0&&abs(st.top())<abs(asteroids[i]))
                        {
                            st.pop();
                        }
                        //st.empty()||st.top()<0||abs(st.top())==abs(asteroids[i])
                        if(!st.empty()&&st.top()*asteroids[i]<0&&abs(st.top())==abs(asteroids[i]))st.pop();
                        else if(st.empty()||st.top()<0)st.push(asteroids[i]);
                    }
                    else if(abs(st.top())==abs(asteroids[i]))
                    {
                        st.pop();
                    }
                }
                else st.push(asteroids[i]);
            }
            
        }
        while(!st.empty())
        {
            ret.push_back(st.top());
            st.pop();
        }
        reverse(ret.begin(),ret.end());
        return ret;
        
    }
};