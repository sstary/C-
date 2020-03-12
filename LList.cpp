#include "LList.h"

//current node is the basis of inserting to head or tail,
//not head node
void create_llist_F(LList* &L, int a[], int n){
    LList* s;

    //malloc need initialise
    L = (LList*)malloc(sizeof(LList));
    L->next = NULL;

    int i = 0;
    for (;i < n; i++){
        s = (LList*)malloc(sizeof(LList));
        s->data = a[n-1-i];
        s->next = L->next;
        L->next = s;
    }
}

void create_llist_R(LList* &L, int a[], int n){
    LList* s,* tmpL;

    L = (LList*)malloc(sizeof(LList));
    tmpL = L;

    int i = 0;
    for (;i < n; i++){
        s = (LList*)malloc(sizeof(LList));
        s->data = a[i];
        tmpL->next = s;
        tmpL = s;
    }
    tmpL->next = NULL;
}

void init_llist(LList* &L){
    L = (LList*)malloc(sizeof(LList));
    L->next = NULL;
}

void destroy_llist(LList* &L){
    LList* pre = L;
    LList* p = L->next;
    while (p != NULL){
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}

bool llist_is_empty(LList* L){
    return (L->next == NULL);
}

int llist_length(LList* L){
    int i = 0;
    LList* p = L->next;
    while (p != NULL){
        i++;
        p = p->next;
    }
    return i;
}

void display_llist(LList* L){    LList* p = L->next;

                                 while (p != NULL){
                                     cout<<p->data<<" ";
                                     p = p->next;
                                 }
                                 cout<<endl;

}

bool get_llist_elem(LList* L, int n, int &e){
    int i = 1;
    LList* p = L->next;
    while(i < n && p != NULL){
        p = p->next;
        i++;
    }
    if (p == NULL){
        cout<<"out of range"<<endl;
        return false;
    }else if (i == n){
        cout<<"already found it"<<endl;
        e = p->data;
        return true;
    }else{
        cout<<"need positive integer"<<endl;
        return false;
    }
}

int locate_llist_elem(LList* L, int e){
    int i = 1;
    LList* p = L->next;
    //when no match, p=null,cause p->data visit out of range,
    //so p!=NULL must be judged firstly
    while (p != NULL && p->data != e){
        p = p->next;
        i++;
    }
    if (p == NULL){
        cout<<"on match found"<<endl;
        return 0;
    }
    else{
        cout<<"match at "<<i+1<<endl;
        return i+1;
    }
}

bool llist_insert(LList* &L, int n, int e){
    int i = 0;
    LList* p = L,* s;
    while (i < n-1 && p != NULL){
        p = p->next;
        i++;
    }
    if (p == NULL){
        cout<<"insert out of range"<<endl;
        return false;
    }
    else {
        s = (LList*)malloc(sizeof(LList));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }
}

//in LList, when delete a node, must find its pre node
bool llist_delete(LList* &L, int n, int &e){
    int i = 0;
    LList* p = L,* s;
    while (i < n-1 && p != NULL){
        p = p->next;
        i++;
    }
    if (p == NULL){
        cout<<"insert out of range"<<endl;
        return false;
    }
    else {
        s = p->next;
        if (s == NULL){
            cout<<"insert out of range"<<endl;
            return false;
        }
        e = s->data;
        p->next = s->next;
        free(s);
        cout<<"delete successful"<<endl;
        return true;
    }
}

//direct insert sort, insert one item at every loop
/* 2
 * 1  2
 * 1  2  5
 * 1  2  4  5
 * 1  2  4  5  6  */
void increase_order(LList* &L){
    LList* p,* q,* pre;
    p = L->next->next;
    L->next->next = NULL;
    while (p != NULL){
        q = p->next;
        pre = L;
        while (pre->next != NULL && pre->next->data < p->data)
            pre = pre->next;
        p->next = pre->next;
        pre->next = p;
        p = q;
    }
}

void three_list_union(LList* &La, LList* &Lb, LList* &Lc){
    LList* pa,* pb,* pc,* s,* p;
    int flag = 0;
    pa = La->next;
    pb = Lb->next;
    pc = Lc->next;
    La->next = NULL;
    s = La;
    while (pa != NULL){
        p = pa;
        while (pb != NULL){
            if (pb->data < pa->data){
                flag = 1;
                p = pb;
                if (p->next != NULL){
                    if (pb->data == pb->next->data){
                        p = pb->next;
                        pb = pb->next;
                        continue;
                    }
                }
                break;
            }
            if (pb->data == pa->data){
                pb = pb->next;
                continue;
            }
            break;
        }
        while (pc != NULL){
            if (pc->data < p->data) {
                flag = 2;
                p = pc;
                if (pc->next != NULL){
                    if (pc->data == pc->next->data){
                        p = pc->next;
                        pc = pc->next;
                        continue;
                    }
                }
                break;
            }
            if (pc->data == p->data){
                pc = pc->next;
                continue;
            }
            break;
        }
        if (flag == 1){
            flag = 0;
            if (pb != NULL)
                pb = pb->next;
        }
        else if (flag == 2){
            flag = 0;
            if (pc != NULL)
                pc = pc->next;
        }else{
            if (pa->next != NULL){
                if (pa->data == pa->next->data){
                    p = pa->next;
                    pa = pa->next;
                    continue;
                }
            }
            pa = pa->next;
        }
        p->next = s->next;
        s->next = p;
        s = p;
    }
    while (pb != NULL && pc != NULL){
        p = pb;
        while (pc != NULL){
            if (pc->data < pb->data){
                flag = 1;
                p = pc;
                if (pa->next != NULL){
                    if (pc->data == pc->next->data){
                        p = pc->next;
                        pc = pc->next;
                        continue;
                    }
                }
                break;
            }
            if (pc->data == pb->data){
                pc = pc->next;
                continue;
            }
            break;
        }
        if (flag == 1){
            flag = 0;
            if (pc != NULL)
                pc = pc->next;
        }else{
            if (pb != NULL)
                pb = pb->next;
        }
        p->next = s->next;
        s->next = p;
        s = p;
    }
    while (pb != NULL){
        p = pb;
        pb = pb->next;
        p->next = s->next;
        s->next = p;
        s = p;
    }
    while (pc != NULL){
        p = pc;
        pc = pc->next;
        p->next = s->next;
        s->next = p;
        s = p;
    }
}

//DLList
void create_dllist_R(DLList* &L, int a[], int n){
    DLList* s,* tmpL;

    L = (DLList*)malloc(sizeof(DLList));
    tmpL = L;

    int i = 0;
    for (;i < n; i++){
        s = (DLList*)malloc(sizeof(DLList));
        s->data = a[i];
        tmpL->next = s;
        s->prev = tmpL;
        tmpL = s;
    }
    tmpL->next = NULL;
}

void display_dllist(DLList* L){
    DLList* p = L->next;

    while (p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void destroy_dllist(DLList* &L){
    DLList* pre = L;
    DLList* p = L->next;
    while (p != NULL){
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}

void increase_order_dllist(DLList* &L){
    DLList* p,* q,* pre;
    p = L->next->next;
    L->next->next = NULL;
    while (p != NULL){
        q = p->next;
        pre = L;
        while (pre->next != NULL && pre->next->data < p->data)
            pre = pre->next;
        p->next = pre->next;
        if (pre->next != NULL)
            pre->next->prev = p;
        pre->next = p;
        p->prev = pre;
        p = q;
    }
}

//LoopLListQueue
void init_llist_queue(LList* &rear){
    rear = NULL;
}

void in_queue(LList* &rear, int e){
    LList* p;
    p = (LList*)malloc(sizeof(LList));
    p->data = e;
    if (rear == NULL){
        p->next = p;
        rear = p;
    }
    else{
        p->next = rear->next;
        rear->next = p;
        rear = p;
    }
}

bool out_queue(LList* &rear, int &e){
    LList* p;
    if (rear == NULL)
        return false;
    else if (rear->next == rear){
        e = rear->data;
        free(rear);
        rear = NULL;
    }
    else{
        p = rear->next;
        e = p->data;
        rear->next = p->next;
        free(p);
    }
    return true;
}









