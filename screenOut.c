/*
    Name : screenOut.h ver 1.0
    Content : ȭ�� ����� ���� �Լ����� ����
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
    puts("1. �� �� ó �� ��  ");
    puts("2. ��          �� ");
    puts("3. ��          �� ");
    puts("4. ��  ü   �� ��  ");
    puts("-------------------------");
    printf("���� : ");scanf("%d",&n);
    clearbuf();
    return n;

}

void ShowPersonData(const person* ref)
{
    printf("��������������������������������������������������������������\n");
    printf("�� �� ��    �� : %s \n",ref->name);
    printf("�� �� ��ȭ��ȣ : %s \n",ref->pNum);
    printf("�� �� ��    �� : %s \n",ref->memo);
    printf("������������������������������������������������������������\n");
}
