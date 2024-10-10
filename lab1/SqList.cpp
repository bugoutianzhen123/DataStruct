#include"head.h"
// #ifndef SQListFunction
// #define SQListFunction

using namespace std;

void Increment(SqList *L){
	int i;
	ElemType *a;
	a = new ElemType [L->ListSize + L->IncrementSize];
	for(i = 0; i <L->Length; i++)a[i]=L->Elem[i];
	delete[] L->Elem;
	L->Elem=a;
	L->ListSize += L->IncrementSize;
}


class SqList
{
private:
    /* data */
public:
    SqList(/* args */);
    ~SqList();
};

SqList::SqList(/* args */)
{
}

SqList::~SqList()
{
}


//初始化
void InitListSq(SqList *L,int l){
	L->Elem = new ElemType[l];
	L->Length = 0;
	L->ListSize = ListIncrement;
} 

//销毁表
void DestroyListSq(SqList *L){
	delete[] L->Elem;
    L->Length = 0;
    L->ListSize = 0;
} 

//清空表
int ClearEmpty(SqList *L){
   DestroyListSq(L);
   InitListSq(L);
   return 0;
} 

// 检索值为e的元素
int LocateElemSq(SqList *L,ElemType e){
	int i = 1;
	ElemType *p = L->Elem;
	while(i <= L->Length && *p++ != e) ++ i;
	if (i <= L->Length) return i;
	else return 0;
} 

//插入元素到目标位置
int ListInsertSq(SqList *L,int i,ElemType e){
 ElemType *q,*p;
if (i<1 || i > L->Length +1 ){
	//ErrorMessage("非法输入");
    return 0;
	}
if(L->Length >= L->ListSize) Increment(L);
  q = &(L->Elem[i-1]);
  for (p = &(L->Elem[L->Length-1]);p>=q;--p )  *(p+1) = *p;
  *q = e;
  ++L->Length;
  return 1;
}

//删除第i个元素
void ListDeleteSq(SqList *L,int i,ElemType *e){
	if (i<1 || i > L->Length +1 ){
	//ErrorMessage("非法输入");
	}
	*e = L->Elem[i-1];
	for (int j = i; j < L->Length; ++j)
    {
        L->Elem[j - 1] = L->Elem[j];
    }
    L->Length--;
} 


//判断是否为空表
int ListEmpty(SqList L){
	return (L.Length == 0);
} 

//返回长度
int ListLength(SqList L){
	return L.Length;
} 

//获取第i个元素
void GetElem(SqList L,int i,ElemType *e){
	if (i >= 1 && i <= L.Length)
    {
        *e = L.Elem[i - 1];
    }
	
} 
// 获取cur_e的直接前驱元素
void PriorElem(SqList *L,ElemType cur_e,ElemType *pre_e){
	int cur_e_location = LocateElemSq(L, cur_e);
    if (cur_e_location != 1)
    {
        *pre_e = L->Elem[cur_e_location - 2];
        return;
    }
    else
    {
		//ErrorMessage("无目标元素");
        return;
    }
}

// 获取cur_e的直接后驱元素
void NextElem(SqList *L,ElemType cur_e,ElemType *next_e){
	 int cur_e_location = LocateElemSq(L, cur_e);
    if (cur_e_location != L->Length)
    {
         *next_e = L->Elem[cur_e_location];
		 return ;
    }
    else
    {
		//ErrorMessage("无目标元素");
        return ;
    }
}

//输出元素
void ListTraverse(SqList L){
     for (int i = 0; i < L.Length; ++i)
    {
        cout << L.Elem[i]<< " ";
    }
    cout << endl;
}




//#endif // SQListFunction