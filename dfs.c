#include "dfs.h"
int visited[19][19];

void init_visited() {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            visited[i][j] = 0;
        }
    }

}

void init_q(Queue* q) {
    for (int i = 0; i < 6; i++) {
        q->Q[i] = "0";
    }
    q->top = -1;
    q->size = 0;
}

void push_q(Queue* q, char* elem) {
    q->Q[++(q->top)] = elem;
    q->size++;
}

char* pop_q(Queue* q) {
    char* elem = q->Q[(q->top)--];
    q->size--;
    return elem;
}
int dfs_row(int x, int y, int num, char* user_id, char* arr[19][20], int blank, Queue* stack) {

    if (visited[y][x] == 1) {

        return blank;
    }
    visited[y][x] = 1;
    if (stack->size > num + blank) {
        if (strcmp(arr[y][x],"0")==0) {

            return blank;
        }
        else {
            pop_q(stack);

            return blank;
        }
    }
    else {
        if (strcmp(arr[y][x],"0")==0) {
            if (blank == 1) {

            	
                return blank;
            }
            else {
                push_q(stack, "0");

                blank++;
                if(x+1<19){
                	dfs_row(x + 1, y, num, user_id, arr, blank,stack);
                }
                if(x-1>=0){
                	dfs_row(x - 1, y, num, user_id, arr, blank,stack);
                }
                return blank;
            }
        }
        else if (strcmp(arr[y][x],user_id)==0) {
            push_q(stack, "1");

            if(x+1<19){
            	blank = dfs_row(x + 1, y, num, user_id, arr, blank,stack);
            }
            if(x-1>=0){
            	blank = dfs_row(x - 1, y, num, user_id, arr, blank,stack);
            }
            return blank;
        }
        else {
            return blank;
        }
    }
}
int dfs_col(int x, int y, int num, char* user_id, char* arr[19][20],int blank,Queue* stack) {

    if (visited[y][x] == 1) {

        return blank;
    }
    visited[y][x]=1;
    if (stack->size > num + blank) {
        if (strcmp(arr[y][x],"0")==0) {

            return blank;
        }
        else{
            pop_q(stack);

            return blank;
        }
    }
    else {
        if (strcmp(arr[y][x],"0")==0) {
            if (blank == 1) {

            	
                return blank;
            }
            else {
                push_q(stack, "0");

                blank++;
                if(y+1<19){
                	dfs_col(x, y + 1, num, user_id, arr, blank,stack);
                }
                if(y-1>=0){
                	dfs_col(x, y - 1, num, user_id, arr, blank,stack);
                }
                return blank;
            }
        }
        else if (strcmp(arr[y][x],user_id)==0) {
            push_q(stack, "1");

            if(y+1<19){
            	blank = dfs_col(x, y + 1, num, user_id, arr, blank,stack);
            }
            if(0<=y-1){
            	blank = dfs_col(x, y - 1, num, user_id, arr, blank,stack);
            }
            return blank;
        }
        else {
            return blank;
        }
    }
}

int dfs_back_slash(int x, int y, int num, char* user_id, char* arr[19][20], int blank, Queue* stack) {

    if (visited[y][x] == 1) {

        return blank;
    }
    visited[y][x] = 1;
    if (stack->size > num + blank) {
        if (strcmp(arr[y][x],"0") == 0) {

            return blank;
        }
        else {
            pop_q(stack);

            return blank;
        }
    }
    else {
        if (strcmp(arr[y][x],"0") == 0) {
            if (blank == 1) {

            	
                return blank;
            }
            else {
                push_q(stack, "0");
                blank++;
                if(x+1<19 && y+1<19){
                	dfs_back_slash(x + 1, y + 1, num, user_id, arr, blank,stack);
                }
                if(0<=x-1 && 0<=y-1){
                	dfs_back_slash(x - 1, y - 1, num, user_id, arr, blank,stack);
                }
                return blank;
            }
        }
        else if (strcmp(arr[y][x],user_id) == 0) {
            push_q(stack, "1");

            if(x+1<19 && y+1<19){
            	blank = dfs_back_slash(x + 1, y + 1, num, user_id, arr, blank,stack);
            }
            if(0<=x-1 && 0<=y-1){
            	blank = dfs_back_slash(x - 1, y - 1, num, user_id, arr, blank,stack);
            }
            return blank;
        }
        else {
            return blank;
        }
    }
}

int dfs_slash(int x, int y, int num, char* user_id, char* arr[19][20], int blank, Queue* stack) {

    if (visited[y][x] == 1) {

        return blank;
    }
    visited[y][x] = 1;
    if (stack->size > num + blank) {
        if (strcmp(arr[y][x], "0") == 0) {

            return blank;
        }
        else {
            pop_q(stack);

            return blank;
        }
    }
    else {
        if (strcmp(arr[y][x],"0") == 0) {
            if (blank == 1) {

            	
                return blank;
            }
            else {
                push_q(stack, "0");

                blank++;
                if(x+1 < 19 && 0<= y-1){
                	dfs_slash(x + 1, y -1 , num, user_id, arr, blank,stack);
                }
                if(0<=x-1 && y+1<19){
                	dfs_slash(x - 1, y + 1, num, user_id, arr, blank,stack);
                }
                return blank;
            }
        }
        else if (strcmp(arr[y][x],user_id)==0) {
            push_q(stack, "1");

            if(x+1 < 19 && 0<= y-1){
            	blank = dfs_slash(x + 1, y - 1 , num, user_id, arr, blank,stack);
            }
            if(0<=x-1 && y+1<19){
            	blank = dfs_slash(x - 1, y + 1, num, user_id, arr, blank,stack);
            }
            return blank;
        }
        else {
            return blank;
        }
    }
}
