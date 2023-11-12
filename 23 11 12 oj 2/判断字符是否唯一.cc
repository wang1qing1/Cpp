class Solution {
public:
    bool isUnique(string& astr) {
        uint32_t hash=0;
        for(auto& s:astr)
        {   
            if(hash&(1<<(s-'a')))
            {
                return false;
            }
            else
            {
                hash|=(1<<(s-'a'));
            }
        }
        return true;
    }
};