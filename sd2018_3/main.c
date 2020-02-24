#include <stdio.h>

double collect(double (*p)(double),double a,double b,int n)
/*
ԭ���У�double (*p)(double)��double *p��
�����pʵ����ָ���Ǻ���f���������Ӧ��ʹ��ָ����f��ָ����Ϊ�βΣ�������ֱ����
double*��ָ����Ϊ�βΣ�Ӧ�޸�Ϊdouble(*p)(double)�����ܹ�ָ����f
*/
{
    double h,area;  //ע�������ǸĴ�area���������ۼӵõ����յ��������Ҫ��ʼ��Ϊ0
    area=0; //ԭ����û����һ�д���
    int i;
    h=(b-a)/n;  //�����ԣ�����������ǽ��ױߵ�a-b�ֳ�n�ݣ�ÿ�ݵĳ�Ϊh���ó�*���ۼ�����
    //ȡ���
    for(i=0;i<100;i++)
    {
        area+=((*p)(a+i*h)+(*p)(a+(i+1)*h))*h/2;
        //������õ������ʽ�����εĹ�ʽ�����ϵ�+�µף�*��h/2.������С�������ۼӣ������֣���
        //��󼴿ɵõ����ߵĻ��֣�������a-b�������
    }
    return area;
}

double f(double x)  //f����������ʵ�ʾ�������Ҫ��ȡ�Ļ��ֺ���������Ϊf(x)=1+x^3
{
    return 1+x*x*x;
}

int main()
{
    double sum;
    sum=collect(f,-1,1,100);
    //ԭ����f��f()
    //������f��Ϊʵ�Σ���Ӧ�ð������ţ�
    printf("%lf\n",sum);
    return 0;
}
