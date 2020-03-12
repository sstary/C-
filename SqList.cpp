#include "SqList.h"

void creat_sqlist(SqList* &L, int a[], int n)
{
    int i;
    L = (SqList *)malloc(sizeof(SqList));
    for (i = 0; i < n; i++){
        L->data[i] = a[i];
    }
    L->length = n;
}

void init_sqlist(SqList* &L){
    L = (SqList *)malloc(sizeof(SqList));
    L->length = 0;
}

void destory_sqlist(SqList* &L){
    free(L);
}

bool sqlist_is_empty(SqList* L){
    return L->length == 0;
}

int sqlist_length(SqList* L){
    return L->length;
}

void disply_sqlist(SqList* L){
    int len = L->length;
    for (int i = 0; i < len; i++ ){
        cout<<L->data[i]<<" ";
    }
    cout<<endl;
}

//n is logical location
bool get_sqlist_elem(SqList* L, int n, int &e){
    if (n < 1 || n > L->length)
        return false;
    e = L->data[n-1];
    return true;
}

int locate_sqlist_elem(SqList* L, int e){
//    add exception handling
//    int n,len = L->length;
//    for (int i = 0; i < len; i++ ){
//        if (e == L->data[i])
//            n = i+1;
//    }
//    return n;
    int i = 0;
    while(i < L->length && e != L->data[i])
        i++;
    if (i >= L->length)
        return 0;
    else
        return i++;
}

bool sqlist_insert(SqList* &L, int n, int e){
    int k;
    if (n < 1 || n > L->length)
        return false;
    n--;
    for( k = L->length; k > n; k--){
        L->data[k] = L->data[k-1];
    }
    L->data[k] = e;
    L->length++;
    return true;
}

bool sqlist_delete(SqList* &L, int n, int &e){
    int k;
    if (n < 1 || n > L->length)
        return false;
    n--;
    e = L->data[n];
    for( k = n; k < L->length-1; k++){
        L->data[k] = L->data[k+1];
    }
    L->length--;
    return true;
}

void small_to_big(SqList* &L){
    int mid = L->data[0];
    int tmp;
    int i = 0,j = L->length-1;
    while (i < j){
        while (i < j && L->data[j] > mid)
            j--;
        while (i < j && L->data[i] <= mid)
            i++;
        if (i < j){
            tmp = L->data[i];
            L->data[i]=L->data[j];
            L->data[j]=tmp;
        }
    }
    tmp = L->data[i];
    L->data[i] = mid;
    L->data[0] = tmp;
}
