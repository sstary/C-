#ifndef MAZEPATH_H
#define MAZEPATH_H
#include "comhead.h"

//maze_queue
//DFS---deep first search
typedef struct{
    int i;
    int j;
    int di;
}Box;

typedef struct{
    Box data[MaxSize];
    int top;
}StType;

int maze[10][10] =
{
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,0},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

bool maze_path(int xi, int yi, int xe, int ye){
    int i,j,k,di,find;
    StType st;
    st.top = -1;
    st.top++;
    st.data[st.top].i = xi;
    st.data[st.top].j = yi;
    st.data[st.top].di = -1;
    maze[xi][yi] = -1;
    while (st.top > -1){
        i = st.data[st.top].i;
        j = st.data[st.top].j;
        di = st.data[st.top].di;
        if (i == xe && j == ye){
            cout<<"find a way:"<<endl;
            for(k = 0; k <= st.top; k++){
                cout<<"("<<st.data[k].i<<","<<st.data[k].j<<") ";
                if ((k+1) % 5 == 0)
                    cout<<endl;
            }
            cout<<endl;
            return true;
        }
        find = 0;
        while ( di < 4 && find == 0){
            di++;
            switch(di){
            case 0: i = st.data[st.top].i-1;
                    j = st.data[st.top].j;
                    break;
            case 1: i = st.data[st.top].i;
                    j = st.data[st.top].j+1;
                    break;
            case 2: i = st.data[st.top].i+1;
                    j = st.data[st.top].j;
                    break;
            case 3: i = st.data[st.top].i;
                    j = st.data[st.top].j-1;
                    break;
            }
            if (maze[i][j] == 0)
                find = 1;
        }
        if (find == 1){
            st.data[st.top].di = di;
            st.top++;
            st.data[st.top].i = i;
            st.data[st.top].j = j;
            st.data[st.top].di = -1;
            maze[i][j] = -1;
        }
        else{
            maze[st.data[st.top].i][st.data[st.top].j] = 0;
            st.top--;
        }
    }
    return false;
}

//BFS---breadth first search
typedef struct{
    int i,j;
    int pre;
}QBox;

typedef struct{
    QBox data[MaxSize];
    int front,rear;
}QuType;

bool maze_path_queue(int xi, int yi,int xe, int ye){
    int i,j,di,find = 0;
    QuType qu;
    qu.front = qu.rear = -1;
    qu.rear++;
    qu.data[qu.rear].i = xi;
    qu.data[qu.rear].j = yi;
    qu.data[qu.rear].pre = -1;
    maze[xi][yi] = -1;
    while (qu.front != qu.rear && !find){
        qu.front++;
        i = qu.data[qu.front].i;
        j = qu.data[qu.front].j;
        if (i == xe && j == ye){
            find = 1;    // print path
            return true;
        }
        for (di = 0;di < 4;di ++){
            switch (di)
            {
            case 0: i = qu.data[qu.front].i-1;
                    j = qu.data[qu.front].j;
                    break;
            case 1: i = qu.data[qu.front].i;
                    j = qu.data[qu.front].j+1;
                    break;
            case 2: i = qu.data[qu.front].i+1;
                    j = qu.data[qu.front].j;
                    break;
            case 3: i = qu.data[qu.front].i;
                    j = qu.data[qu.front].j-1;
                    break;
            }
            if (maze[i][j] == 0){
                qu.rear++;
                qu.data[qu.rear].i = i;
                qu.data[qu.rear].j = j;
                qu.data[qu.rear].pre = qu.front;
                maze[i][j] = -1;
            }
        }
    }
    return false;
}
#endif // MAZEPATH_H















