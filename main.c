#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum {ADD=1, SEARCH=2, DEL=3, SHOWALL=4, CHANGE=5, END=0};

int main()
{
    int sw;
    LoadData();

    sw=ShowMenu();
    while(1)
    {
        switch(sw)
        {
        case ADD:
            addData(); break;
        case SEARCH:
            searchData(); break;
        case DEL:
             delData(); break;
        case SHOWALL:
            ShowAllData(); break;
        case CHANGE:
            ChangeData();break;
        case END:
            ExitProgram();goto loopOut;
        }
        sw=ShowMenu();
    }
    loopOut:

    return 0;
}
