#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char s[20]; //��ȡÿ�����ʣ��ٶ����ʳ��Ȳ�����20
    struct Node *next;
}Node,*Linklist;

//β�巨������ͷ���ĵ�����ÿ��������ڴ洢�ַ���
Linklist CreateLinklist()
{
    FILE *fp=fopen("data.dat","r"); //�ļ�ָ��
    if(fp==NULL)
    {
        perror("fopen");
    }
    char s[20]; //�����ݴ���ļ�����ĵ���
    Linklist head=(Linklist)malloc(sizeof(Node));   //ͷ���
    strcpy(head->s,"\0");   //ͷ�����ַ�����Ϊ��
    head->next=NULL;
    Linklist tail=head; //����β�巨��βָ�룬ʼ��ָ��β���
    //ѭ����ȡ�ļ���ÿһ��
    while(fgets(s,19,fp)!=NULL) //fgets��ȡ�ļ���ÿһ�У���Ϊ�����ˣ����Ի��л��з�'\n')
    //�һ���ÿ���Զ�����'\0'
    //ȥ������Ļ��з�'\n',�滻Ϊ�ո�
    {
        if(s[strlen(s)-1]=='\n')
        {
            s[strlen(s)-1]=' ';
        }
        Linklist newNode=(Linklist)malloc(sizeof(Node));
        strcpy(newNode->s,s);
        newNode->next=NULL;
        tail->next=newNode;
        tail=newNode;
    }
    return head;
}

//����������ȡ�����е��ַ�����Ȼ��ʹ��ģʽƥ���㷨�����Ӵ�
void TravelAndSearch(Linklist head)
{
    char s[100];    //�洢��Ҫ���ҵ��Ӵ�
    int i,j;
    char string[1000]={'\0'};   //���ڴ洢���е��ʵ�����
    int l1,l2;
    int danci_position; //ȷ���Ӵ����ڵĵڼ�������
    int start_position; //ȷ�������ڵĿ�ʼλ��
    printf("����������ҵ��Ӵ�s��\n");
    gets(s);
    Linklist p=head->next;  //����ָ��p
    while(p!=NULL)
    {
        strcat(string,p->s);
        p=p->next;
    }
    /*
    ʹ���ַ�����ģʽƥ���㷨�������Ӵ�������ѭ���������㷨
    */
    l1=strlen(string);
    l2=strlen(s);
    i=0;
    j=0;
    danci_position=1;   //��ʼʱ���ڵ�һ������
    start_position=1;   //��ʼʱ�ڵ��ʵĵ�һ��λ��
    //����Լ�д�����ַ��ֶ�ģ�⣬������⡣
    while(i<l1&&j<l2)
    {
        if(string[i]==' ')  //���Ϊ�ո��������������������֮��ļ��
        {
            i++;    //i+1������ƶ�����һ�����ʣ�j����
            if(j==0)
            //j==0����ǰ����еıȽϲ�ƥ�䣬��Ҫ����һ���������¿�ʼ�Ƚϣ���ʱ���ʼ�����Ҫ+1
            {
                danci_position++;
                start_position=1;
            }
        }
        if(string[i]==s[j]) //����ȣ����������ȥ
        {
            i++;
            j++;
        }
        else
        {
            i=i-j+1;    //������ȣ���ֻ�ܻ���ָ��i,j��j�ص�0���¿�ʼ�ȣ�i
            //�ص�i-j+1������һ�εĺ�һ��λ�ã���ס�����ʽ
            j=0;
            start_position++;   //��Ϊ����ȣ���˵����ڲ�����ʼλ����Ҫ����
        }
    }
    if(j==l2)   //���j�ߵ�������棬������Ӵ��Ƚ����ˣ�����Ӵ���Ȼ�ڹ�ʽ��
        printf("�Ӵ�ƥ��ɹ���%s��%s�ĵ�%d�����ʵĵ�%d���ַ���ʼ\n",s,string,danci_position,start_position);
    else
        printf("%s��û���Ӵ�%s\n",string,s);
    printf("\n");
    return;
}

int main()
{
    Linklist head=CreateLinklist();
    TravelAndSearch(head);
    system("pause");
    return 0;
}
