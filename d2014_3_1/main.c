#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s1[100],s2[100];   //存放两个百位数字的字符数组
    int s[101]={0}; //存放最后相加结果的整型数组，一开始全都是0
    int l1,l2,i,j,k=0;
    printf("请输入两个待相加的大整数s1,s2：\n");
    gets(s1);
    gets(s2);
    l1=strlen(s1);
    l2=strlen(s2);
    for(i=l1-1,j=l2-1;i>=0&&j>=0;i--,j--)
    {
        s[k]=s[k]+s1[i]-'0'+s2[j]-'0';
        if(s[k]>=10)    //大于10要进位
        {
            s[k]=s[k]-10;
            s[k+1]++;   //进位，直接进位的1放到k+1的位置，那么接下来在算s[k+1]的时候自然
            //就加上了这个进位（s[k+1]=s[k+1]+s[i]-'0'+s2[j]-'0'
        }
        k++;
    }
    if(i>=0)    //如果i的高位没有加完
    {
        for(;i>=0;i--)  //则将i对应的数字字符串的高位加上去
        {
            s[k]=s[k]+s1[i]-'0';
            if(s[k]>=10)    //要进位
            {
                s[k]=s[k]-10;
                s[k+1]++;   //进位
            }
            k++;
        }
    }
    if(j>=0)    //同理，如果j的高位没有加完
    {
        for(;j>=0;j--)  //则将j对应的数字字符串的高位加上去
        {
            s[k]=s[k]+s2[j]-'0';
            if(s[k]>=10)    //要进位
            {
                s[k]=s[k]-10;
                s[k+1]++;   //进位
            }
            k++;
        }
    }
    if(s[k])    //当最高位有进位1时，在输出的时候应将这个进位的1输出
    {
        for(i=k;i>=0;i--)   //逆序输出
        {
            printf("%d",s[i]);
        }
        putchar('\n');
    }
    else    //当最高位无进位时
    {
        for(i=k-1;i>=0;i--) //逆序输出
        {
            printf("%d",s[i]);
        }
        putchar('\n');
    }
    system("pause");
    return 0;
}
