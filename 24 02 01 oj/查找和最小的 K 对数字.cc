

// class Solution {
// public:
//     typedef pair<int,int> PII;
//     struct Com
//     {
//         bool operator()(PII& e1,PII& e2)
//         {
//             auto& [a1,b1]=e1;
//             auto& [a2,b2]=e2;
//             return a1+b1<a2+b2;
//         }
//     }; 
    
//     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//         int n=0;
//         int m=0;
//         priority_queue<PII,vector<PII>,Com> q;
//         vector<vector<int>> ret;
//         while(n<nums1.size()&&m<nums2.size())
//         {
//             if(nums1[n]<nums2[m])
//             {
//                 int flag=1;
//                 for(int i=m;i<nums2.size();i++)
//                 {
//                     q.push({nums1[n],nums2[i]});
//                     if(q.size()==k)
//                     {
//                         while(!q.empty())
//                         {
//                             auto [a,b]=q.top();
//                             ret.push_back({a,b});
//                             q.pop();
//                         }
//                         flag=0;
//                         break;
//                     }
//                 }
//                 if(flag==0)break;
//                 n++;
//             }
//             else
//             {
//                 int flag=1;
//                 for(int i=n;i<nums1.size();i++)
//                 {
//                     q.push({nums1[m],nums2[i]});
//                     if(q.size()==k)
//                     {
//                         while(!q.empty())
//                         {
//                             auto [a,b]=q.top();
//                             ret.push_back({a,b});
//                             q.pop();
//                         }
//                         flag=0;
//                     }
//                 }
//                 if(flag==0)break;
//                 m++;
//             }
//         }
//         return ret;

//     }
// };




class Solution {
public:
    typedef pair<int,int> PII;
    struct Com
    {
        bool operator()(PII& e1,PII& e2)
        {
            auto& [a1,b1]=e1;
            auto& [a2,b2]=e2;
            return a1+b1<a2+b2;
        }
    }; 
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=0;
        int m=0;
        priority_queue<PII,vector<PII>,Com> q;
        vector<vector<int>> ret;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(q.size()<k)
                {
                    q.push({nums1[i],nums2[j]});
                }
                else
                {
                    auto [a,b]=q.top();
                    if((nums1[i]+nums2[j])<(a+b))
                    {
                        q.pop();
                        q.push({nums1[i],nums2[j]});
                    }
                    else break;
                }
            }
        }
        while(!q.empty())
        {
            auto& [a,b]=q.top();
            ret.push_back({a,b});
            q.pop();
        }
        return ret;

    }
};
};