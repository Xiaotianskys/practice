#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    printf("����������ܵ��ַ�����\n");
    gets(s);
    int i,n=strlen(s);
    for(i=0;i<n;i++)
    {
        if(s[i]>='a'&&s[i]<='z')    //��Сд��ĸ����ת��
            s[i]=96+(26-(s[i]-96)+1);
        else if(s[i]>='A'&&s[i]<='Z')   //�Դ�д��ĸ����ת��
            s[i]=64+(26-(s[i]-64)+1);
    }
    puts(s);
    system("pause");
    return 0;
}
