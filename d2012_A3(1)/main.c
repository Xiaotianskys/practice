#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char s[20]; //���ڴ�ŵ���
    int count;  //���ڴ�ȡ�����ʵĸ���
    struct node *next;
}Node,*Linklist;

/*�ж��Ƿ�Ϊ��ĸ�ĺ��������Ǵ�Сд�ĵ���Ӧ����һ���ģ�����֮�������β�
��ָ�����ʽ������Ҫ����д��ĸתΪСд��ĸ��������ָ����ܱ�֤�βεĸı�
Ӱ�쵽ʵ��
*/
int zimu(char *c)
{
    if(*c>='a'&&*c<='z')    //Сд��ĸֱ��ȷ�ϼ���
    {
        return 1;
    }
    if(*c>='A'&&*c<='Z')    //��д��ĸʱ�����￼���жϣ����Ѵ�дתСд
    {
        *c=*c+32;
        return 1;
    }
    else
        return 0;
}

void binary_search(Linklist p[],int *index,Linklist newnode)    //���ֲ��ҵĺ���
{
    int low,high;   //���ֲ��ҵĸߵ�ָ��
    int mid;
    int i;
    if(*index==-1)  //֤��ָ�������ǿյ�
    {
        p[0]=newnode;   //��ʱ��ֱ�ӽ�ָ�������0��Ԫ��ָ��ý��
        (*index)++;
    }
    else    //��ʼ���ֲ��ң�ָ������Ӧ�ð����ַ����Ĵ�С���򣨴�С��������
    {
        low=0;
        high=*index;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(strcmp(p[mid]->s,newnode->s)>0)
            {
                high=mid-1;
            }
            else if(strcmp(p[mid]->s,newnode->s)<0)
            {
                low=mid+1;
            }
            else if(strcmp(p[mid]->s,newnode->s)==0)    //���
            {
                break;
            }
        }
        if(low<=high)   //������low<=high,֤����������Ǵ��ڵģ�����Ӧ���ַ���++
        {
            (p[mid]->count)++;
            return;
        }
        else    //����low>=high,֤�����ֵ����ǲ����ڵģ�Ӧ�ò��룬�Ҳ���λ����low���ڵ�λ��
        {
            for(i=*index;i>=low;i--)
            {
                p[i+1]=p[i];    //����
            }
            p[low]=newnode;     //���룬p[low]ָ��newnode
            (*index)++;         //Ԫ��+1
            return;
        }
    }
}

int main()
{
    Linklist *p;    //ָ������
    int i,l,word=0; //word�ǵ��ʱ��
    int k;
    int index=-1;   //ָ��������±�
    Linklist newnode;   //���������½��
    int count_danci=0;
    char s[1000];   //���ڴ��Ҫ�жϵ�Ӣ����䣨�ٶ����ĳ���Ϊ1000��
    char str[20];   //���ڴ�ŵ���
    printf("������������Ӣ����䣺\n");   //����Ҳ�п�����ֱ�Ӵ��ļ��ж��������䣬
    //��Ϊ��Ŀ��˵�����漰�ļ������������������Լ�д��仹�Ǵ��ļ������������ǲ��ģ�
    //��������ʡ���˴��ļ��ж��Ĺ���
    gets(s);    //����������Ӣ�����
    l=strlen(s);
    p=(Linklist*)calloc(1000,sizeof(Linklist));     //ָ�������ͷָ��p����һ������ָ��
    word=0;     //�����ʱ��word=0
    for(i=0;i<=l;i++)
    {
        if(i==l&&!zimu(&s[i-1]))
            break;
        if((!zimu(&s[i])&&i-1>=0&&zimu(&s[i-1]))||(i==l&&zimu(&s[i-1])))
        //֤�����ʽ����ˣ�Ӧ�÷����½��newnode
        {
            str[k]='\0';
            newnode=(Linklist)calloc(1,sizeof(Node));   //�����½��
            newnode->count=1;   //����Ϊ1
            strcpy(newnode->s,str);     //�����ʷ����½��
            binary_search(p,&index,newnode);    //�����۰����
        }
        if(!zimu(&s[i]))
            word=0;     //������ĸ������ʱ��=0
        else if(word==0)    //֤���ҵ����ʵĿ�ʼ�ˣ�����Ӧ�ÿ��ǽ����ʷŵ�
        //ĳ���ط��������ʽ������ٷ���������
        {
            k=0;
            word=1; //��ʱ��=1
            count_danci++;
        }
        if(word==1)
        {
            str[k]=s[i];
            k++;
        }
    }
    printf("��ͬ������index=%d\n",index+1);
    for(i=0;i<=index;i++)
    {
        printf("%s\t%d\n",p[i]->s,p[i]->count);
    }
    system("pause");
    return 0;
}
