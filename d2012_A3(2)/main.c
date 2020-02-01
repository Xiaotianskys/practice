#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int danci(char c)   //判断是否为单词的函数
{
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
        return 1;
    else
        return 0;
}

int main()
{
    char s[100][100];   //用来装单词，二维字符数组用来装拿到的单词，先全部置空
    for(int i=0;i<100;i++)
        s[i][0]='\0';   //先全部置空
    char str[300];  //先输入的字符串
    char temp[30]; //用来临时装单词
    int count[100]={0}; //给单词计数，计数器
    int k=0;
    int j;
    printf("请输入一个待判断单词的字符串：\n");
    gets(str);
    for(int i=0;i<=strlen(str);i++)
    {
        if(danci(str[i]))   //当前一个字符是单词
        {
            if(i-1<0||!danci(str[i-1])) //如果当前是第一个单词，或者他的前面不是
            //单词，则证明新的单词开始了,可以把它存到temp中
            {
                j=0;
                temp[j]=str[i];
                j++;
            }
            else
                temp[j++]=str[i];
        }
        else if(i-1>=0&&danci(str[i-1]))    //当前字符不是单词，但是前一字符是单词，则证明单词结束了
        {
            temp[j]='\0';   //单词结束，加上字符串结束标志，在考虑与前面的单词作比较，看是否有单词出现
            int m;
            for(m=0;m<k;m++)
                if(strcmp(s[m],temp)==0)    //先循环跟前面比较
                {
                    count[m]++;
                    break;
                }   //前面如果有相等的，则m必小于k的，否则循环完毕，前面都没有相等的，则有m=k
            if(m==k)    //m==k表明前面没有相等的
            {
                strcpy(s[k],temp);
                count[k]++;
                k++;
            }
        }
    }
    for(int i=0;i<k;i++)
        printf("单词%s，出现次数：%d\n",s[i],count[i]);
    return 0;
}
