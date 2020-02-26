#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct danci
{
    char str[30];
    int count;
}DANCI;

int length=0;

int zimu(char *c)
{
    if(*c>='a'&&*c<='z')
    {
        return 1;
    }
    else if(*c>='A'&&*c<='Z')
    {
        *c=*c+32;
        return 1;
    }
    else
        return 0;
}

void zheban(DANCI *cizu,DANCI *p)
{
    if(length==0)
    {
        cizu[0].count=p->count;
        strcpy(cizu[0].str,p->str);
        length++;
    }
    else
    {
        int low=0;
        int high=length-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(strcmp(cizu[mid].str,p->str)==0)
            {
                cizu[mid].count++;
                free(p);
                break;
            }
            else if(strcmp(cizu[mid].str,p->str)<0)
            {
                low=mid+1;
            }
            else if(strcmp(cizu[mid].str,p->str)>0)
            {
                high=mid-1;
            }
        }
        if(high<low)
        {
            for(int i=length-1;i>high;i--)  //其实low指针所指的位置就是插入的位置
            {
                cizu[i+1].count=cizu[i].count;
                strcpy(cizu[i+1].str,cizu[i].str);
            }
            cizu[high+1].count=p->count;
            strcpy(cizu[high+1].str,p->str);
            free(p);
            length++;
        }
    }
}
int main()
{
    FILE *fp=fopen("data.dat","r");
    if(fp==NULL)
    {
        printf("cannot open file.\n");
        exit(0);
    }
    char abc[200];
    char word[30];
    int IsWord=0;
    DANCI strs[50]={0};
    fgets(abc,200,fp);
    puts(abc);
    fclose(fp);
    int i=0,j;
    while(abc[i]!='\0')
    {
        IsWord=0;
        if((i==0&&zimu(&abc[i]))||(!zimu(&abc[i-1])&&zimu(&abc[i])))
        {
            IsWord=1;
            j=0;
        }
        else if(zimu(&abc[i]))
            IsWord=1;
        else
        {
            IsWord=0;
        }
        if(IsWord)
        {
            word[j]=abc[i];
            j++;
        }
        else if(zimu(&abc[i-1])&&!zimu(&abc[i]))
        {
            word[j]='\0';
            DANCI *p=(DANCI*)malloc(sizeof(DANCI));
            p->count=1;
            strcpy(p->str,word);
            zheban(strs,p);
            j=0;
        }
        i++;
    }
    for(i=0;i<length;i++)
    {
        printf("%s:%d\n",strs[i].str,strs[i].count);
    }
    return 0;
}
