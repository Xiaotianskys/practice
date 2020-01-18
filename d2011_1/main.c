#include <stdio.h>
#include <stdlib.h>

int shuixianhuashu(int n)      //判断是否为水仙花数的函数，返回值为bool类型
{
    int sum=0;
    int m=n;    //保留原先的n
    int k;
    while(n)
    {
        k=n%10; //通过取余获得每一位数
        sum=sum+k*k*k;
        n=n/10; //除以10，丢弃最后一位数，则在下次取余时便能依次得到之前的数
    }
    if(sum==m)
        return 1;
    else
        return 0;
}

int main()
{
    FILE *in,*out;  //两个文件指针
    int m;
    printf("请输入要判断是否为水仙花数的数（以0结束）：\n");
    if((in=fopen("shui.in","w"))==NULL) //以写的方式打开当前目录下的shui.in文件，如果不存在shui.in则会创建该文件。
    {
        printf("file cannot open.\n");
        exit(0);
    }
    if((out=fopen("shui.out","w"))==NULL)   //以写的方式打开当前目录下的shui.out文件
    {
        printf("file cannot open.\n");
        exit(0);
    }
    while(scanf("%d",&m)!=EOF)  //当输入的数据不是文件结束标志EOF=-1；此时循环输入
    {
        fprintf(in,"%d\n",m);   //先把输入的字符写到shui.in中，无论是不是0；
        if(m==0)
            break;  //输入为0，则跳出循环
        else
        {
            if(shuixianhuashu(m))   //如果m是水仙花数
            {
                fputc('T',out);
                fputc('\n',out);
                printf("T\n");
            }
            else    //不是水仙花数时
            {
                fputc('F',out);
                fputc('\n',out);
                printf("F\n");
            }
        }
    }
    fclose(in); //关闭文件指针
    fclose(out);
    system("pause");    //防止窗口立马关闭
    return 0;
}
