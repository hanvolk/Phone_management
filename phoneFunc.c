/*
    Name : phoneFunc.c ver 1.0
    Content : ���α׷��� ����� ����ϴ� �Լ����� ����
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
    puts("����ó �߰��� �����մϴ�.");
    person* buf;
    int ret;
    buf=(person*)malloc(sizeof(person));

    printf("��    �� : ");gets(buf->name);
    printf("��ȭ��ȣ : ");gets(buf->pNum);
    printf("��    �� : ");gets(buf->memo);

    printf("����ó�� �߰� �մϴ�. (1. Ȯ��, 0.���) : ");
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
