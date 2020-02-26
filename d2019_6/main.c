#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char s[20]; //存取每个单词，假定单词长度不超过20
    struct Node *next;
}Node,*Linklist;

//尾插法创建带头结点的单链表，每个结点用于存储字符串
Linklist CreateLinklist()
{
    FILE *fp=fopen("data.dat","r"); //文件指针
    if(fp==NULL)
    {
        perror("fopen");
    }
    char s[20]; //用于暂存从文件读入的单词
    Linklist head=(Linklist)malloc(sizeof(Node));   //头结点
    strcpy(head->s,"\0");   //头结点的字符数组为空
    head->next=NULL;
    Linklist tail=head; //用于尾插法的尾指针，始终指向尾结点
    //循环读取文件的每一行
    while(fgets(s,19,fp)!=NULL) //fgets读取文件的每一行（因为换行了，所以会有换行符'\n')
    //且会在每行自动附上'\0'
    //去掉读入的换行符'\n',替换为空格
    {
        if(s[strlen(s)-1]=='\n')
        {
            s[strlen(s)-1]=' ';
        }
        Linklist newNode=(Linklist)malloc(sizeof(Node));
        strcpy(newNode->s,s);
        newNode->next=NULL;
        tail->next=newNode;
        tail=newNode;
    }
    return head;
}

//遍历链表，读取出所有的字符串，然后使用模式匹配算法查找子串
void TravelAndSearch(Linklist head)
{
    char s[100];    //存储需要查找的子串
    int i,j;
    char string[1000]={'\0'};   //用于存储所有单词的数组
    int l1,l2;
    int danci_position; //确定子串所在的第几个单词
    int start_position; //确定单词内的开始位置
    printf("请输入待查找的子串s：\n");
    gets(s);
    Linklist p=head->next;  //遍历指针p
    while(p!=NULL)
    {
        strcat(string,p->s);
        p=p->next;
    }
    /*
    使用字符串的模式匹配算法来查找子串，采用循环暴力的算法
    */
    l1=strlen(string);
    l2=strlen(s);
    i=0;
    j=0;
    danci_position=1;   //初始时是在第一个单词
    start_position=1;   //初始时在单词的第一个位置
    //最好自己写两个字符手动模拟，加深理解。
    while(i<l1&&j<l2)
    {
        if(string[i]==' ')  //如果为空格，则表明遇到了两个单词之间的间隔
        {
            i++;    //i+1，向后移动到下一个单词，j不变
            if(j==0)
            //j==0表明前面进行的比较不匹配，需要从下一个单词重新开始比较，此时单词计数需要+1
            {
                danci_position++;
                start_position=1;
            }
        }
        if(string[i]==s[j]) //若相等，则继续比下去
        {
            i++;
            j++;
        }
        else
        {
            i=i-j+1;    //若不相等，则只能回溯指针i,j。j回到0重新开始比，i
            //回到i-j+1，即上一次的后一个位置，记住这个公式
            j=0;
            start_position++;   //因为不相等，因此单词内部的起始位置需要增加
        }
    }
    if(j==l2)   //如果j走到了最后面，则表明子串比较完了，这个子串必然在公式中
        printf("子串匹配成功，%s在%s的第%d个单词的第%d个字符开始\n",s,string,danci_position,start_position);
    else
        printf("%s中没有子串%s\n",string,s);
    printf("\n");
    return;
}

int main()
{
    Linklist head=CreateLinklist();
    TravelAndSearch(head);
    system("pause");
    return 0;
}
