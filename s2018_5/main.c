#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void atoA(char *str)
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='a'&&str[i]<='z')
            str[i]-=32;
    }
}

int main()
{
    char str[100];
    gets(str);
    atoA(str);
    puts(str);
    FILE *fp;
    fp=fopen("E:\\test.txt","w");
    fputs(str,fp);
    fclose(fp);
    return 0;
}
