#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char password[7];   //���6λ���룬���һλ���ַ���������'\0'

//�������һ����λ�������룬�����ַ�ָ��
void rand_six_password()
{
    //���ڱ���ͬʱ����Сд��ĸ����д��ĸ�����֣������Ҫ���ȷ��Сд��ĸ����д��ĸ�����ֵĸ���
    int lowerCaseNo=0;
    int upperCaseNo=0;
    int digitsNo=0;
    int count=0;
    int select=0;   //����ѡ������Сд��ĸ����д��ĸ������
    char selectLower,selectUpper,selectDigit;
    srand((unsigned)time(NULL));    //�����������
    lowerCaseNo=rand()%4+1; //����һ��1-4������������ֻ��4������ΪСд��ĸ����д��ĸ������
    //�������ٸ���һ����
    upperCaseNo=rand()%(5-lowerCaseNo)+1;   //������ɴ�д��ĸ�ĸ�����5-lowerCaseNo��Ϊ��
    //��֤������һλ���֣�
    digitsNo=6-lowerCaseNo-upperCaseNo; //���ֵĸ���

    while(count<6)  //ѭ������6λ����
    {
        select=rand()%3+1;  //���ѡ��������Ǵ�д��ĸ��Сд��ĸ����������
        switch(select)
        {
        case 1: //Сд��ĸ
            if(lowerCaseNo==0)
                continue;
            selectLower=(char)((rand()%26)+'a');    //�������Сд��û��
            printf("%c",selectLower);
            password[count]=selectLower;
            lowerCaseNo--;
            count++;
            break;
        case 2: //��д��ĸ
            if(upperCaseNo==0)
                continue;
            selectUpper=(char)((rand()%26)+'A');    //������ɴ�д��ĸ
            printf("%c",selectUpper);
            password[count]=selectUpper;
            upperCaseNo--;
            count++;
            break;
        case 3: //����
            if(digitsNo==0)
                continue;
            selectDigit=(char)((rand()%9)+'0'); //������ɴ�д��ĸ
            printf("%c",selectDigit);
            password[count]=selectDigit;
            digitsNo--;
            count++;
            break;
        }
    }
    password[6]='\0';
    printf("\n");
}

int main()
{
    rand_six_password();
    int i;
    for(i=0;i<6;i++)
    {
        printf("%c",password[i]);
    }
    printf("\n");
    return 0;
}
