#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char s[20]; //���ڴ�ŵ���
    int count;  //���ڴ�ű����ʵĸ���
    struct node *next;
}Node,*Linklist;

int zimu(char *c)
/*
�ж��Ƿ�Ϊ��ĸ�ĺ��������Ǵ�Сд�ĵ���Ӧ����һ���ģ�����֮�������β���ָ�����ʽ������
Ҫ����д��ĸתΪСд��ĸ��������ָ����ܱ�֤�βεĸı�Ӱ�쵽ʵ��
*/
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
    if(*index==-1)
    {
        p[0]=newnode;   //��ʱֱ�ӽ�ָ�������0��Ԫ��ָ��ý��
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
            else if(strcmp(p[mid]->s,newnode->s)==0)
            {
                break;
            }
        }
        if(low<=high)   //������low<=high��֤����������Ǵ��ڵģ�����Ӧ���ַ���++
        {
            (p[mid]->count)++;  //����֮����������
            free(newnode);
            return ;
        }
        else    //����low>high��֤���õ����ǲ����ڵģ�Ӧ�ò��룬�Ҳ���λ����low���ڵ�λ��
        {
            for(i=*index;i>=low;i--)
            {
                p[i+1]=p[i];    //����
            }
            p[low]=newnode; //����p[low]ָ��newnode
            (*index)++;
            return ;
        }
    }
}

int main()
{
    FILE *fp=fopen("data.dat","r");  //�ļ�ָ��
    if(fp==NULL)
    {
        perror("fopen");
    }
    Linklist *p;    //ָ������
    int i,l,word=0; //word�ǵ��ʱ�־
    int k;
    int index=-1;   //ָ��������±�
    Linklist newnode;   //���������½��
    int count_danci=0;
    char s[1000];   //�������Ҫ�жϵ�Ӣ����䣨�ٶ����ĳ���Ϊ1000��
    char str[20];   //���ڴ�ŵ���
    p=(Linklist *)calloc(2000,sizeof(Linklist));
    //ָ�������ͷָ��p����һ������ָ�루������ҪԤ�ȼ��費ͬ���ʸ�������������2000�����ʣ�
    int flag=0;
    while(fgets(s,13,fp)!=NULL)    //fgets��ȡ�ļ���ÿһ�У��һ���ÿ���Զ�����'\0'
    {
        if(flag!=1) //���ڱ����һ�ζ����������һ�������Ƿ����
            word=0; //�����ʱ�־Word=0������Ƕ��μ����϶����еĿ�ʼ
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(i==l&&!zimu(&s[i-1]))
                break;
            if((!zimu(&s[i])&&i-1>=0&&zimu(&s[i-1]))||(flag==1&&i>0&&!zimu(&s[i])&&zimu(&s[i-1]))||(flag==1&&i==0&&!zimu(&s[i])))//(i==l&&zimu(&s[i-1]))
            //֤�����ʽ����ˣ�Ӧ�ü����½��newnode
            {
                str[k]='\0';
                newnode=(Linklist)calloc(1,sizeof(Node));   //�����½��
                newnode->count=1;   //����Ϊ1
                strcpy(newnode->s,str); //�����ʷ����½��
                binary_search(p,&index,newnode);    //�����۰����
                if(flag==1)
                {
                    flag=0;
                    word=0; //���м����ϵĿ�ͷ��word�ڿ�ʼû����Ϊ0
                }
            }
            if(!zimu(&s[i]))
                word=0; //������ĸ������ʱ��=0
            else if(word==0)
            //֤���ҵ����ʵĿ�ʼ�ˣ�����Ӧ�ÿ��ǽ����ʷŵ�ĳ���ط��������ʽ������ٷ���������
            {
                k=0;
                word=1; //��ʱ��Ϊ1
                count_danci++;
            }
            if(word==1)
            {
                str[k]=s[i];
                k++;
            }
        }
        if(zimu(&s[i-1]))
            flag=1; //���Ϊ1����Ϊ����һ�е����һ������û�ж��ꡣ
    }
    printf("��ͬ������index=%d\n",index+1);
    for(i=0;i<=index;i++)
    {
        printf("%s\t%d\n",p[i]->s,p[i]->count);
    }
    system("pause");
    return 0;
}
