#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sushu(int n)
{
    int i,k=sqrt(n);
    for(i=2;i<=k;i++)   //这里跟之前的方法稍有不同。只要在2-k中，n除以i
        //能够除尽，则n就不是素数；否则最后循环完毕，就是素数
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

int huiwenshu(int n)
{
    int m=n;
    int sum=0;
    while(n)
    {
        sum=sum*10+n%10;
        n=n/10;
    }
    if(sum==m)
        return 1;
    else
        return 0;
}

int main()
{
    int i;
    int count=0;
    for(i=2;i<100000;i++)
    {
        if(sushu(i)&&huiwenshu(i))
        {
            printf("%6d",i);
            count++;
            if(count%10==0) //每10个元素输出一个换行
                putchar('\n');
        }
    }
    putchar('\n');
    return 0;
}
