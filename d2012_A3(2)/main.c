#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int danci(char c)   //�ж��Ƿ�Ϊ���ʵĺ���
{
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
        return 1;
    else
        return 0;
}

int main()
{
    char s[100][100];   //����װ���ʣ���ά�ַ���������װ�õ��ĵ��ʣ���ȫ���ÿ�
    for(int i=0;i<100;i++)
        s[i][0]='\0';   //��ȫ���ÿ�
    char str[300];  //��������ַ���
    char temp[30]; //������ʱװ����
    int count[100]={0}; //�����ʼ�����������
    int k=0;
    int j;
    printf("������һ�����жϵ��ʵ��ַ�����\n");
    gets(str);
    for(int i=0;i<=strlen(str);i++)
    {
        if(danci(str[i]))   //��ǰһ���ַ��ǵ���
        {
            if(i-1<0||!danci(str[i-1])) //�����ǰ�ǵ�һ�����ʣ���������ǰ�治��
            //���ʣ���֤���µĵ��ʿ�ʼ��,���԰����浽temp��
            {
                j=0;
                temp[j]=str[i];
                j++;
            }
            else
                temp[j++]=str[i];
        }
        else if(i-1>=0&&danci(str[i-1]))    //��ǰ�ַ����ǵ��ʣ�����ǰһ�ַ��ǵ��ʣ���֤�����ʽ�����
        {
            temp[j]='\0';   //���ʽ����������ַ���������־���ڿ�����ǰ��ĵ������Ƚϣ����Ƿ��е��ʳ���
            int m;
            for(m=0;m<k;m++)
                if(strcmp(s[m],temp)==0)    //��ѭ����ǰ��Ƚ�
                {
                    count[m]++;
                    break;
                }   //ǰ���������ȵģ���m��С��k�ģ�����ѭ����ϣ�ǰ�涼û����ȵģ�����m=k
            if(m==k)    //m==k����ǰ��û����ȵ�
            {
                strcpy(s[k],temp);
                count[k]++;
                k++;
            }
        }
    }
    for(int i=0;i<k;i++)
        printf("����%s�����ִ�����%d\n",s[i],count[i]);
    return 0;
}
