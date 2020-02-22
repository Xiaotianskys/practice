#include <stdio.h>
#include <stdlib.h>

int zuidagongyueshu(int x,int y)    //辗转相除法求最大公约数的函数
{
    int temp;
    if(x<y) //使x是x,y中较大的数，然后再辗转相除
    {
        temp=x;
        x=y;
        y=temp;
    }
    while(y)
    {
        temp=x%y;   //辗转相除并取余
        x=y;
        y=temp;     //y为每次的余数
    }
    return x;
}

int zuixiaogongbeishu(int x,int y)  //求解最小公倍数的函数
{
    return x*y/zuidagongyueshu(x,y);
}

int main()
{
    FILE *in,*out;  //in指向输入文件，out指向输出文件
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
    fprintf(in,"%d %d",x,y);    //将两个数写到输入文件
    int m=zuidagongyueshu(x,y);
    int n=zuixiaogongbeishu(x,y);
    //将得到的结果写到输出文件
    fprintf(out,"%d和%d的最大公约数是%d,最小公倍数是%d\n",x,y,m,n);
    printf("%d和%d的最大公约数是%d\n最小公倍数为是%d\n",x,y,m,n);
    fclose(in);
    fclose(out);
    system("pause");
    return 0;
}
