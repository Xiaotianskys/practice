#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int islowercase(char ch)    //�ж��Ƿ�ΪСд��ĸ
{
    if(ch>='a'&&ch<='z')
        return 1;
    else
        return 0;
}

int main()
{
    FILE *out;  //����ļ����ļ�ָ��
    int i;
    char s[1000];   //�洢������ַ������ٶ��ַ�������󳤶�Ϊ1000
    int len;    //�洢�ַ����ĳ���
    printf("�������ת�����ַ�����");
    scanf("%s",s);
    len=strlen(s);
    if((out=fopen("E:\\test.txt","w"))==NULL)
    /*��д�ķ�ʽ��E:\test.txt�ļ���ע��windows�µ�·��������������\\������һ��\��
    ��Ϊ��windows�µķ���\����Ϊת���ַ����ֵģ�����windows�µ��ļ�·��ֻ��һ��\��
    ���ǵ��ڳ��������ַ�������ʽ�����ļ�·��ʱ��\������ת���ַ���������Ҫ������б��\\
    */
    {
        printf("file cannot open\n");
        system("pause");
        exit(0);
    }
    for(i=0;i<len;i++)
    {
        if(islowercase(s[i]))   //�����Сд��ĸ�Ļ����ͽ���תΪ��Ӧ�Ĵ�д��ĸ
        {
            s[i]=s[i]-32;
        }
    }
    fprintf(out,"%s\n",s);  //��ת������ַ���д����Ӧ�ļ�
    printf("ת������ַ����ǣ�%s\n",s);
    system("pause");
    return 0;
}
