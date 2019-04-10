/*
    Name : phonData.h ver 1.0
    Content : 연락처의 정보를 담은 구조체의 선언 및 정의
    developer : gjcomputer

    Last Modified 2019/4/09
*/

#ifndef __PHONEDATA_H__
#define __PHONEDATA_H__

#define NAME_LEN 10
#define PHONE_LEN 15
#define MEMO_LEN 50


typedef struct __person{
    char name[NAME_LEN];
    char pNum[PHONE_LEN];
    char memo[MEMO_LEN];
}person;

#endif // __PHONEDATA_H__
