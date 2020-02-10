#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(char *s1,char *s2)  //自定义的比较函数
{
    int l1=strlen(s1);
    int l2=strlen(s2);
    int i,j;
    int m=0,n=0;
    for(i=0;i<l1;i++)   //求l1中'0'的个数
        if(s1[i]=='0')
            m++;
    for(j=0;j<l2;j++)   //求l2中'0'的个数
        if(s2[j]=='0')
            n++;
    if(l1>l2)   //根据题目要求的比较规则得到以下三种返回方式
        return 1;
    else if((l1==l2)&&m<n)
        return 1;
    else
        return 0;
}

int main()  //主函数
{
    int n;
    printf("请输入字符串的个数n：");
    scanf("%d",&n); //可以考虑定义n个元素的指针数组，指针数组中的每个指针指向一个字符串，
    //动态分配指针数组，得考虑用指向指针的指针
    char **s=(char**)calloc(n,sizeof(char*));   //定义指向指针数组的首地址，动态分配
    int i,j,k;
    for(i=0;i<n;i++)    //由于字符指针数组中的元素没有指向确定的存储单元，无法输入
    //字符串，应该为这些字符指针再分配存储单元。
        s[i]=(char*)calloc(100,sizeof(char));   //假定字符串的长度最多为100
    for(i=0;i<n;i++)
        scanf("%s",s[i]);
    char *temp=(char*)calloc(100,sizeof(char)); //用于交换排序用的临时空间
    for(i=0;i<n-1;i++)  //这里用选择排序，各种排序方法得自己好好掌握
    {
        k=i;
        for(j=i+1;j<n;j++)
            if(compare(s[k],s[j]))
                k=j;
        if(k!=i)    //如果最后发现最小的不是i对应的字符串，则进行交换
        {
            strcpy(temp,s[i]);
            strcpy(s[i],s[k]);
            strcpy(s[k],temp);
        }
    }
    printf("排序的结果如下所示：\n");
    for(i=0;i<n;i++)    //输出排序后的字符串
    {
        printf("%s\n",s[i]);
        free(s[i]);
    }
    free(*s);
    free(temp);
    system("pause");
    return 0;
}
