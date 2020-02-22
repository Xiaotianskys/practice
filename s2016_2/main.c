#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int shuxianhuashu(int x)
{
    int num=x;
    int num1=0;
    while(num)
    {
        int n=num%10;
        num1+=n*n*n;
        num/=10;
    }
    if(num1==x)
        return 1;
    else
        return 0;
}

int main()
{
    int i;
    for(i=100;i<65535;i++)
    {
        if(shuxianhuashu(i))
            printf("%d\n",i);
    }
    return 0;
}
