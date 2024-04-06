class UnusualAdd {
public:
    int addAB(int A, int B) {
        while(B)
        {
            //A^B获得A+B的余位
            int i=A^B;
            //A&B获得A+B的进位
            //A+B的进位应该改整体前面一位加上
            int j=(A&B)<<1;
            A=i;
            B=j;
        }
        return A;
    }
};