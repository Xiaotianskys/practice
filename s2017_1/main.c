#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sushu(int x)
{
    int i;
    int temp=1;
    for(i=2;i<sqrt(x);i++)
    {
        if(x%i==0)
        {
            temp=0;
            break;
        }
    }
    return temp;
}

int main()
{
    int Mysushu[1000]={0};
    int i,k;
    k=0;
    for(i=2;i<1000;i++)
    {
        if(sushu(i))
        {
            Mysushu[k]=i;
            k++;
        }
    }
    for(i=0;i<10;i++)
    {
        printf("%d\n",Mysushu[k-1-i]);
    }
    return 0;
}
