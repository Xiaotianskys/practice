#include <stdio.h>
#include <stdlib.h>

int DSP(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return DSP(b,a%b);
    }
}

int main()
{
    FILE *fp=fopen("123.txt","r");
    int a,b;
    fscanf(fp,"%d %d",&a,&b);
    fclose(fp);
    printf("a=%d,b=%d\n",a,b);
    printf("���ǵ���������ǣ�%d\n",DSP(a,b));
    fp=fopen("out.txt","w");
    fprintf(fp,"���ǵ���������ǣ�%d\n",DSP(a,b));
    printf("���ǵ���С�������ǣ�%d\n",a*b/DSP(a,b));
    fprintf(fp,"���ǵ���С�������ǣ�%d\n",a*b/DSP(a,b));
    return 0;
}
