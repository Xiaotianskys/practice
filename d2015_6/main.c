#include <stdio.h>
#include <stdlib.h>

int shuixianhuashu(int n)
{
    int m=n,sum=0,k;
    while(n)
    {
        k=n%10;
        sum=sum+k*k*k;
        n/=10;
    }
    if(sum==m)
        return 1;
    else
        return 0;
}

int main()
{
    int i;
    for(i=100;i<65535;i++)
    {
        if(shuixianhuashu(i))
        {
            printf("%d\t",i);
        }
    }
    putchar('\n');
    system("pause");
    return 0;
}
