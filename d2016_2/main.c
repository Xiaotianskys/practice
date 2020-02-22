#include <stdio.h>
#include <stdlib.h>

int shuixianhuashu(int n)
{
    int k;
    int m=n,sum=0;
    while(n)
    {
        k=n%10;
        sum=sum+k*k*k;
        n=n/10;
    }
    if(sum==m)
        return 1;
    else
        return 0;
}

int main()
{
    int n;
    printf("请输入一个待判断是否为水仙花数的3位整数n：");
    scanf("%d",&n);
    if(shuixianhuashu(n))
        printf("%d是水仙花数\n",n);
    else
        printf("%d不是水仙花数\n",n);
    system("pause");
    return 0;
}
