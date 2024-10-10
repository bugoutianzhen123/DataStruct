#include "List.cpp"
//#include "head.h"
using namespace std;

int main(){
    SqList L1,L2;
    InitListSq(&L1);
    InitListSq(&L2);
    ListInsertSq(&L1,1,12);
    ListInsertSq(&L1,2,25);
    ListInsertSq(&L1,3,78);
    ListInsertSq(&L1,4,99);
    ListInsertSq(&L1,5,5);

    ListInsertSq(&L2,1,5);
    ListInsertSq(&L2,1,7);
    ListInsertSq(&L2,1,57);
    ListInsertSq(&L2,1,24);
    ListInsertSq(&L2,1,99);

    ListTraverse(L1);
    ListTraverse(L2);

    Union(&L1,&L2);

    ListTraverse(L1);
    return 0;
}