#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int defSXHS(int x);
void filewrite1(int x,char* filename,int flag);
void filewrite2(char x,char* filename,int flag);
int main()
{
    int n;
    scanf("%d",&n);
    int flag1=0;
    int flag2=0;
    filewrite1(n,"shui.in",flag1);
    flag1=1;
    while(n!=0)
    {
        if(defSCHS(n)){
            printf("%c\n",'T');
            filewrite2('T',"shui.out",flag2);
            flag2=1;
        }
        else{
            printf("%c\n",'F');
            filewrite2('F',"shui.out",flag2);
            flag2=1;
        }
        scanf("%d",&n);
        filewrite1(n,"shui.in",flag1);
    }
    return 0;
}

int defSCHS(int x)
{
    int sum = 0;
    int a = x;
    while(x>0)
    {
        int k=x%10;
        sum = sum + k*k*k;
        x=x/10;
    }
    if(sum == a)
        return 1;
    else
        return 0;
}

void filewrite1(int x,char* filename,int flag)
{
    FILE *fp;
    if(flag==0)
    {
        if((fp=fopen(filename,"w"))==NULL)
        {
            printf("Failure to open %s!\n",filename);
            exit(0);
        }
    }
    else
    {
        if((fp=fopen(filename,"a"))==NULL)
        {
            printf("Failure to open %s!\n",filename);
            exit(0);
        }
    }
    fprintf(fp,"%d\n",x);
    fclose(fp);
}

void filewrite2(char x,char* filename,int flag)
{
    FILE *fp;
    if(flag==0)
    {
        if((fp=fopen(filename,"w"))==NULL)
        {
            printf("Failure to open %s!\n",filename);
            exit(0);
        }
    }
    else
    {
        if((fp=fopen(filename,"a"))==NULL)
        {
            printf("Failure to open %s!\n",filename);
            exit(0);
        }
    }
    fprintf(fp,"%c\n",x);
    fclose(fp);
}
