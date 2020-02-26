#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char mima[6];
    int abc[3];
    int i,j;
    srand((unsigned)time(NULL));
    for(i=0;i<6;i++)
    {
        int magic=rand()%62;
        if(magic<26)
            mima[i]='a'+magic;
        else if(magic<52)
            mima[i]='A'+magic-26;
        else
            mima[i]='0'+magic-52;
        if(i==5)
        {
            for(j=0;j<3;j++)
            {
                abc[j]=0;
            }
            for(j=0;j<6;j++)
            {
                if(mima[j]>='a'&&mima[j]<='z')
                    abc[0]=1;
                else if(mima[j]>='A'&&mima[j]<='Z')
                    abc[1]=1;
                else if(mima[j]>='0'&&mima[j]<='9')
                    abc[2]=1;
            }
            int flag=0;
            for(j=0;j<3;j++)
            {
                if(abc[j]==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                i=-1;
        }
    }
    printf("Password:");
    for(i=0;i<6;i++)
    {
        printf("%c",mima[i]);
    }
    return 0;
}
