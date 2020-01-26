#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char str[30];
    int count;
}Node,*Linklist;

//�ж��Ƿ�����ĸ�ĺ������������ĸ�򷵻�1��ͳ�Ƶ��ʸ�����ʱ�򲻻����ִ�Сд
int zimu(char *c)
{
    if(*c>='a'&&*c<='z')
        return 1;
    if(*c>='A'&&*c<='Z')//���Ǵ�д��ĸ���ն���ת��ΪСд��ĸ
    {
        *c=*c+32;
        return 1;
    }
    return 0;
}

/*
ͨ���۰���ң�Ҫ�����λ�ã����ԭ����������ͬ��Ԫ�أ���ֱ��count++��
���ԭ������û����ͬ��Ԫ�أ�����Ҫ���������ʵ�λ�ã���ʱcount=1����
*/
void zheban(Linklist p[],Node *newnode,int *index)
{
    int low,high;
    int mid;    //�۰���ҵ��������������ض�˵
    int i;
    if(*index==-1)//��������ʲô��û�е�ʱ����Ҫ�ر���
    {
        p[0]=newnode;
        *index=*index+1;
    }
    else
    {
        low=0;
        high=*index;
        while(high>=low)    //ע������һ����>=,��Ȼ��mid=high=low��ʱ����д���
        {
            mid=(low+high)/2;
            if(strcmp(newnode->str,p[mid]->str)>0)
            {
                low=mid+1;
            }
            else if(strcmp(newnode->str,p[mid]->str)<0)
            {
                high=mid-1;
            }
            else if(strcmp(newnode->str,p[mid]->str)==0)
            {
                break;
            }
        }
        if(low>high)
        {
            for(i=*index;i>=low;i--)    //�������
            {
                p[i+1]=p[i];
            }
            p[low]=newnode;     //�����ʵ���λ��
            /*
            ��*p��++�൱��a++,����ָ�����P����ʾ�ı�����ֵ��1����*P++�ȼ���*(P++)��
            ��ʱ�Ƚ�pֵ��1��p����ָ��a������ָ��a��ռ�洢����ĺ���λ�ã���ȡ���ڴ�ֵ
            */
            *index=*index+1;    //ǧ��Ҫд��*index++,��ʾ��ָ���λ�ü�һ
        }
        else
        {
            p[mid]->count++;
            free(newnode);      //���õ�newnodeҪ��ʱfree�������������ڴ�й©
        }
    }
}

int main()
{
    int i=0;
    int j=0;
    int k=-1;
    int word;
    Linklist Q[100]={0};    //������������ָ������
    char p[1000];           //�����һ�λ����λ��
    char s[30];             //������ȡ�����ĵ�����ȡ������λ��
    gets(p);
    int L = strlen(p);      //���뻰�Ļ���
    printf("strlen==============%d\n",L);
    while(i<(L+1))
    {
        word=0;
        if((i==0&&zimu(&p[i]))||(!zimu(&p[i-1])&&zimu(&p[i])))  //��������ĸ�ж���־
        {
            word=1;     //��������s�ı�־λ
            j=0;        //��ʼ�����ı�־λ
        }
        else if(zimu(&p[i]))
        {
            word=1;     //��������s�ı�־λ
            j++;
        }
        if(word==1)
        {
            s[j]=p[i];  //ͨ����j�������д���j++�����ַ��������
        }
        if(word==0)
        {
            s[j+1]='\0';    //������Ϻ�ǧ���������������'\0'���Թ����ַ���
            Node *q=(Node*)malloc(sizeof(Node));    //��ʼ��
            strcpy(q->str,s);
            q->count=1;
            zheban(Q,q,&k);//��仰ִ����֮��Ͳ���k++�ˣ���Ϊ����kΪģ�����õ��ã������оͿ��Ըı���ֵ
        }

        i++;
    }
    //��ӡ�����Ľ��
    for(i=0;i<=k;i++)
    {
        printf("%s:\t%d\n",Q[i]->str,Q[i]->count);
    }
    system("pause");
    return 0;
}
