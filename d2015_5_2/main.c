#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mi2(int n)  //�ж��Ƿ�Ϊ2����
{
    if(n<1) //С��1��Ȼ����2����
        return 0;
    else
    {
        if((n&(n-1))==0)  //n��n-1�Ķ����ƽ��а�λ��Ϊ0ʱ������2����
            return 1;
        else
            return 0;
    }
}

int main()
{
    int i;
    int j=0;    //��������
    int k=pow(2,sizeof(int)*8-2);
    for(i=1;i<=k;i=i*2)
        if(mi2(i))
        {
            printf("%10d\t",i);
            j++;
            if(j%5==0)
                putchar('\n');  //ÿ10�����һ��
        }
    return 0;
}
