#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fama[6]={1,2,3,5,10,20};    //������������
    int num[6]={5,3,2,2,1,1};   //������������
    int flag[100]={0};  //������飬һ��ʼȫΪ0
    int i,j;
    int tempweight; //������ÿ�������ܳƳ������������ÿ���ۼӣ�
    //���Ǵ�0��ʼ����ǰ�������
    int newweight;  //��������õ���������
    int maxweight=0;    //��������������ܳƵõ����������
    int currentweight;  //Ŀǰ�ܳ��ص���������һ���ж�ָ��
    for(i=0;i<6;i++)
        maxweight=maxweight+fama[i]*num[i];
    for(i=0;i<=num[0];i++)  //�����ȼ����0�������ܳƳ�������
        flag[fama[0]*i]=1;  //���ܳƳ������ı�־����Ķ�Ӧλ��Ϊ1
    tempweight=fama[0]*num[0];  //���ǵ�0�������ܳƳ�������������ں�
    //��ļ����У�����0-tempweight֮���Ѿ����Գ��ص����ۼ��Ϻ������������
    //���õ��µ��ܹ���ȡ����������̬�滮�ĺ��ģ���ǰһ���������һ������
    i=1;    //׼�������1-5�������ܳƵ��������ڵ�0�������ܳ�ȡ�Ļ����Ͻ��м��㣩
    while(i<6)  //�ܹ���5�����룬����ѭ��5�Σ������Ѿ�����õĵ�0�����룩
    {
        for(j=1;j<=num[i];j++)  //��1�����룬��ǰ���Ѿ�������Գ��ص�������
        //�Ӻ�������������
            for(currentweight=0;currentweight<=tempweight;currentweight++)
            //��0��ʼ����ǰ����Ѿ��ܳ��ص�������������������
            {
                newweight=currentweight+j*fama[i];
                if(flag[currentweight]==1&&flag[newweight]==0)
                    flag[newweight]=1;  //���currentweight�ܳ��أ�����
                //newweight��û���ܳƵĻ���������������������Գ���
            }
        tempweight=tempweight+fama[i]*num[i];   //�޸ĵ�ǰ�ܳ��ص����
        //ֵ���Ա�����ܹ���0-tempweight�ۼ�
        i++;    //������һ������
    }
    int count=0;
    for(i=0;i<=maxweight;i++)
    {
        if(flag[i]==1)  //����ܳ��أ���Ӧ��־λΪ1��
        {
            count++;
            printf("%d\t",i);
            if(count%10==0) //ÿ10������
                putchar('\n');
        }
    }
    printf("\n���ϣ��ܹ��ܳƳ�%d",count);
    system("pause");
    return 0;
}
