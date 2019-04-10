/*
    Name : screenOut.h ver 1.0
    Content : 화면 출력을 위한 함수들의 정의
    developer : gjcomputer

    Last Modified 2019/4/09
*/
#include "common.h"
#include "screenOut.h"

int ShowMenu(void)
{
    system("cls");
    int n;
    puts("--------  Menu ---------");
    puts("1. 연 락 처 추 가  ");
    puts("2. 검          색 ");
    puts("3. 삭          제 ");
    puts("4. 전  체   목 록  ");
    puts("-------------------------");
    printf("선택 : ");scanf("%d",&n);
    clearbuf();
    return n;

}

void ShowAllData(void)
{
    puts("전체 연락처를 출력 합니다.");
    clearbuf();
}
