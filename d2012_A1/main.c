#include <stdio.h>
#include <math.h>

int sushu(int n) //判断一个数n是否为素数的函数，其返回值为bool布尔类型
{
    int i;
    int k=sqrt(n);  //对n进行开方
    for(i=2;i<=k;i++)
    {
        if(n%i==0)  //如果n能够整除i，表明n除了1和它自身之外，还有其他的因数，表明其不是素数，直接跳出循环
            break;
    }
    if(i>k)     //如果n是素数，则不会跳出循环，最后会有i>k，表明是素数
        return 1;
    else
        return 0;   //否则表明不是素数（因为跳出循环了，导致 i并没有增加到大于k就停止了）
}

int huiwenshu(int n)   //判断是否为回文数的典型方法（取余10得到最后一位数，除以10消除最后一位数）
{
    int sum=0,m=n;
    while(n)
    {
        sum=sum*10+n%10;    //n%10得到对应数的最后一位
        n=n/10;     //n除以10，能够消除最后一位
    }
    if(sum==m)
        return 1;
    else
        return 0;
}

int main()
{
    int n;
    for(n=2;n<10000;n++)    //判断2-9999中满足既是素数，又是回文数的数
        if(sushu(n)&&huiwenshu(n))
            printf("%d既是素数，又是一个对称的数\n",n);
    return 0;
}
