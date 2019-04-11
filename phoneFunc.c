/*
    Name : phoneFunc.c ver 1.0
    Content : 프로그램의 기능을 담당하는 함수들의 정의
    developer : gjcomputer

    Last Modified 2019/4/09
*/
#include "common.h"
#include "phoneData.h"
#include "screenOut.h"
#include "phoneFunc.h"

static person* plist[50];
static int perNum=0;

void clearbuf(void)
{ while(getchar()!='\n');}


void addData(void)
{
    puts("연락처 추가를 시작합니다.");
    person* buf;
    int ret;
    buf=(person*)malloc(sizeof(person));

    printf("이    름 : ");gets(buf->name);
    printf("전화번호 : ");gets(buf->pNum);
    printf("메    모 : ");gets(buf->memo);

    printf("연락처를 추가 합니다. (1. 확인, 0.취소) : ");
    scanf("%d",&ret);


    if(ret==1)
    {
        plist[perNum]=buf;
        perNum++;
        SaveData();
    }

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

void SaveData(void)
{
    int idx;
    FILE* fps=fopen("PhoneData.bin","wb");

    fwrite(&perNum,sizeof(int),1,fps);
    for(idx=0;idx<perNum;idx++)
    {
        fwrite(plist[idx],sizeof(person),1,fps);
    }
    fclose(fps);
}

void LoadData(void)
{
    int idx;

    FILE* fpr=fopen("PhoneData.bin", "rb");

    fread(&perNum,sizeof(int),1,fpr);
    for(idx=0;idx<perNum;idx++)
    {
        plist[idx]=(person*)malloc(sizeof(person));
        fread(plist[idx],sizeof(person),1,fpr);
    }
    fclose(fpr);

}
