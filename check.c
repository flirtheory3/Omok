#include "dfs.h"
#include "check.h"

int check33(int arr[19][19], int user_id, int x, int y) {
    int num = 0;
    int blank = 0;
    init_visited();
    init_q(&stack);
    
    blank = dfs_row(x, y, 3, user_id, arr,0);
    if (stack.size - blank == 3) {
        num++;
    }

    init_visited();
    init_q(&stack);

    blank = dfs_col(x, y, 3, user_id, arr,0);
    if (stack.size - blank == 3) {
        num++;
    }

    init_visited();
    init_q(&stack);

    blank = dfs_back_slash(x, y, 3, user_id, arr,0);
    if (stack.size - blank == 3) {
        num++;
    }

    init_visited();
    init_q(&stack);

    blank = dfs_slash(x, y, 3, user_id, arr, 0);
    if (stack.size - blank == 3) {
        num++;
    }
    
    if (num >= 2) {
        return 0;
    }
    return 1;
}

int check44(int arr[19][19], int user_id, int x, int y) {
    int num = 0;
    init_visited();
    num += dfs_row(x, y, 4, user_id, arr, 0);
    init_visited();
    num += dfs_col(x, y, 4, user_id, arr, 0);
    init_visited();
    num += dfs_back_slash(x, y, 4, user_id, arr, 0);
    init_visited();
    num += dfs_slash(x, y, 4, user_id, arr, 0);
    if (num >= 2) {
        return 0;
    }
    return 1;
}

int check(int arr[19][19],int user_id, int x, int y) {
    int tmp[19][19];
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            tmp[i][j] = arr[i][j];
        }
    }
    tmp[y][x] = user_id;
    if (!check33(tmp,user_id,x,y)) {
        return 33;
    }
    else if (!check44(tmp,user_id ,x, y)) {
        return 44;
    }
    
    return 1;
}
