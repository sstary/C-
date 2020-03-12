#include "SqString.h"

void init_sqstring(SqString &s,char cstr[]){
    int i = 0;
    for (; cstr[i] != '\0'; i++)
        s.data[i] = cstr[i];
    s.length = i;
}

int BF(SqString s,SqString t){
    int i = 0, j = 0;
    while (i < s.length && j < t.length){
        if (s.data[i] == t.data[j])
        {
            i++;
            j++;
        }
        else{
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= t.length)
        return (i - t.length);
    else
        return -1;
}

void get_next(SqString t,int next[]){
    int j = 0,k = -1;
    next[0] = -1;
    while (j < t.length -1){
        if (k == -1 || t.data[j] == t.data[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
            k = next[k];
    }
}

void get_next_opti(SqString t,int next[]){
    int j = 0,k = -1;
    next[0] = -1;
    while (j < t.length){
        if (k == -1 || t.data[j] == t.data[k])
        {
            j++;
            k++;
            if (t.data[j] != t.data[k])
                next[j] = k;
            else
                next[j] = next[k];
        }
        else
            k = next[k];
    }
}

int KMP(SqString s, SqString t){
    int next[MaxSize],i = 0,j = 0;
    get_next_opti(t, next);
    while ( i < s.length && j < t.length){
        if ( j == -1 || s.data[i] == t.data[j]){
            i++;
            j++;
        }
        else j = next[j];
    }
    if (j >= t.length)
        return i-t.length;
    else
        return -1;
}















