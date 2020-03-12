#ifndef LISTACK_H
#define LISTACK_H
#include "comhead.h"

typedef struct LiNode{
    int data;
    struct LiNode* next;
}LiStack;

void init_listack(LiStack* &s);
void destroy_listack(LiStack* &s);
bool listack_is_empty(LiStack* s);
void display_listack(LiStack* s);
void push_listack(LiStack* &s,int e);
bool pop_listack(LiStack* &s,int &e);
bool get_listack_top(LiStack* s,int &e);

#endif // LISTACK_H
