#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int year;
    int month;
    int day;
}Data;

typedef struct
{
    int xh;
    char name[100];
    Data birthday;
    int score;
}STU;

int main()
{
    int i,n;
    printf("������ѧ������\n");
    scanf("%d",&n);
    STU *p=(STU*)malloc(sizeof(STU)*n); //Ϊp��̬����ռ䣬����n��ѧ������Ҫ�Ŀ�
    //�䣬p�ǽṹ��������׵�ַ
    STU *q=p;   //�����qָ����ʵ���Ǳ���������̬������׵�ַ
    for(i=0;i<n;i++)
    {
        printf("�������%d��ѧ����ѧ��\n",i+1);
        scanf("%d",&p->xh);
        printf("�������%d��ѧ��������\n",i+1);
        scanf("%s",p->name);    //����name��������һ����ַ�����Բ���Ҫ��ȡ��ַ��
        printf("�������%d��ѧ�������գ���1991.11.26\n",i+1);
        scanf("%d.%d.%d",&p->birthday.year,&p->birthday.month,&p->birthday.day);
        printf("�������%d��ѧ���ķ���\n",i+1);
        scanf("%d",&p->score);  ///ԭ������û��&��
        p++;    ///ԭ��������û��
    }
    p=q;
    for(i=0;i<n;i++)
    {
        printf("%d\t%s\t%d.%d.%d\t%d\n",p->xh,p->name,p->birthday.year
               ,p->birthday.month,p->birthday.day,p->score);
        p++;
    }
    free(q);    ///ԭ��������free(p)����Ϊp�Ѿ������ˣ�
                ///�����Ƕ�̬����Ľṹ��������׵�ַ��
    return 0;
}
