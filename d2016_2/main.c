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
    printf("������һ�����ж��Ƿ�Ϊˮ�ɻ�����3λ����n��");
    scanf("%d",&n);
    if(shuixianhuashu(n))
        printf("%d��ˮ�ɻ���\n",n);
    else
        printf("%d����ˮ�ɻ���\n",n);
    system("pause");
    return 0;
}
