#ifndef SQSTRING_H
#define SQSTRING_H
#include "comhead.h"

typedef struct{
    char data[MaxSize];
    int length;
}SqString;

void init_sqstring(SqString &s,char cstr[]);
int BF(SqString s, SqString t);

void get_next(SqString t,int next[]);
void get_next_opti(SqString t, int next[]);
int KMP(SqString s, SqString t);

#endif // SQSTRING_H
