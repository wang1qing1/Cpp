class Solution {
public:
    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
        srand(time(0));
        qsort(stock,0,stock.size()-1,cnt);
        return vector<int>(stock.begin(),stock.begin()+cnt);
    }

    void qsort(vector<int>& stock,int begin,int end,int k)
    {
        if(begin>=end)return;
        int mid=GetRandom(begin,end);
        int key=stock[mid];
        int i=begin;int left=begin-1;int right=end+1;
        while(i<right)
        {
            if(stock[i]<key)swap(stock[++left],stock[i++]);
            else if(stock[i]==key)i++;
            else swap(stock[--right],stock[i]);
        }
        //[begin,left][left+1,right-1][right,end]
        int l=left-begin+1;int m=right-left-1;
        if(l>k)qsort(stock,begin,left,k);
        else if(l+m>=k)return ;
        else qsort(stock,right,end,k-l-m);
    }

    int GetRandom(int begin,int end)
    {
        int num=rand()%(end-begin+1);
        return num+begin;
    }

};