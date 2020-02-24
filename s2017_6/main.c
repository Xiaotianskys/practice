#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[200];
    char str1[200];
    char str2[200];
    gets(str);
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='a'&&str[i]<='z')
        {
            str1[i]=(str[i]-'a'+26+5)%26+'a';
            str2[i]=(26-1-(str[i]-'a'))+'a';
        }
        if(str[i]>='A'&&str[i]<='Z')
        {
            str1[i]=(str[i]-'A'+26+5)%26+'A';
            str2[i]=(26-1-(str[i]-'A'))+'A';
        }
    }
    puts(str1);
    puts(str2);
    return 0;
}
