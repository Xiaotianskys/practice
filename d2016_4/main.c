#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int A[26]={0};  //大写字母计数器
    int a[26]={0};  //小写字母计数器
    int digit[10]={0};  //数字计数器
    int i;
    FILE *in,*out;
    if((in=fopen("shuru.in","w"))==NULL)
    {
        printf("file cannot open.\n");
        exit(0);
    }
    if((out=fopen("shuru.out","w"))==NULL)
    {
        printf("file cannot open.\n");
        exit(0);
    }
    char s[100];    //用来装输入字符串的数组，假定大小为100
    printf("请输入待统计的字符串：\n");
    gets(s);
    int n=strlen(s);
    fputs(s,in);    //将输入的字符串写到输入文件
    for(i=0;i<n;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')    //大写字母
            A[s[i]-65]++;       //65可以用'A'代替
        if(s[i]>='a'&&s[i]<='z')    //小写字母
            a[s[i]-97]++;       //97可以用'a'代替
        else if(s[i]>='0'&&s[i]<='9')   //数字
            digit[s[i]-'0']++;
    }
    for(i=0;i<26;i++)    //统计大小写字母的出现频率
    {
        if(A[i]!=0)
        {
            printf("%c:%d\n",i+65,A[i]);
            fprintf(out,"%c:%d\n",i+65,A[i]);   //将字母及频率写到输出文件
        }
        if(a[i]!=0)
        {
            printf("%c:%d\n",i+97,a[i]);
            fprintf(out,"%c:%d\n",i+97,a[i]);
        }
    }
    for(i=0;i<10;i++)   //统计数字的出现频率
    {
        if(digit[i]!=0)
        {
            printf("%c:%d\n",i+'0',digit[i]);
            fprintf(out,"%c:%d\n",i+'0',digit[i]);
        }
    }
    fclose(in);
    fclose(out);
    system("pause");
    return 0;
}
