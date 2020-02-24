#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int islowercase(char ch)    //判断是否为小写字母
{
    if(ch>='a'&&ch<='z')
        return 1;
    else
        return 0;
}

int main()
{
    FILE *out;  //输出文件的文件指针
    int i;
    char s[1000];   //存储输入的字符串，假定字符串的最大长度为1000
    int len;    //存储字符串的长度
    printf("请输入待转换的字符串：");
    scanf("%s",s);
    len=strlen(s);
    if((out=fopen("E:\\test.txt","w"))==NULL)
    /*以写的方式打开E:\test.txt文件，注意windows下的路径，这里是两个\\而不是一个\，
    因为在windows下的符号\是作为转义字符出现的，本来windows下的文件路径只有一个\，
    但是当在程序中以字符串的形式输入文件路径时，\被当做转义字符，所以需要加两个斜杆\\
    */
    {
        printf("file cannot open\n");
        system("pause");
        exit(0);
    }
    for(i=0;i<len;i++)
    {
        if(islowercase(s[i]))   //如果是小写字母的话，就将其转为对应的大写字母
        {
            s[i]=s[i]-32;
        }
    }
    fprintf(out,"%s\n",s);  //将转换后的字符串写到对应文件
    printf("转换后的字符串是：%s\n",s);
    system("pause");
    return 0;
}
