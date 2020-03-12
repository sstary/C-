#ifndef GTABLE_H
#define GTABLE_H
#include "comhead.h"

typedef struct gtnode
{
    int tag;
    union{
        int data;
        struct gtnode* sublist;
    }val;
    struct gtnode* link;
}GTNode;

GTNode* gt_create(char* &s){
    GTNode* g;
    char ch = *s++;
    if (ch != '\0'){
        g = (GTNode*)malloc(sizeof(GTNode));
        if (ch == '('){
            g->tag = 1;
            g->val.sublist = gt_create(s);
        }
        else if (ch == ')')
            g = NULL;
        else if (ch == '#')
            g = NULL;
        else{
            g->tag = 0;
            g->val.data = ch;
        }
    }
    else
        g = NULL;
    ch = *s++;
    if (g != NULL){
        if (ch == ',')
            g->link = gt_create(s);
        else
            g->link = NULL;
    }
    return g;
}

int gt_depth(GTNode* g){
    GTNode* gt;
    int max = 0,dep;
    if (g->tag == 0)
        return 0;
    gt = g->val.sublist;
    if (gt == NULL)
        return 1;
    while (gt != NULL){
        if (gt->tag == 1){
            dep = gt_depth(gt);
            if (dep > max)
                max = dep;
        }
        gt = gt->link;
    }
    return max+1;
}

void gt_display(GTNode* g){
    if (g != NULL){
        if (g->tag == 0)
            cout.put(g->val.data);
        else{
            cout.put('(');
            if (g->val.sublist == NULL)
                cout.put('#');
            else
                gt_display(g->val.sublist);
            cout.put(')');
        }
        if (g->link != NULL){
            cout.put(',');
            gt_display(g->link);
        }
    }
}














#endif // GTABLE_H
