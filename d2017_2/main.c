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
    printf("%5d\n",1);  //先输出第一行
    for(i=0;i<8;i++)
    {
        printf("  ");
    }
    printf("%5d%5d\n",a[0],a[1]);   //再输出第二行
    for(i=2;i<10;i++)   //2-9行
    {
        a[0]=a[i]=1;    //每行的第一个元素和最后一个元素均为1
        for(j=i-1;j>0;j--)
            a[j]=a[j-1]+a[j];   //从后往前计算每行中的元素
        for(k=0;k<9-i;k++)
            printf("  ");       //控制输出每行前面的空格
        for(j=0;j<=i;j++)
            printf("%5d",a[j]); //再输出每行元素
        putchar('\n');
    }
    system("pause");
    return 0;
}
