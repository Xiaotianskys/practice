#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 128
#define MAXI 1000

int ALF[MAXN];

void Atoa(char *s,char *s1)
{
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
            s[i]+=32;
    }
    strcpy(s1,s);
}

void Cal(char *str)
{
    for(int i=0;str[i]!='\0';i++)
    {
        ALF[(int)str[i]]++;
    }
}

int main()
{
    char str[MAXI];
    FILE *fp=fopen("in.txt","r");
    fgets(str,MAXI,fp);
    fclose(fp);
    puts(str);
    Atoa(str,str);
    Cal(str);
    fp=fopen("out.txt","w");
    for(int i=0;i<128;i++)
    {
        if(ALF[i]!=0)
        {
            printf("%c:%d\n",i,ALF[i]);
            fprintf(fp,"%c:%d\n",i,ALF[i]);
        }
    }
    fclose(fp);
    return 0;
}
