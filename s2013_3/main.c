#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char* p[MAX];

int Mystrcmp(char *s1,char *s2)
{
    int len1=strlen(s1);
    int len2=strlen(s2);
    if(len1==len2)
    {
        int n1=0;
        int n2=0;
        for(int i=0;s1[i]!='\0';i++)
        {
            if(s1[i]=='1')
                n1++;
        }
        for(int i=0;s2[i]!='\0';i++)
        {
            if(s2[i]=='1')
                n2++;
        }
        if(n1>n2)
            return 1;
        else if(n1==n2)
            return 0;
        else
            return -1;
    }
    else
    {
        if(len1>len2)
            return 1;
        else
            return -1;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    getchar();
    for(i=0;i<n;i++)
    {
        char *s=(char*)malloc(sizeof(char)*MAX);
        gets(s);
        p[i]=s;
    }
    for(i=0;i<n-1;i++)
    {
        int flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(Mystrcmp(p[j],p[j+1])==1)
            {
                char *temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
    printf("½á¹ûÊÇ£º\n");
    for(i=0;i<n;i++)
    {
        printf("%s\n",p[i]);
        free(p[i]);
    }
    return 0;
}
