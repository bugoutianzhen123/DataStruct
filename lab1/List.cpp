#include "SqList.cpp"

#ifndef SQListFunction

int Union(SqList *a,SqList *b){
    int i;
    for(i=0;i<b->Length;i++){
        if(LocateElemSq(a,b->Elem[i]) == 0){
            if(ListInsertSq(a,a->Length+1,b->Elem[i]) != 1){
                return 0;
            }
        }
    }
    return 1;
}

#endif // SQListFunction