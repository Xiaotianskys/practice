#include <stdio.h>
#include <stdlib.h>

int gcd(int a,int b)    //������Լ�����ݹ�ķ�����ʹ����ǳ��򵥣��������
{
    return a%b?gcd(b,a%b):b;    //��Ŀ�����
}

int lcm(int a,int b)    //�����С������
{
    return a*b/gcd(a,b);
}

int main()
{
    FILE *in,*out;  //in ָ�������ļ���outָ������ļ�
    int x,y;
    printf("�����������������Լ������С������������x��y��");
    scanf("%d",&x);
    scanf("%d",&y);
    if((in=fopen("gongyueshugongbeishu.in","w"))==NULL)
    {
        printf("cannot open file.\n");
        exit(0);
    }
    if((out=fopen("gongyueshugongbeishu.out","w"))==NULL)
    {
        printf("cannot open file.\n");
        exit(0);
    }
    fprintf(in,"%d %d",x,y); //��������д�������ļ�
    int m=gcd(x,y);
    int n=lcm(x,y);
    //���õ��Ľ��д������ļ�
    fprintf(out,"%d��%d�����Լ����%d����С��������%d\n",x,y,m,n);
    printf("%d��%d�����Լ����%d\n��С��������%d\n",x,y,m,n);
    fclose(in);
    fclose(out);
    system("pause");
    return 0;
}
