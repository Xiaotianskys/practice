#include <stdio.h>
#include <stdlib.h>

int shuixianhuashu(int n)      //�ж��Ƿ�Ϊˮ�ɻ����ĺ���������ֵΪbool����
{
    int sum=0;
    int m=n;    //����ԭ�ȵ�n
    int k;
    while(n)
    {
        k=n%10; //ͨ��ȡ����ÿһλ��
        sum=sum+k*k*k;
        n=n/10; //����10���������һλ���������´�ȡ��ʱ�������εõ�֮ǰ����
    }
    if(sum==m)
        return 1;
    else
        return 0;
}

int main()
{
    FILE *in,*out;  //�����ļ�ָ��
    int m;
    printf("������Ҫ�ж��Ƿ�Ϊˮ�ɻ�����������0��������\n");
    if((in=fopen("shui.in","w"))==NULL) //��д�ķ�ʽ�򿪵�ǰĿ¼�µ�shui.in�ļ������������shui.in��ᴴ�����ļ���
    {
        printf("file cannot open.\n");
        exit(0);
    }
    if((out=fopen("shui.out","w"))==NULL)   //��д�ķ�ʽ�򿪵�ǰĿ¼�µ�shui.out�ļ�
    {
        printf("file cannot open.\n");
        exit(0);
    }
    while(scanf("%d",&m)!=EOF)  //����������ݲ����ļ�������־EOF=-1����ʱѭ������
    {
        fprintf(in,"%d\n",m);   //�Ȱ�������ַ�д��shui.in�У������ǲ���0��
        if(m==0)
            break;  //����Ϊ0��������ѭ��
        else
        {
            if(shuixianhuashu(m))   //���m��ˮ�ɻ���
            {
                fputc('T',out);
                fputc('\n',out);
                printf("T\n");
            }
            else    //����ˮ�ɻ���ʱ
            {
                fputc('F',out);
                fputc('\n',out);
                printf("F\n");
            }
        }
    }
    fclose(in); //�ر��ļ�ָ��
    fclose(out);
    system("pause");    //��ֹ��������ر�
    return 0;
}
