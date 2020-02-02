#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,i;  //要转化为二进制的十进制数
    int binary[100];    //这个数组用于存放除基取余正排得到的数
    int k=0;    //为了知道二进制数有多少位，用k来计数
    printf("请输入一个待转化为二进制的十进制数：");
    scanf("%d",&n);
    m=n;
    while(n!=0) //用于计算二进制的方法来模拟
    {
        binary[k]=n%2;
        n=n/2;
        k++;    //k实际便是二进制的位数
    }
    printf("十进制数%d对应的二进制数是：",m);
    for(i=k-1;i>=0;i--)
        printf("%d",binary[i]); //输出十进制对应的二进制数
    putchar('\n');
    system("pause");
    return 0;
}
