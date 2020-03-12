#ifndef LNODE_H
#define LNODE_H
#include "comhead.h"

typedef struct LNode{
    int data;
    struct LNode* next;
}LList;

typedef struct DNode{
    int data;
    struct DNode* next;
    struct DNode* prev;
}DLList;

//LList
void create_llist_F(LList* &L, int a[], int n);
void create_llist_R(LList* &L, int a[], int n);
void init_llist(LList* &L);
void destroy_llist(LList* &L);
bool llist_is_empty(LList* L);
int llist_length(LList* L);
void display_llist(LList* L);
bool get_llist_elem(LList* L, int n, int &e);
int locate_llist_elem(LList* L, int e);
bool llist_insert(LList* &L, int n, int e);
bool llist_delete(LList* &L, int n, int &e);

void increase_order(LList* &L);
void three_list_union(LList* &La, LList *&Lb, LList *&Lc);

//DLList
void create_dllist_R(DLList* &L, int a[], int n);
void display_dllist(DLList* L);
void destroy_dllist(DLList* &L);

void increase_order_dllist(DLList* &L);

//LoopLListQueue
void init_llist_queue(LList* &rear);
void in_queue(LList* &rear, int e);
bool out_queue(LList* &rear, int &e);

#endif // LNODE_H








