#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(char *s1,char *s2)  //�Զ���ıȽϺ���
{
    int l1=strlen(s1);
    int l2=strlen(s2);
    int i,j;
    int m=0,n=0;
    for(i=0;i<l1;i++)   //��l1��'0'�ĸ���
        if(s1[i]=='0')
            m++;
    for(j=0;j<l2;j++)   //��l2��'0'�ĸ���
        if(s2[j]=='0')
            n++;
    if(l1>l2)   //������ĿҪ��ıȽϹ���õ��������ַ��ط�ʽ
        return 1;
    else if((l1==l2)&&m<n)
        return 1;
    else
        return 0;
}

int main()  //������
{
    int n;
    printf("�������ַ����ĸ���n��");
    scanf("%d",&n); //���Կ��Ƕ���n��Ԫ�ص�ָ�����飬ָ�������е�ÿ��ָ��ָ��һ���ַ�����
    //��̬����ָ�����飬�ÿ�����ָ��ָ���ָ��
    char **s=(char**)calloc(n,sizeof(char*));   //����ָ��ָ��������׵�ַ����̬����
    int i,j,k;
    for(i=0;i<n;i++)    //�����ַ�ָ�������е�Ԫ��û��ָ��ȷ���Ĵ洢��Ԫ���޷�����
    //�ַ�����Ӧ��Ϊ��Щ�ַ�ָ���ٷ���洢��Ԫ��
        s[i]=(char*)calloc(100,sizeof(char));   //�ٶ��ַ����ĳ������Ϊ100
    for(i=0;i<n;i++)
        scanf("%s",s[i]);
    char *temp=(char*)calloc(100,sizeof(char)); //���ڽ��������õ���ʱ�ռ�
    for(i=0;i<n-1;i++)  //������ѡ�����򣬸������򷽷����Լ��ú�����
    {
        k=i;
        for(j=i+1;j<n;j++)
            if(compare(s[k],s[j]))
                k=j;
        if(k!=i)    //����������С�Ĳ���i��Ӧ���ַ���������н���
        {
            strcpy(temp,s[i]);
            strcpy(s[i],s[k]);
            strcpy(s[k],temp);
        }
    }
    printf("����Ľ��������ʾ��\n");
    for(i=0;i<n;i++)    //����������ַ���
    {
        printf("%s\n",s[i]);
        free(s[i]);
    }
    free(*s);
    free(temp);
    system("pause");
    return 0;
}
