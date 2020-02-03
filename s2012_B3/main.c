#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int alphabet_to_digital(char c) //把十六进制的字母转化为十进制的数字
{
    if(c>='A'&&c<='F')
        return c-'A'+10;
    else if(c>='0'&&c<='9')
        return c-'0';
    return 0;
}

char digital_to_alphabet(int x) //把十进制的数字转化为十六进制的字母
{
    if(x>=10&&x<16)
        return x-10+'A';
    else if(x>=0&&x<=9)
        return x+'0';
    return 0;
}

int string_to_int(char *str,int x)  //x进制的数转化为10进制
{
    int i,n=0;
    for(i=0;str[i]!='\0';i++)
    {
        n=n*x+alphabet_to_digital(str[i]);
    }
    return n;
}

//次函数用于模拟人的手工算法，可以处理大位数x进制的加数
char* Add_String(char *sum,char *str1,char *str2,int x)
{
    int i=strlen(str1)-1,j=strlen(str2)-1,k=0;
    int last=0;
    while(i>=0&&j>=0)   //k为和的位数
    {
        last+=alphabet_to_digital(str1[i])+alphabet_to_digital(str2[j]);
        sum[k]=digital_to_alphabet(last%x); //此时sum为逆序存储
        //printf("%c",sum[k]);
        last/=x;
        i--;
        j--;
        k++;
    }
    if(j>=0)    //经过这样处理，只需处理i和str1
    {
        i=j;
        strcpy(str1,str2);
    }
    while(i>=0||last>0) //多余的位数需另外处理
    {
        last+=alphabet_to_digital(str1[i]);
        sum[k]=digital_to_alphabet(last%x);
        last/=x;
        //printf("i=%d,last=%d\n",i,last);
        i--;
        k++;
    }
    sum[k]='\0';
    //将sum的逆序反转过来，借助于中间载体str1
    strcpy(str1,sum);
    for(i=0;i<strlen(str1);i++)
    {
        sum[i]=str1[strlen(str1)-1-i];
    }
    sum[strlen(str1)]='\0';
    return sum;
}

int main()
{
    char str1[100],str2[100],strsum[100],strsum1[100];
    scanf("%s",str1);
    scanf("%s",str2);
    //第一种方法是把16进制的数转化为10进制，相加之后再转化为16进制的数输出，
    //缺点是受int类型表示的数的大小的限制使得，能够计算的位数有限
    int n1=string_to_int(str1,16);
    int n2=string_to_int(str2,16);
    int sum=n1+n2;  //十进制相加
    int i;
    for(i=0;sum!=0;i++)
    {
        strsum[i]=digital_to_alphabet(sum%16);
        sum/=16;
    }
    strsum[i]='\0';
    printf("第一次：\n");
    for(i=strlen(strsum)-1;i>=0;i--)    //倒序输出
    {
        printf("%c",strsum[i]);
    }
    //第二次采用的是模拟手算加法的16进制的加法的运算，可以对字符串进行直接的运算，
    //可以处理多位的情况
    printf("\n第二次：\n");
    Add_String(strsum1,str1,str2,16);
    printf("%s\n",strsum1);
    return 0;
}
