#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum {ADD=1, SEARCH=2, DEL=3, SHOWALL=4, END=0};


int main()
{
    int sw;
    sw=ShowMenu();
    while(sw!=END)
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
        }
        sw=ShowMenu();
    }
    return 0;
}
