#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,i;  //Ҫת��Ϊ�����Ƶ�ʮ������
    int binary[100];    //����������ڴ�ų���ȡ�����ŵõ�����
    int k=0;    //Ϊ��֪�����������ж���λ����k������
    printf("������һ����ת��Ϊ�����Ƶ�ʮ��������");
    scanf("%d",&n);
    m=n;
    while(n!=0) //���ڼ�������Ƶķ�����ģ��
    {
        binary[k]=n%2;
        n=n/2;
        k++;    //kʵ�ʱ��Ƕ����Ƶ�λ��
    }
    printf("ʮ������%d��Ӧ�Ķ��������ǣ�",m);
    for(i=k-1;i>=0;i--)
        printf("%d",binary[i]); //���ʮ���ƶ�Ӧ�Ķ�������
    putchar('\n');
    system("pause");
    return 0;
}
