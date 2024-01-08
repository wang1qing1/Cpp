class Solution {
public:
    map<int,string> hash;
    Solution()
    {
        hash[1]='I';hash[5]='V';hash[10]='X';
        hash[50]='L';hash[100]='C';hash[500]='D';
        hash[1000]='M';hash[4]="IV";hash[9]="IX";
        hash[40]="XL";hash[90]="XC";hash[400]="CD";
        hash[900]="CM";
    }
    string intToRoman(int num) {
        string ret;
        while(num)
        {
            for(auto rit=hash.rbegin();rit!=hash.rend();rit++)
            {
                auto &[numb,str]=*rit;
                if(num>=numb)
                {
                    ret+=str;
                    num-=numb;
                    break;
                }
            }
        }
        hash[num]=ret;
        return ret;
    }
};