#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sushu(int n)
{
    int i,k=sqrt(n);
    for(i=2;i<=k;i++)
    {
        if(n%i==0)
            break;
    }
    if(i>k)
        return 1;
    else
        return 0;
}

int main()
{
    int i;
    int j=0;    //j用来控制素数的个数
    for(i=1000;i>=2;i--)
    {
        if(sushu(i))
        {
            printf("%d ",i);
            j++;
            if(j==10)
                break;  //素数满10个之后便跳出循环
        }
    }
    putchar('\n');
    system("pause");
    return 0;
}
