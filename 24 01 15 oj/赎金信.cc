class Solution {
public:
    bool canConstruct(string r, string m) {

        unordered_map<char,int> hash_ran;
        unordered_map<char,int> hash_mag;
        int n=r.size();
        int c=m.size();
        for(int i=0;i<n||i<c;i++)
        {
            if(i<c)hash_mag[m[i]]++;
            if(i<n)hash_ran[r[i]]++;
        }
        for(auto [ch,num]:hash_ran)
        {
            if(num>hash_mag[ch])return false;
        }
        return true;
    }
};