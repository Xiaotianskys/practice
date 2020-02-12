#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void jianfa(char s1[], char s2[], int a[]) //这里默认是s1比s2要大的，如果小的话，则
//只需在主函数交换位置，最后加上-负号即可。可以考虑自己写一个大数-小数来模拟
{
    int l1=strlen(s1);
    int l2=strlen(s2);
    int k=0;    //k是a数组的下标，a数组用来存放减法得到的结果
    int i,j;
    for(i=l1-1,j=l2-1;i>=0&&j>=0;i--,j--)
    {
        if(s1[i]>=s2[j])
            a[k]=s1[i]-s2[j];
        else if(s1[i]<s2[j])
        {
            a[k]=10+s1[i]-s2[j];
            s1[i-1]--;  //向高位借位
        }
        k++;
    }
    if(i>=0)    //如果此时s1还没有减完（也只有可能s1没减完，因为这里假设的是s1比s2大）
    {
        for(;i>=0;i--)
        {
            if(s1[i]>='0')
                a[k]=s1[i]-'0';
            else if(s1[i]<'0')  //因为有可能s1[i]由于借位变成了-1，此时是小于0的，
            //得向高位借位
            {
                a[k]=10+s1[i]-'0';
                s1[i-1]--;
            }
            k++;
        }
    }
    for(i=k-1;i>=0;i--) //由于减法之后高位可能会变成0，因此我们得先找到第一个不是0的
    //位置，再输出
    {
        if(a[i]!=0) //a中放的是int，直接与0比较即可，不用与'0'比较
            break;
    }
    for(;i>=0;i--)  //输出结果
    {
        printf("%d",a[i]);
    }
}

int main()
{
    char s1[100];
    char s2[100];
    int a[100];
    printf("请输入两个待相减的大数s1,s2：\n");
    gets(s1);
    gets(s2);
    int l1=strlen(s1);
    int l2=strlen(s2);  //通过字符数组的长度首先判断s1，s2哪个数大一点
    if(l1>l2)   //此时s1必定比s2大
    {
        jianfa(s1,s2,a);    //调用函数jianfa(……)
    }
    else if(l1<l2)  //此时s1比s2小，可以先输出负号，再交换并做减法
    {
        putchar('-');
        jianfa(s2,s1,a);
    }
    else if(l1==l2) //长度相等时还无法判断谁大谁小，可以考虑用strcmp函数
    {
        if(strcmp(s1,s2)>0) //s1>s2时
        {
            jianfa(s1,s2,a);
        }
        else if(strcmp(s1,s2)<0)    //s1<s2时
        {
            putchar('-');
            jianfa(s2,s1,a);
        }
        else if(strcmp(s1,s2)==0)
        {
            printf("0");
        }
    }
    putchar('\n');
    system("pause");
    return 0;
}
