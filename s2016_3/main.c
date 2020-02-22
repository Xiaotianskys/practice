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
    printf("他们的最大公因数是：%d\n",DSP(a,b));
    fp=fopen("out.txt","w");
    fprintf(fp,"他们的最大公因数是：%d\n",DSP(a,b));
    printf("他们的最小公倍数是：%d\n",a*b/DSP(a,b));
    fprintf(fp,"他们的最小公因数是：%d\n",a*b/DSP(a,b));
    return 0;
}
