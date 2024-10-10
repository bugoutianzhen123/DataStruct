// # include <stdio.h>
// # include <malloc.h>
// # include <stdlib.h>
// #include <process.h>
// #include<iostream>
#include <bits/stdc++.h>

#ifndef HEAD_H
#define HEAD_H


using namespace std;

const int ListInitSize = 100;
const int ListIncrement = 10; 

const bool Ok = 1;
const bool False = 0;

typedef int ElemType;

typedef  struct List{
	ElemType *Elem;
	int Length;
	int ListSize;
	int IncrementSize;
}SqList;

void Increment(SqList *L);
void InitListSq(SqList *L,int l = ListInitSize);
void DestroyListSq(SqList *L);
int ClearEmpty(SqList *L);
int LocateElemSq(SqList *L,ElemType e);
int ListInsertSq(SqList *L,int i,ElemType e);
void ListDeleteSq(SqList *L,int i,ElemType *e);
int ListEmpty(SqList L);
int ListLength(SqList L);
void GetElem(SqList L,int i,ElemType *e);
void PriorElem(SqList *L,ElemType cur_e,ElemType *pre_e);
void NextElem(SqList *L,ElemType cur_e,ElemType *next_e);
void ListTraverse(SqList L);
int Union(SqList *a,SqList *b);

#endif
