#include "LiStack.h"

void init_listack(LiStack* &s){
    s = (LiStack*)malloc(sizeof(LiStack));
    s->next = NULL;
}

void destroy_listack(LiStack* &s){
    LiStack*pre, *p;
    pre = s;
    p = s->next;
    while(p != NULL){
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}

bool listack_is_empty(LiStack* s){
    return s->next == NULL;
}

void display_listack(LiStack* s){
    LiStack* p = s->next;

    while (p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void push_listack(LiStack*& s,int e){
    LiStack* p = (LiStack*)malloc(sizeof(LiStack));
    p->data = e;
    p->next = s->next;
    s->next = p;
}

bool pop_listack(LiStack*& s,int &e){
    if (s->next == NULL)
        return false;
    LiStack* p;
    p = s->next;
    e = p->data;
    s->next = p->next;
    free(p);
    return true;
}

bool get_listack_top(LiStack* s,int &e){
    if (s->next == NULL)
        return false;
    e = s->next->data;
    return true;
}
