/*
    Name : phoneFunc.c ver 1.0
    Content : ���α׷��� ����� ����ϴ� �Լ����� ����
    developer : gjcomputer

    Last Modified 2019/4/09
*/
#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

static person* plist[50];
static int perNum=0;

void addData(void)
{
    puts("����ó �߰��� �����մϴ�.");
    plist[perNum]=(person*)malloc(sizeof(person));
    printf("��    �� : ");gets(plist[perNum]->name);
    printf("��ȭ��ȣ : ");gets(plist[perNum]->pNum);
    printf("��    �� : ");gets(plist[perNum]->memo);
    perNum++;
    clearbuf();
}

void searchData(void)
{
    puts("����ó �˻��� �����մϴ�.");
    clearbuf();
}

void delData(void)
{
    puts("����ó�� ���� �մϴ�.");
    clearbuf();
}

void ShowAllData(void)
{
    int idx;
    for(idx=0;idx<perNum;idx++)
    {
        ShowPersonData(plist[idx]);
    }
    clearbuf();
}
