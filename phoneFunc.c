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
    int ret=0, idx=0;
    buf=(person*)malloc(sizeof(person));

    printf("이    름 : ");gets(buf->name);
    printf("전화번호 : ");gets(buf->pNum);
    printf("메    모 : ");gets(buf->memo);

    for(idx=0;idx<perNum;idx++)
    {
        if(!strcmp(buf->name,plist[idx]->name) && !strcmp(buf->pNum,plist[idx]->pNum))
        {
            printf("연락처가 이미 존재합니다.");getchar();
            return;
         }
    }

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
    int idx;
    char sName[NAME_LEN];
    printf("찾는 이름 : ");gets(sName);

    for(idx=0;idx<perNum;idx++)
    {
        if(!strcmp(sName,plist[idx]->name))
                    ShowPersonData(plist[idx]);
    }

    clearbuf();
}

void delData(void)
{
    int idx=0, i=0;
    int idxMatch[50]={0,};
    char sName[NAME_LEN];
    printf("삭제 할 이름 : ");gets(sName);

    for(idx=0;idx<perNum;idx++)
    {
        if(!strcmp(sName,plist[idx]->name))
        {
            idxMatch[i]=idx;
            i++;
        }
    }

     for(idx=0;idx<i;idx++)
    {
        printf("No. %d \n",idx+1);
        ShowPersonData(plist[idxMatch[idx]]);
    }

    printf("선택 : ");scanf("%d",&idx);clearbuf();
    DelPersonData(idxMatch[idx-1]);

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

void ChangeData(void)
{
    int idx=0,i=0;
    int idxMatch[50]={0,};
    char sName[NAME_LEN];
    printf("수정 할 이름 : ");gets(sName);

    for(idx=0;idx<perNum;idx++)
    {
        if(!strcmp(sName,plist[idx]->name))
        {
            idxMatch[i]=idx;
            i++;
        }
    }

    for(idx=0;idx<i;idx++)
    {
        printf("No. %d \n",idx+1);
        ShowPersonData(plist[idxMatch[idx]]);
    }


    printf("선택 : ");scanf("%d",&idx);clearbuf();
    changePersonData(idxMatch[idx-1]);
}

void changePersonData(int idx)
{

    person* buf;
    int ret=0, i=0;
    buf=(person*)malloc(sizeof(person));

    printf("이    름 : ");gets(buf->name);
    printf("전화번호 : ");gets(buf->pNum);
    printf("메    모 : ");gets(buf->memo);

    for(i=0;i<perNum;i++)
    {
        if(!strcmp(buf->name,plist[i]->name) && !strcmp(buf->pNum,plist[i]->pNum))
        {
            printf("연락처가 이미 존재합니다.");getchar();
            return;
         }
    }
    printf("연락처를 변경 합니다. (1. 확인, 0.취소) : ");
    scanf("%d",&ret);

    if(ret==1)
    {
        free(plist[idx]);
        plist[idx]=buf;
        SaveData();
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

void DelPersonData(int idx)
{
    free(plist[idx]);

    while(idx<perNum)
    {
        plist[idx]=plist[idx+1];
        idx++;
    }

    perNum--;
    SaveData();
    puts("삭제가 완료 되었습니다.");
}

void ExitProgram(void)
{
    int idx=0;
    printf("프로그램을 종료 합니다.\n");
    for(idx=0;idx<perNum;idx++)
    {
        free(plist[idx]);
    }
}
