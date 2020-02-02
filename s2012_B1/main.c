#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* Divide(char *c,int x) //此处就是模拟我们手算的除法
{
    int reminder=0;
    int i;
    for(i=0;c[i]!='\0';i++)
    {
        int cur=reminder*10+c[i]-'0';   //这里是要提出数来进行计算所以千万不要忘记-'0'
        c[i]=cur/x+'0'; //这里是要重新存入字符数组中所以不要忘记+'0'
        reminder=cur%x;
    }
    for(i=0;c[i]=='0';i++); //跳过前面的'0'
    strcpy(c,&c[i]);    //略去前面的'0'
    /*
    char abc[100];
    int j;
    for(j=0;c[i]!='\0';j++,i++)
    {
        abc[j]=c[i];
    }
    abc[j]='\0';    //这里千万必要return abc;因为abc是函数里面的变量
                    //，当退出函数后，内存空间返回后即为乱码
    char *p=abc;
    printf("%s\n",p);
    return p;   //这里返回p又没有问题，具体原因未知
    */
    //printf("%s\n",c);
    return c;
}
int main()
{
    char str[100];
    printf("请输入十进制数字，不要超过100位:\n");
    scanf("%s",str);
    int i;
    char out[300];
    for(i=0;strlen(str)!=0;i++) //这里i实际上就是二进制的位数
    //为什么这里中间不写为strcmp(str,"0")!=0,是因为Divide函数不允许有"0\0"这样的字符串出现，
    //因为它总要将前缀"0"给跳过，因而最后只剩下"\0",故只能用strlen(str)!=0
    {
        out[i]=(str[strlen(str)-1]-'0')%2+'0';  //求余
        strcpy(str,Divide(str,2));  //相除
    }
    out[i]='\0';    //末尾补'\0'，形成字符串
    printf("对应的二进制数为：\n");
    for(int i=strlen(out)-1;i>=0;i--)   //这里需要倒过来输出
    {
        printf("%c",out[i]);
    }
    printf("\n");
    return 0;
}
