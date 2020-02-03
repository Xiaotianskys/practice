#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int decimal(char s[])   //十六进制转十进制，用字符数组存放十六进制
{
    int n=strlen(s);
    int sum=0;  //sum初始化为0
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            s[i]=s[i]-'0';
        else if(s[i]>='A'&&s[i]<='F')
            s[i]=10+s[i]-'A';
        sum=sum+s[i]*pow(16,n-1-i); //按位乘权累加
    }
    return sum;
}

//十进制转十六进制，除基取余倒排，倒排的数放到数组里
void hex(int n)
{
    int a[50];
    int k=0;
    while(n)
    {
        a[k]=n%16;
        n=n/16;
        k++;
    }
    for(int i=k-1;i>=0;i--)
    {
        if(a[i]>=0&&a[i]<=9)
            printf("%d",a[i]);
        else
        {
            if(a[i]==10)
                printf("A");
            if(a[i]==11)
                printf("B");
            if(a[i]==12)
                printf("C");
            if(a[i]==13)
                printf("D");
            if(a[i]==14)
                printf("E");
            if(a[i]==15)
                printf("F");
        }
    }
    putchar('\n');
}

int main()
{
    printf("输入两个待求和的十六进制数：\n");
    char a[100];
    char b[100];
    gets(a);
    gets(b);
    printf("%s",a);
    printf("+");
    printf("%s",b);
    printf("=");
    int m=decimal(a);   //两个十六进制转为十进制
    int n=decimal(b);
    hex(m+n);   //将相加的结果再转化为十六进制
    system("pause");
    return 0;
}
