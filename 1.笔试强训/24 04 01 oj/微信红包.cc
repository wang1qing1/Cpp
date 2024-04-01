class Gift {
  public:
    int getValue(vector<int> gifts, int n) {
        map<int,int> hash;
        for (auto e : gifts) hash[e]++;
        int target=0;
        int size=0;
        for(auto [num,s]:hash)
        {
            if(s>size)
            {
                size=s;
                target=num;
            }
        }
        return size>n/2?target:0;
    }
};