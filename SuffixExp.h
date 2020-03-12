#ifndef SUFFIXEXP_H
#define SUFFIXEXP_H
#include "comhead.h"

#define MaxOp 7

//infix expression to sufix expression
struct{
    char ch;
    int pri;
}lpri[] = {{'=',0},{'(',1},{'+',3},{'-',3},{'*',5},{'/',5},{')',6}},
 rpri[] = {{'=',0},{'(',6},{'+',2},{'-',2},{'*',4},{'/',4},{')',1}};

int leftpri(char op){
    int i;
    for (i = 0;i < MaxOp; i++)
        if (lpri[i].ch == op)
            return lpri[i].pri;
    cout<<"error"<<endl;
    return -2;
}

int rightpri(char op){
    int i;
    for (i = 0;i < MaxOp; i++)
        if (rpri[i].ch == op)
            return rpri[i].pri;
    cout<<"error"<<endl;
    return -2;
}

int IsOp(char ch){
    if (ch == '(' || ch == ')' || ch == '+' ||
            ch == '-' || ch == '*' || ch == '/')
        return true;
    else
        return false;
}

int Precede(char lop, char rop){
    if (leftpri(lop) == rightpri(rop))
        return 0;
    else if (leftpri(lop) < rightpri(rop))
        return -1;
    else
        return 1;
}

void trans(char* exp,char postexp[]){
    struct
    {
        char data[MaxSize];
        int top;
    }op;
    int i = 0;
    op.top = -1;
    op.top++;
    op.data[op.top] = '=';
    while (*exp != '\0'){
        if (!IsOp(*exp)){
            while (*exp >= '0' && *exp <= '9'){
                postexp[i++] = *exp;
                exp++;
            }
            postexp[i++] = '#';
        }
        else
            switch (Precede(op.data[op.top], *exp)){
            case -1:
                op.top++;
                op.data[op.top] = *exp;
                exp++;
                break;
            case 0:
                op.top--;
                exp++;
                break;
            case 1:
                postexp[i++] = op.data[op.top];
                op.top--;
                break;
            }
    }
    while (op.data[op.top] != '='){
        postexp[i++] = op.data[op.top];
        op.top--;
    }
    postexp[i] = '\0';
}


#endif // SUFFIXEXP_H
