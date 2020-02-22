#include <stdio.h>
#include <stdlib.h>

int gcd(int a,int b)    //求解最大公约数，递归的方法会使代码非常简单！建议采用
{
    return a%b?gcd(b,a%b):b;    //三目运算符
}

int lcm(int a,int b)    //求解最小公倍数
{
    return a*b/gcd(a,b);
}

int main()
{
    FILE *in,*out;  //in 指向输入文件，out指向输出文件
    int x,y;
    printf("请输入两个待求最大公约数和最小公倍数的整数x和y：");
    scanf("%d",&x);
    scanf("%d",&y);
    if((in=fopen("gongyueshugongbeishu.in","w"))==NULL)
    {
        printf("cannot open file.\n");
        exit(0);
    }
    if((out=fopen("gongyueshugongbeishu.out","w"))==NULL)
    {
        printf("cannot open file.\n");
        exit(0);
    }
    fprintf(in,"%d %d",x,y); //将两个数写到输入文件
    int m=gcd(x,y);
    int n=lcm(x,y);
    //将得到的结果写到输出文件
    fprintf(out,"%d和%d的最大公约数是%d，最小公倍数是%d\n",x,y,m,n);
    printf("%d和%d的最大公约数是%d\n最小公倍数是%d\n",x,y,m,n);
    fclose(in);
    fclose(out);
    system("pause");
    return 0;
}
