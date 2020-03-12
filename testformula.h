#ifndef TESTFORMULA_H
#define TESTFORMULA_H
#include "comhead.h"
#include "idvhead.h"

void solve_equation(float a, float b, float c){
    float d,x1,x2;
    d = b*b-4*a*c;
    if (d > 0){
        x1 = (-b-sqrt(d))/(2*a);
        x2 = (-b+sqrt(d))/(2*a);
        cout<<"two different solution: x1="<<x1<<" x2="<<x2<<endl;
    }
    else if (d == 0){
        x1 = (-b-sqrt(d))/(2*a);
        cout<<"two equal solution: x1=x2="<<x1<<endl;
    }
    else {
        cout<<"no solution"<<endl;
    }
}

void test_SqList(){
    SqList* sqlist;
    int a[]={3,8,2,7,1,5,3,4,6,0};
    creat_sqlist(sqlist, a, 10);
    disply_sqlist(sqlist);
    small_to_big(sqlist);
    disply_sqlist(sqlist);
}

void test_LList(){
    LList* llista,* llistb,* llistc;
    int a[]={1,2,3,7,7,7,8};
    int b[]={1,2,3,4,4,5,6,7,9,10};
    int c[]={3,4,5,5,7,8,8,9,10,12};
    create_llist_R(llista, a, 7);
    create_llist_R(llistb, b, 10);
    create_llist_R(llistc, c, 10);
    display_llist(llista);
    display_llist(llistb);
    display_llist(llistc);
    three_list_union(llista, llistb, llistc);
    display_llist(llista);

    destroy_llist(llista);
}

void test_DLList(){
    DLList* dllist;
    int a[]={3,6,1,5,9};
    create_dllist_R(dllist, a, 5);
    display_dllist(dllist);
    increase_order_dllist(dllist);
    display_dllist(dllist);
    destroy_dllist(dllist);
}

void test_LiStack(){
    LiStack* listack;
    int e = 0;
    init_listack(listack);
    push_listack(listack,4);
    display_listack(listack);
    push_listack(listack,3);
    display_listack(listack);
    pop_listack(listack,e);
    display_listack(listack);
    destroy_listack(listack);
}

void test_Suffix(){
    char exp[MaxSize];
    char postexp[MaxSize];
    char flag = 'Y';
    while (flag == 'Y'){
        cout<<"Input insif expression: "<<endl;
        cin>>exp;
        trans(exp, postexp);
        cout<<"infix expression: "<<exp<<endl;
        cout<<"sufix expression: "<<postexp<<endl;
        cout<<"continue? Y/N"<<endl;
        cin>>flag;
    }
    cout<<"end test"<<endl;
}

void test_maze_path(){
    if(!maze_path(1,1,8,8))
        cout<<"no path found"<<endl;
}

void test_loop_llist_queue(){
    LList* rear;
    int e;
    init_llist_queue(rear);
    in_queue(rear, 2);
    in_queue(rear, 3);
    out_queue(rear, e);
    cout<<e<<endl;
}

void test_maze_path_queue(){
    maze_path_queue(1,1,8,8);
}

void test_BF(){
    SqString s, t;
    char sctr[]={'a','a','a','b','c','b','c','\0'};
    char tstr[]={'a','b','c','\0'};
    init_sqstring(s, sctr);
    init_sqstring(t, tstr);
    int r = BF(s, t);
    cout<<r<<endl;
}

void test_KMP(){
    SqString s, t;
    int r;
    char sstr[]={'a','a','a','b','a','a','a','a','b','\0'};
    char tstr[]={'a','a','a','a','b','\0'};
    init_sqstring(s, sstr);
    init_sqstring(t, tstr);
    r = KMP(s, t);
    cout<<r<<endl;
}

void test_gt(){
    char str[] = {'(','a',',','(','b',',','c',',','d',')',',',
               '(','#',')',')','\0'};
    char* s = str;
    GTNode* g;
    g = gt_create(s);
    cout<<"depth = "<<gt_depth(g)<<endl;
    gt_display(g);
}
#endif // TESTFORMULA_H
