#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10]={1,1};
    int i,j,k;
    for(i=0;i<9;i++)
    {
        printf("  ");
    }
    printf("%5d\n",1);  //�������һ��
    for(i=0;i<8;i++)
    {
        printf("  ");
    }
    printf("%5d%5d\n",a[0],a[1]);   //������ڶ���
    for(i=2;i<10;i++)   //2-9��
    {
        a[0]=a[i]=1;    //ÿ�еĵ�һ��Ԫ�غ����һ��Ԫ�ؾ�Ϊ1
        for(j=i-1;j>0;j--)
            a[j]=a[j-1]+a[j];   //�Ӻ���ǰ����ÿ���е�Ԫ��
        for(k=0;k<9-i;k++)
            printf("  ");       //�������ÿ��ǰ��Ŀո�
        for(j=0;j<=i;j++)
            printf("%5d",a[j]); //�����ÿ��Ԫ��
        putchar('\n');
    }
    system("pause");
    return 0;
}
