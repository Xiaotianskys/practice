#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10][10],i,j,k;
    for(i=0;i<10;i++)
    {
        a[i][0]=1;
        a[i][i]=1;
    }
    for(i=2;i<10;i++)
        for(j=1;j<i;j++)
            a[i][j]=a[i-1][j-1]+a[i-1][j]; //����������ǵ�Ԫ��
    for(i=0;i<10;i++)
    {
        for(k=0;k<9-i;k++)  //��ӡ�ո�����������״Ϊ�����ε��������
            printf("  ");
        for(j=0;j<=i;j++)
            printf("%5d",a[i][j]);
        printf("\n");
    }
    system("pause");
    return 0;
}
