#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int decimal(char s[])   //ʮ������תʮ���ƣ����ַ�������ʮ������
{
    int n=strlen(s);
    int sum=0;  //sum��ʼ��Ϊ0
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            s[i]=s[i]-'0';
        else if(s[i]>='A'&&s[i]<='F')
            s[i]=10+s[i]-'A';
        sum=sum+s[i]*pow(16,n-1-i); //��λ��Ȩ�ۼ�
    }
    return sum;
}

//ʮ����תʮ�����ƣ�����ȡ�൹�ţ����ŵ����ŵ�������
void hex(int n)
{
    int a[50];
    int k=0;
    while(n)
    {
        a[k]=n%16;
        n=n/16;
        k++;
    }
    for(int i=k-1;i>=0;i--)
    {
        if(a[i]>=0&&a[i]<=9)
            printf("%d",a[i]);
        else
        {
            if(a[i]==10)
                printf("A");
            if(a[i]==11)
                printf("B");
            if(a[i]==12)
                printf("C");
            if(a[i]==13)
                printf("D");
            if(a[i]==14)
                printf("E");
            if(a[i]==15)
                printf("F");
        }
    }
    putchar('\n');
}

int main()
{
    printf("������������͵�ʮ����������\n");
    char a[100];
    char b[100];
    gets(a);
    gets(b);
    printf("%s",a);
    printf("+");
    printf("%s",b);
    printf("=");
    int m=decimal(a);   //����ʮ������תΪʮ����
    int n=decimal(b);
    hex(m+n);   //����ӵĽ����ת��Ϊʮ������
    system("pause");
    return 0;
}
