#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10][10];
    int i,j;
    for(i=0;i<=9;i++)   //���ﴴ��10���������
    {
        a[i][0]=1;  //��ÿ�е�һ��Ԫ�غ����һ��Ԫ�ؾ���1
        a[i][i]=1;
    }
    for(i=2;i<=9;i++)   //�ӵڶ��п�ʼ�������������ɽ���������Ǹ���Ԫ��
    {
        for(j=1;j<=i-1;j++)
            a[i][j]=a[i-1][j]+a[i-1][j-1];
    }
    printf("������ǣ�\n");
    for(i=0;i<=9;i++)   //����û�н�������ǰ��������δ�ӡ
    {
        for(j=0;j<=i;j++)
        {
            printf("%5d",a[i][j]);
        }
        printf("\n");   //ÿ���һ��֮��㻻��
    }
    system("pause");
    return 0;
}
