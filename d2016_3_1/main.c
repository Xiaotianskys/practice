#include <stdio.h>
#include <stdlib.h>

int zuidagongyueshu(int x,int y)    //շת����������Լ���ĺ���
{
    int temp;
    if(x<y) //ʹx��x,y�нϴ������Ȼ����շת���
    {
        temp=x;
        x=y;
        y=temp;
    }
    while(y)
    {
        temp=x%y;   //շת�����ȡ��
        x=y;
        y=temp;     //yΪÿ�ε�����
    }
    return x;
}

int zuixiaogongbeishu(int x,int y)  //�����С�������ĺ���
{
    return x*y/zuidagongyueshu(x,y);
}

int main()
{
    FILE *in,*out;  //inָ�������ļ���outָ������ļ�
    int x,y;
    printf("�����������������Լ������С������������x��y��");
    scanf("%d",&x);
    scanf("%d",&y);
    if((in=fopen("gongyueshugongbeishu.in","w"))==NULL)
    {
        printf("cannot open file.\n");
        exit(0);
    }
    if((out=fopen("gongyueshugongbeishu.out","w"))==NULL)
    {
        printf("cannot open file.\n");
        exit(0);
    }
    fprintf(in,"%d %d",x,y);    //��������д�������ļ�
    int m=zuidagongyueshu(x,y);
    int n=zuixiaogongbeishu(x,y);
    //���õ��Ľ��д������ļ�
    fprintf(out,"%d��%d�����Լ����%d,��С��������%d\n",x,y,m,n);
    printf("%d��%d�����Լ����%d\n��С������Ϊ��%d\n",x,y,m,n);
    fclose(in);
    fclose(out);
    system("pause");
    return 0;
}
