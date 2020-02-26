#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char s[20]; //用于存放单词
    int count;  //用于存放本单词的个数
    struct node *next;
}Node,*Linklist;

int zimu(char *c)
/*
判断是否为字母的函数，考虑大小写的单词应该是一样的，这里之所以在形参用指针的形式是由于
要将大写字母转为小写字母，所以用指针才能保证形参的改变影响到实参
*/
{
    if(*c>='a'&&*c<='z')    //小写字母直接确认即可
    {
        return 1;
    }
    if(*c>='A'&&*c<='Z')    //大写字母时，这里考虑判断，并把大写转小写
    {
        *c=*c+32;
        return 1;
    }
    else
        return 0;
}

void binary_search(Linklist p[],int *index,Linklist newnode)    //二分查找的函数
{
    int low,high;   //二分查找的高低指针
    int mid;
    int i;
    if(*index==-1)
    {
        p[0]=newnode;   //此时直接将指针数组第0个元素指向该结点
        (*index)++;
    }
    else    //开始二分查找，指针数组应该按照字符串的大小排序（从小到大排序）
    {
        low=0;
        high=*index;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(strcmp(p[mid]->s,newnode->s)>0)
            {
                high=mid-1;
            }
            else if(strcmp(p[mid]->s,newnode->s)<0)
            {
                low=mid+1;
            }
            else if(strcmp(p[mid]->s,newnode->s)==0)
            {
                break;
            }
        }
        if(low<=high)   //如果最后low<=high，证明这个单词是存在的，把相应的字符串++
        {
            (p[mid]->count)++;  //加了之后不用再排序
            free(newnode);
            return ;
        }
        else    //否则low>high，证明该单词是不存在的，应该插入，且插入位置是low所在的位置
        {
            for(i=*index;i>=low;i--)
            {
                p[i+1]=p[i];    //后移
            }
            p[low]=newnode; //插入p[low]指向newnode
            (*index)++;
            return ;
        }
    }
}

int main()
{
    FILE *fp=fopen("data.dat","r");  //文件指针
    if(fp==NULL)
    {
        perror("fopen");
    }
    Linklist *p;    //指针数组
    int i,l,word=0; //word是单词标志
    int k;
    int index=-1;   //指针数组的下标
    Linklist newnode;   //用于申请新结点
    int count_danci=0;
    char s[1000];   //用来存放要判断的英文语句（假定语句的长度为1000）
    char str[20];   //用于存放单词
    p=(Linklist *)calloc(2000,sizeof(Linklist));
    //指针数组的头指针p，是一个二级指针（这里需要预先假设不同单词个数，本假设是2000个单词）
    int flag=0;
    while(fgets(s,13,fp)!=NULL)    //fgets读取文件的每一行，且会在每行自动赋上'\0'
    {
        if(flag!=1) //用于标记上一次读出来的最后一个单词是否读完
            word=0; //先另单词标志Word=0，如果是二次及以上读入行的开始
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(i==l&&!zimu(&s[i-1]))
                break;
            if((!zimu(&s[i])&&i-1>=0&&zimu(&s[i-1]))||(flag==1&&i>0&&!zimu(&s[i])&&zimu(&s[i-1]))||(flag==1&&i==0&&!zimu(&s[i])))//(i==l&&zimu(&s[i-1]))
            //证明单词结束了，应该加入新结点newnode
            {
                str[k]='\0';
                newnode=(Linklist)calloc(1,sizeof(Node));   //申请新结点
                newnode->count=1;   //数量为1
                strcpy(newnode->s,str); //将单词放入新结点
                binary_search(p,&index,newnode);    //进行折半查找
                if(flag==1)
                {
                    flag=0;
                    word=0; //二行及以上的开头，word在开始没有置为0
                }
            }
            if(!zimu(&s[i]))
                word=0; //不是字母，则令单词标记=0
            else if(word==0)
            //证明找到单词的开始了，我们应该考虑将单词放到某个地方，待单词结束后再放入链表中
            {
                k=0;
                word=1; //令单词标记为1
                count_danci++;
            }
            if(word==1)
            {
                str[k]=s[i];
                k++;
            }
        }
        if(zimu(&s[i-1]))
            flag=1; //标记为1，因为可能一行的最后一个单词没有读完。
    }
    printf("不同单词数index=%d\n",index+1);
    for(i=0;i<=index;i++)
    {
        printf("%s\t%d\n",p[i]->s,p[i]->count);
    }
    system("pause");
    return 0;
}
