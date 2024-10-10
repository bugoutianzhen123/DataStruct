#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef struct Student
{
    char no[9];
    char name[11];
    int score;
    int time;
} STUDENT;

typedef struct DulNode
{
    STUDENT Stu;
    int i;
    DulNode *prior, *next;
} DulNode, *DulLinkList;

