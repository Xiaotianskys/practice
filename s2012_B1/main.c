#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* Divide(char *c,int x) //�˴�����ģ����������ĳ���
{
    int reminder=0;
    int i;
    for(i=0;c[i]!='\0';i++)
    {
        int cur=reminder*10+c[i]-'0';   //������Ҫ����������м�������ǧ��Ҫ����-'0'
        c[i]=cur/x+'0'; //������Ҫ���´����ַ����������Բ�Ҫ����+'0'
        reminder=cur%x;
    }
    for(i=0;c[i]=='0';i++); //����ǰ���'0'
    strcpy(c,&c[i]);    //��ȥǰ���'0'
    /*
    char abc[100];
    int j;
    for(j=0;c[i]!='\0';j++,i++)
    {
        abc[j]=c[i];
    }
    abc[j]='\0';    //����ǧ���Ҫreturn abc;��Ϊabc�Ǻ�������ı���
                    //�����˳��������ڴ�ռ䷵�غ�Ϊ����
    char *p=abc;
    printf("%s\n",p);
    return p;   //���ﷵ��p��û�����⣬����ԭ��δ֪
    */
    //printf("%s\n",c);
    return c;
}
int main()
{
    char str[100];
    printf("������ʮ�������֣���Ҫ����100λ:\n");
    scanf("%s",str);
    int i;
    char out[300];
    for(i=0;strlen(str)!=0;i++) //����iʵ���Ͼ��Ƕ����Ƶ�λ��
    //Ϊʲô�����м䲻дΪstrcmp(str,"0")!=0,����ΪDivide������������"0\0"�������ַ������֣�
    //��Ϊ����Ҫ��ǰ׺"0"��������������ֻʣ��"\0",��ֻ����strlen(str)!=0
    {
        out[i]=(str[strlen(str)-1]-'0')%2+'0';  //����
        strcpy(str,Divide(str,2));  //���
    }
    out[i]='\0';    //ĩβ��'\0'���γ��ַ���
    printf("��Ӧ�Ķ�������Ϊ��\n");
    for(int i=strlen(out)-1;i>=0;i--)   //������Ҫ���������
    {
        printf("%c",out[i]);
    }
    printf("\n");
    return 0;
}
