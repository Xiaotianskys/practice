#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct danci
{
    char a[20];
    int count;
}DANCI;

int zimu(char *c)
{
    if(*c>='A'&&*c<='Z')    //ע������Ҫд��*c,����Ҫд��>=��
    {
        *c=*c+32;
        return 1;
    }
    else if(*c>='a'&&*c<='z')
    {
        return 1;
    }
    else
        return 0;
}

int baoli(DANCI *abc,char *s)
{
    int word;
    int n=0,i,j;
    char str[20];
    for(i=0;s[i]!='\0';i++)
    {
        word=0;
        if((i==0&&zimu(&s[i]))||(!zimu(&s[i-1])&&zimu(&s[i])))  //���ʿ�ͷ
        {
            word=1;
            j=0;
        }
        else if(zimu(&s[i]))
        {
            word=1;
        }
        if(word==1)
        {
            str[j]=s[i];
            j++;
        }
        else if(!zimu(&s[i])&&zimu(&s[i-1]))    //��һ�����ʽ�������Ҫ�����������д���
        {
            str[j]='\0';
            int zc;
            for(zc=0;zc<n;zc++)
            {
                if(strcmp(abc[zc].a,str)==0)
                {
                    break;
                }
            }
            if(zc<n)    //������ǰ���ֹ�
            {
                abc[zc].count++;
            }
            else    //û�г��ֵĵ��ʲ��ں���
            {
                strcpy(abc[n].a,str);
                abc[n].count=1;
                n++;
            }
        }
    }
    return n;
}

int main()
{
    FILE *fp;
    fp = fopen("text.txt","r");
    char s[300];
    fgets(s,300,fp);
    fclose(fp);
    printf("%s\n",s);
    DANCI abc[50];
    int n=baoli(abc,s);
    fp = fopen("out.txt","w");
    for(int i=0;i<n;i++)
    {
        printf("%s: \t%d\n",abc[i].a,abc[i].count);
        fprintf(fp,"%s: \t%d\n",abc[i].a,abc[i].count);
    }
    fclose(fp);
    return 0;
}
