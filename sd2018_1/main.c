#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i,j,sum=0,flag;
    for(i=2;i<=100;i++) //ѭ���ж�100���ڵ�����
    {
        flag=0; //����flagΪ0�����ȼٶ������һ������
        for(j=2;j<=sqrt(i);j++) //ͨ�������2��sqrt(i)�����ǿ���֪�������������ж�������
        //����ΪֻҪi�ܹ�������������2��sqrt(i)���κ�һ��������ôi�Ͳ���������
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            sum+=i;
        }
    }
    printf("%d\n",sum);
    return 0;
}
