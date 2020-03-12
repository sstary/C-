#ifndef SQLIST_H
#define SQLIST_H
#include "comhead.h"

typedef struct SqNode{
    int data[MaxSize];
    int length;
}SqList;

//basic function
void creat_sqlist(SqList* &L, int a[], int n);
void init_sqlist(SqList* &L);
void destory_sqlist(SqList* &L);
bool sqlist_is_empty(SqList* L);
int sqlist_length(SqList* L);
void disply_sqlist(SqList* L);
bool get_sqlist_elem(SqList* L, int n, int &e);
int locate_sqlist_elem(SqList* L, int e);
bool sqlist_insert(SqList* &L, int n, int e);
bool sqlist_delete(SqList* &L, int n, int &e);

//primary algorithm

//small->first item->big
void small_to_big(SqList* &L);

#endif // SQLIST_H
