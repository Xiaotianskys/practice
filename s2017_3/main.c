#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXN 10

int getdigit()
{
    int magic;
    //srand(time(NULL));  //������ǧ��Ҫд�ں����ã���Ȼ���������ٶ��ر���
    //��ΪֻҪ��������ͬ��ÿ����������ĵ�һ������Ȼ��ͬ�������������仰д������
    //�Ļ����Ϳ���ʹ����һ������������������һ����
    magic=rand()%100+1;
    return magic;
}

int main()
{
    int number[MAXN]={0};
    int i=0;
    srand(time(NULL));  //Ϊ����rand()�����������
    while(i<MAXN)
    {
        int num=getdigit();
        int temp=1;
        for(int j=0;j<i;j++)
        {
            if(num==number[j])
            {
                temp=0;
                break;
            }
        }
        if(temp==1)
        {
            number[i]=num;
            i++;
        }
    }
    for(i=0;i<MAXN;i++)
    {
        printf("%d ",number[i]);
    }
    return 0;
}
