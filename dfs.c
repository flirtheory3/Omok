#include "dfs.h"

void init_visited() {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            visited[i][j] = 0;
        }
    }

}

void init_q(Queue* q) {
    for (int i = 0; i < 6; i++) {
        q->Q[i] = 0;
    }
    q->top = -1;
    q->size = 0;
}

void push_q(Queue* q, int elem) {
    q->Q[++(q->top)] = elem;
    q->size++;
}

int pop_q(Queue* q) {
    int elem = q->Q[(q->top)--];
    q->size--;
    return elem;
}
int dfs_row(int x, int y, int num, int user_id, int arr[19][19], int blank) {
    if (visited[y][x] == 1) {
        return blank;
    }
    visited[y][x] = 1;
    if (stack.size > num + blank) {
        if (arr[y][x] == 0) {
            return blank;
        }
        else {
            pop_q(&stack);
            return blank;
        }
    }
    else {
        if (arr[y][x] == 0) {
            if (blank == 1) {
                return blank;
            }
            else {
                push_q(&stack, 0);
                blank++;
                dfs_row(x + 1, y, num, user_id, arr, blank);
                dfs_row(x - 1, y, num, user_id, arr, blank);
                return blank;
            }
        }
        else if (arr[y][x] == user_id) {
            push_q(&stack, 1);
            blank = dfs_row(x + 1, y, num, user_id, arr, blank);
            blank = dfs_row(x - 1, y, num, user_id, arr, blank);
            return blank;
        }
        else {
            return blank;
        }
    }
}
int dfs_col(int x, int y, int num, int user_id, int arr[19][19],int blank) {
    if (visited[y][x] == 1) {
        return blank;
    }
    visited[y][x] = 1;
    if (stack.size > num + blank) {
        if (arr[y][x] == 0) {
            return blank;
        }
        else{
            pop_q(&stack);
            return blank;
        }
    }
    else {
        if (arr[y][x] == 0) {
            if (blank == 1) {
                return blank;
            }
            else {
                push_q(&stack, 0);
                blank++;
                dfs_col(x, y + 1, num, user_id, arr, blank);
                dfs_col(x, y - 1, num, user_id, arr, blank);
                return blank;
            }
        }
        else if (arr[y][x] == user_id) {
            push_q(&stack, 1);
            blank = dfs_col(x, y + 1, num, user_id, arr, blank);
            blank = dfs_col(x, y - 1, num, user_id, arr, blank);
            return blank;
        }
        else {
            return blank;
        }
    }
}

int dfs_back_slash(int x, int y, int num, int user_id, int arr[19][19], int blank) {
    if (visited[y][x] == 1) {
        return blank;
    }
    visited[y][x] = 1;
    if (stack.size > num + blank) {
        if (arr[y][x] == 0) {
            return blank;
        }
        else {
            pop_q(&stack);
            return blank;
        }
    }
    else {
        if (arr[y][x] == 0) {
            if (blank == 1) {
                return blank;
            }
            else {
                push_q(&stack, 0);
                blank++;
                dfs_back_slash(x + 1, y + 1, num, user_id, arr, blank);
                dfs_back_slash(x - 1, y - 1, num, user_id, arr, blank);
                return blank;
            }
        }
        else if (arr[y][x] == user_id) {
            push_q(&stack, 1);
            blank = dfs_back_slash(x + 1, y + 1, num, user_id, arr, blank);
            blank = dfs_back_slash(x - 1, y - 1, num, user_id, arr, blank);
            return blank;
        }
        else {
            return blank;
        }
    }
}

int dfs_slash(int x, int y, int num, int user_id, int arr[19][19], int blank) {
    if (visited[y][x] == 1) {
        return blank;
    }
    visited[y][x] = 1;
    if (stack.size > num + blank) {
        if (arr[y][x] == 0) {
            return blank;
        }
        else {
            pop_q(&stack);
            return blank;
        }
    }
    else {
        if (arr[y][x] == 0) {
            if (blank == 1) {
                return blank;
            }
            else {
                push_q(&stack, 0);
                blank++;
                dfs_slash(x + 1, y -1 , num, user_id, arr, blank);
                dfs_slash(x - 1, y + 1, num, user_id, arr, blank);
                return blank;
            }
        }
        else if (arr[y][x] == user_id) {
            push_q(&stack, 1);
            blank = dfs_slash(x + 1, y - 1 , num, user_id, arr, blank);
            blank = dfs_slash(x - 1, y + 1, num, user_id, arr, blank);
            return blank;
        }
        else {
            return blank;
        }
    }
}
