#include <stdio.h>
int FQ(int n)
{
    int a=1;
    int b=1;
    int c=1;
    while(n>=3)
    {
        c=a+b;
        a=b;
        b=c;
        n--;
    }
    return c;
}
int main() {
    int n;
    scanf("%d",&n);
    printf("%d",FQ(n));
    return 0;
}