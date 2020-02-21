#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXI 200

typedef struct BigInteger
{
    int integer[MAXI];
    int length;
}BIG;

void Transfor(char *s1,BIG *s2)
{
    int i;
    char temp;
    int n=strlen(s1);
    for(i=0;i<n/2;i++)
    {
        temp=s1[i];
        s1[i]=s1[n-1-i];
        s1[n-1-i]=temp;
    }
    for(i=0;i<n;i++)
    {
        s2->integer[i]=s1[i]-'0';
    }
    s2->length=n;
}

void Multiple(BIG *a,BIG *b,BIG *c)
{
    int i,j;
    c->length=a->length+b->length;
    for(i=0;i<a->length;i++)
    {
        for(j=0;j<b->length;j++)
        {
            c->integer[i+j]=c->integer[i+j]+a->integer[i]*b->integer[j];
        }
    }
    for(i=0;i<c->length;i++)
    {
        c->integer[i]%=10;
        c->integer[i+1]+=c->integer[i]/10;
    }
    for(i=c->length-1;i>0;i--)
    {
        if(c->integer[i]!=0)
            break;
        c->length--;
    }
}

int main()
{
    char a[MAXI];
    char b[MAXI];
    char c[MAXI];
    int i;
    for(i=0;i<MAXI;i++)
    {
        a[i]=b[i]=c[i]=0;
    }
    gets(a);
    gets(b);
    BIG A,B,C;
    memset(A.integer,0,sizeof(A.integer));
    memset(B.integer,0,sizeof(B.integer));
    memset(C.integer,0,sizeof(C.integer));
    Transfor(a,&A);
    Transfor(b,&B);
    Transfor(c,&C);
    Multiple(&A,&B,&C);
    for(i=C.length-1;i>=0;i--)
    {
        printf("%d",C.integer[i]);
    }
    return 0;
}
