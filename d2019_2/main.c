#include <stdio.h>

//nΪ��Ҫ�ƶ������ӵĸ�����a,b,c����3�����ӵ����ƣ���char����ʾ
void hanio(int n,char a,char b,char c)
{
    if(n==1)
    {
        printf("%c->%c\n",a,c); //���ֻ��һ�����ӣ���ֱ�Ӵ���a�ƶ�����c
    }
    else
    {
        hanio(n-1,a,c,b);   //����ݹ���ã���c��Ϊ�н飬�Ƚ�n-1�����ӵݹ����a�ƶ�����b
        printf("%c->%c\n",a,c); //Ȼ����a��ʣ�µ�һ������ֱ���ƶ�����c
        hanio(n-1,b,a,c);   //�����a��Ϊ�н飬��n-1�����ӵݹ�Ĵ���b�ƶ���c
    }
}

int main()
{
    int n;
    printf("������Ҫ�ƶ��Ŀ�����");
    scanf("%d",&n);
    hanio(n,'A','B','C');
    return 0;
}
