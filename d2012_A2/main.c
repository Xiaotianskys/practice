#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    printf("������һ������ʽ�ֽ������n��");
    scanf("%d",&n);
    printf("%d=",n);
    for(i=2;i<=n;i++)
    {
        while(i<=n) //��û�г�����ʱ��ѭ����֤���������д��ֽ�
        {
            if(n%i==0)  //����ܳ����Ļ�
            {
                printf("%d",i);     //�����ʽ�ֽ��һ����
                if(n!=i)
                {
                    printf("*");    //�����һ������֮�󣬲�����Ҫ*���ˣ��������һ�������*��
                }
                n=n/i;              //�ܳ��������n�ֽ⣬���n/i;
            }
            else
                break;      //���򣬵��޷�����ʱ������i+1�������forѭ����������
        }
    }
    putchar('\n');    //���һ�����з�
    system("pause");
    return 0;
}
