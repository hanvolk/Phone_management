/*
    Name : phoneFunc.c ver 1.0
    Content : 프로그램의 기능을 담당하는 함수들의 정의
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
    puts("연락처 추가를 시작합니다.");
    plist[perNum]=(person*)malloc(sizeof(person));
    printf("이    름 : ");gets(plist[perNum]->name);
    printf("전화번호 : ");gets(plist[perNum]->pNum);
    printf("메    모 : ");gets(plist[perNum]->memo);
    perNum++;
    clearbuf();
}

void searchData(void)
{
    puts("연락처 검색을 시작합니다.");
    clearbuf();
}

void delData(void)
{
    puts("연락처를 삭제 합니다.");
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
