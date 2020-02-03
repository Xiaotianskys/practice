#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int alphabet_to_digital(char c) //��ʮ�����Ƶ���ĸת��Ϊʮ���Ƶ�����
{
    if(c>='A'&&c<='F')
        return c-'A'+10;
    else if(c>='0'&&c<='9')
        return c-'0';
    return 0;
}

char digital_to_alphabet(int x) //��ʮ���Ƶ�����ת��Ϊʮ�����Ƶ���ĸ
{
    if(x>=10&&x<16)
        return x-10+'A';
    else if(x>=0&&x<=9)
        return x+'0';
    return 0;
}

int string_to_int(char *str,int x)  //x���Ƶ���ת��Ϊ10����
{
    int i,n=0;
    for(i=0;str[i]!='\0';i++)
    {
        n=n*x+alphabet_to_digital(str[i]);
    }
    return n;
}

//�κ�������ģ���˵��ֹ��㷨�����Դ����λ��x���Ƶļ���
char* Add_String(char *sum,char *str1,char *str2,int x)
{
    int i=strlen(str1)-1,j=strlen(str2)-1,k=0;
    int last=0;
    while(i>=0&&j>=0)   //kΪ�͵�λ��
    {
        last+=alphabet_to_digital(str1[i])+alphabet_to_digital(str2[j]);
        sum[k]=digital_to_alphabet(last%x); //��ʱsumΪ����洢
        //printf("%c",sum[k]);
        last/=x;
        i--;
        j--;
        k++;
    }
    if(j>=0)    //������������ֻ�账��i��str1
    {
        i=j;
        strcpy(str1,str2);
    }
    while(i>=0||last>0) //�����λ�������⴦��
    {
        last+=alphabet_to_digital(str1[i]);
        sum[k]=digital_to_alphabet(last%x);
        last/=x;
        //printf("i=%d,last=%d\n",i,last);
        i--;
        k++;
    }
    sum[k]='\0';
    //��sum������ת�������������м�����str1
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
    //��һ�ַ����ǰ�16���Ƶ���ת��Ϊ10���ƣ����֮����ת��Ϊ16���Ƶ��������
    //ȱ������int���ͱ�ʾ�����Ĵ�С������ʹ�ã��ܹ������λ������
    int n1=string_to_int(str1,16);
    int n2=string_to_int(str2,16);
    int sum=n1+n2;  //ʮ�������
    int i;
    for(i=0;sum!=0;i++)
    {
        strsum[i]=digital_to_alphabet(sum%16);
        sum/=16;
    }
    strsum[i]='\0';
    printf("��һ�Σ�\n");
    for(i=strlen(strsum)-1;i>=0;i--)    //�������
    {
        printf("%c",strsum[i]);
    }
    //�ڶ��β��õ���ģ������ӷ���16���Ƶļӷ������㣬���Զ��ַ�������ֱ�ӵ����㣬
    //���Դ����λ�����
    printf("\n�ڶ��Σ�\n");
    Add_String(strsum1,str1,str2,16);
    printf("%s\n",strsum1);
    return 0;
}
