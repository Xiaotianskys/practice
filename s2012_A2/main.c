#include <stdio.h>
#include <stdlib.h>
/*
�㷨˼�룺
��n���зֽ���������Ӧ���ҵ�һ����С������k��Ȼ������������ɣ�
��1������������ǡ����n����˵���ֽ��������Ĺ����Ѿ���������ӡ������
��2�����n>k����n�ܱ�k��������Ӧ��ӡ��k��ֵ������n����k���̣���Ϊ�µ�������n��
     �ظ�ִ�е�һ����
��3�����n���ܱ�k����������k+1��Ϊk��ֵ���ظ�ִ�е�һ����
*/
int main()
{
    int n,i;
    printf("Please input a number.\n");
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        while(n!=i)
        {
            if(n%i==0)
            {
                printf("%d*",i);
                n=n/i;
            }
            else
                break;
        }
    }
    printf("%d",n);
    return 0;
}
