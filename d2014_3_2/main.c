#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void jianfa(char s1[], char s2[], int a[]) //����Ĭ����s1��s2Ҫ��ģ����С�Ļ�����
//ֻ��������������λ�ã�������-���ż��ɡ����Կ����Լ�дһ������-С����ģ��
{
    int l1=strlen(s1);
    int l2=strlen(s2);
    int k=0;    //k��a������±꣬a����������ż����õ��Ľ��
    int i,j;
    for(i=l1-1,j=l2-1;i>=0&&j>=0;i--,j--)
    {
        if(s1[i]>=s2[j])
            a[k]=s1[i]-s2[j];
        else if(s1[i]<s2[j])
        {
            a[k]=10+s1[i]-s2[j];
            s1[i-1]--;  //���λ��λ
        }
        k++;
    }
    if(i>=0)    //�����ʱs1��û�м��꣨Ҳֻ�п���s1û���꣬��Ϊ����������s1��s2��
    {
        for(;i>=0;i--)
        {
            if(s1[i]>='0')
                a[k]=s1[i]-'0';
            else if(s1[i]<'0')  //��Ϊ�п���s1[i]���ڽ�λ�����-1����ʱ��С��0�ģ�
            //�����λ��λ
            {
                a[k]=10+s1[i]-'0';
                s1[i-1]--;
            }
            k++;
        }
    }
    for(i=k-1;i>=0;i--) //���ڼ���֮���λ���ܻ���0��������ǵ����ҵ���һ������0��
    //λ�ã������
    {
        if(a[i]!=0) //a�зŵ���int��ֱ����0�Ƚϼ��ɣ�������'0'�Ƚ�
            break;
    }
    for(;i>=0;i--)  //������
    {
        printf("%d",a[i]);
    }
}

int main()
{
    char s1[100];
    char s2[100];
    int a[100];
    printf("����������������Ĵ���s1,s2��\n");
    gets(s1);
    gets(s2);
    int l1=strlen(s1);
    int l2=strlen(s2);  //ͨ���ַ�����ĳ��������ж�s1��s2�ĸ�����һ��
    if(l1>l2)   //��ʱs1�ض���s2��
    {
        jianfa(s1,s2,a);    //���ú���jianfa(����)
    }
    else if(l1<l2)  //��ʱs1��s2С��������������ţ��ٽ�����������
    {
        putchar('-');
        jianfa(s2,s1,a);
    }
    else if(l1==l2) //�������ʱ���޷��ж�˭��˭С�����Կ�����strcmp����
    {
        if(strcmp(s1,s2)>0) //s1>s2ʱ
        {
            jianfa(s1,s2,a);
        }
        else if(strcmp(s1,s2)<0)    //s1<s2ʱ
        {
            putchar('-');
            jianfa(s2,s1,a);
        }
        else if(strcmp(s1,s2)==0)
        {
            printf("0");
        }
    }
    putchar('\n');
    system("pause");
    return 0;
}
