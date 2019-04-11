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
    int ret=0, idx=0;
    buf=(person*)malloc(sizeof(person));

    printf("��    �� : ");gets(buf->name);
    printf("��ȭ��ȣ : ");gets(buf->pNum);
    printf("��    �� : ");gets(buf->memo);

    for(idx=0;idx<perNum;idx++)
    {
        if(!strcmp(buf->name,plist[idx]->name) && !strcmp(buf->pNum,plist[idx]->pNum))
        {
            printf("����ó�� �̹� �����մϴ�.");getchar();
            return;
         }
    }

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
    int idx;
    char sName[NAME_LEN];
    printf("ã�� �̸� : ");gets(sName);

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
    printf("���� �� �̸� : ");gets(sName);

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

    printf("���� : ");scanf("%d",&idx);clearbuf();
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
    printf("���� �� �̸� : ");gets(sName);

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


    printf("���� : ");scanf("%d",&idx);clearbuf();
    changePersonData(idxMatch[idx-1]);
}

void changePersonData(int idx)
{

    person* buf;
    int ret=0, i=0;
    buf=(person*)malloc(sizeof(person));

    printf("��    �� : ");gets(buf->name);
    printf("��ȭ��ȣ : ");gets(buf->pNum);
    printf("��    �� : ");gets(buf->memo);

    for(i=0;i<perNum;i++)
    {
        if(!strcmp(buf->name,plist[i]->name) && !strcmp(buf->pNum,plist[i]->pNum))
        {
            printf("����ó�� �̹� �����մϴ�.");getchar();
            return;
         }
    }
    printf("����ó�� ���� �մϴ�. (1. Ȯ��, 0.���) : ");
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
    puts("������ �Ϸ� �Ǿ����ϴ�.");
}

void ExitProgram(void)
{
    int idx=0;
    printf("���α׷��� ���� �մϴ�.\n");
    for(idx=0;idx<perNum;idx++)
    {
        free(plist[idx]);
    }
}
