#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char word[30];
    struct node *first;
    struct node *next;
}NODE,*Linklist;

void GetNextpos(char *str,int *nextpos,int length)
{
    nextpos[0]=-1;
    int i,j;
    i=-1;j=0;
    while(j<length)
    {
        if(i==-1||str[j]==str[i])
        {
            i++;
            j++;
            nextpos[j]=i;
        }
        else
        {
            i=nextpos[i];
        }
    }
}

void KMP(Linklist L,char *str,int *nextpos)
{
    int i=0,j=0,k=0;
    Linklist p=L;
    int len=strlen(str);
    while(p&&k<len)
    {
        int length=strlen(p->word);
        for(j=0;j<length;j++)
        {
            if(p->word[j]==str[k])
                k++;
            else
            {
                if(k!=0)
                    k=nextpos[k];
            }
            if(k==len)
                break;
        }
        if(k==len)
            break;
        p=p->next;
        i++;
    }
    if(k==len)
    {
        j=j+1;
        i=i+1;
        j=j-len+1;
        while(j<1)
        {
            i--;
            p=p->first;
            j=strlen(p->word)+j;
        }
        printf("第%d个单词,第%d个位置\n",i,j);
    }
    else
    {
        printf("没有这个单词。\n");
    }
}

int main()
{
    FILE *fp;
    char str[30];
    fp=fopen("data.dat","r");
    if(fp==NULL)
    {
        printf("cannot open file.\n");
        exit(0);
    }
    Linklist L=NULL,p;
    while(fgets(str,30,fp))
    {
        str[strlen(str)-1]='\0';
        Linklist newnode=(Linklist)malloc(sizeof(NODE));
        strcpy(newnode->word,str);
        newnode->next=NULL;
        if(L==NULL)
        {
            L=newnode;
            newnode->first=L;
        }
        else
        {
            for(p=L;p->next!=NULL;p=p->next);
            p->next=newnode;
            newnode->first=p;
        }
    }
    for(p=L;p!=NULL;p=p->next)
    {
        printf("%s ",p->word);
    }
    putchar('\n');
    printf("Please input:");
    char mystr[30];
    scanf("%s",mystr);
    int nextpos[30];
    int length=strlen(mystr);
    GetNextpos(mystr,nextpos,length);
    KMP(L,mystr,nextpos);
    return 0;
}
