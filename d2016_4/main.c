#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int A[26]={0};  //��д��ĸ������
    int a[26]={0};  //Сд��ĸ������
    int digit[10]={0};  //���ּ�����
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
    char s[100];    //����װ�����ַ��������飬�ٶ���СΪ100
    printf("�������ͳ�Ƶ��ַ�����\n");
    gets(s);
    int n=strlen(s);
    fputs(s,in);    //��������ַ���д�������ļ�
    for(i=0;i<n;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')    //��д��ĸ
            A[s[i]-65]++;       //65������'A'����
        if(s[i]>='a'&&s[i]<='z')    //Сд��ĸ
            a[s[i]-97]++;       //97������'a'����
        else if(s[i]>='0'&&s[i]<='9')   //����
            digit[s[i]-'0']++;
    }
    for(i=0;i<26;i++)    //ͳ�ƴ�Сд��ĸ�ĳ���Ƶ��
    {
        if(A[i]!=0)
        {
            printf("%c:%d\n",i+65,A[i]);
            fprintf(out,"%c:%d\n",i+65,A[i]);   //����ĸ��Ƶ��д������ļ�
        }
        if(a[i]!=0)
        {
            printf("%c:%d\n",i+97,a[i]);
            fprintf(out,"%c:%d\n",i+97,a[i]);
        }
    }
    for(i=0;i<10;i++)   //ͳ�����ֵĳ���Ƶ��
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
