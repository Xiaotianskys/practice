#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char* Mystrrev(char *s)
{
    int ls=strlen(s);
    char temp;
    for(int i=0;i<ls/2;i++)
    {
        temp=s[i];
        s[i]=s[ls-i-1];
        s[ls-i-1]=temp;
    }
    return s;
}

void ADD(char *a,char *b,char *c)
{
    int la=strlen(a);
    int lb=strlen(b);
    a=Mystrrev(a);
    b=Mystrrev(b);
    int lmax=la>lb?la:lb;
    int lmin=la<lb?la:lb;
    int i;
    int yunum=0;
    for(i=0;i<lmin;i++)
    {
        int num=yunum+a[i]-2*'0'+b[i];
        c[i]=num%10+'0';
        yunum=num/10;
    }
    if(lb>la)
        strcpy(a,b);
    while(i<lmax)
    {
        int num=yunum+a[i]-'0';
        c[i]=num%10+'0';
        yunum=num/10;
        i++;
    }
    if(yunum>0)
    {
        c[i]=yunum+'0';
        c[i+1]='\0';
    }
    else
    {
        c[i]='\0';
    }
    c=Mystrrev(c);
}

int main()
{
    char a[MAX];
    char b[MAX];
    char c[MAX];
    gets(a);
    gets(b);
    ADD(a,b,c);
    puts(c);
    return 0;
}
