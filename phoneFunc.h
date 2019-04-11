/*
    Name : phoneFunc.h ver 1.0
    Content : 프로그램의 기능을 담당하는 함수들의 선언
    developer : gjcomputer

    Last Modified 2019/4/09
*/

#ifndef __PHONEFUNC_H__
#define __PHONEFUNC_H__
#include "phoneData.h"

void addData(void);
void searchData(void);
void delData(void);
void ShowAllData(void);

void clearbuf(void)
{ while(getchar()!='\n');}

#endif // __PHONEFUNC_H__
