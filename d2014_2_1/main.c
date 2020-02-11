#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10][10];
    int i,j;
    for(i=0;i<=9;i++)   //这里创建10行杨辉三角
    {
        a[i][0]=1;  //将每行第一个元素和最后一个元素均置1
        a[i][i]=1;
    }
    for(i=2;i<=9;i++)   //从第二行开始，利用上述规律建造杨辉三角各行元素
    {
        for(j=1;j<=i-1;j++)
            a[i][j]=a[i-1][j]+a[i-1][j-1];
    }
    printf("杨辉三角：\n");
    for(i=0;i<=9;i++)   //这里没有将杨辉三角按照三角形打印
    {
        for(j=0;j<=i;j++)
        {
            printf("%5d",a[i][j]);
        }
        printf("\n");   //每输出一行之后便换行
    }
    system("pause");
    return 0;
}
