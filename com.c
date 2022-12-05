#include <stdio.h>
#include <stdbool.h>

int arr[19][19] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,2,1,1,1,0,2,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

int visited[19][19];
void init_visited() {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            visited[i][j] = 0;
        }
    }
    
}
int dfs_row(int x, int y, int num, int user_id) {
    if (arr[y][x] == 0) {
        visited[y][x] = 1;
        return 0;
    }
    else if (visited[y][x] == 1) {
        return 0;
    }
    else if (arr[y][x] == user_id) {
        visited[y][x] = 1;
        num--;
        if (num == 0) {
            return 1;
        }
        else {
            dfs_row(x+1, y,num, user_id);
        }
    }
    else {
        return;
    }
}
int dfs_col(int x, int y, int num, int user_id) {
    if (arr[y][x] == 0) {
        visited[y][x] = 1;
        return 0;
    }
    else if (visited[y][x] == 1) {
        return 0;
    }
    else if (arr[y][x] == user_id) {
        visited[y][x] = 1;
        num--;
        if (num == 0) {
            return 1;
        }
        else {
            dfs_col(x, y+1, num, user_id);
        }
    }
    else {
        return;
    }
}
int dfs_back_slash(int x, int y, int num, int user_id) {
    if (arr[y][x] == 0) {
        visited[y][x] = 1;
        return 0;
    }
    else if (visited[y][x] == 1) {
        return 0;
    }
    else if (arr[y][x] == user_id) {
        visited[y][x] = 1;
        num--;
        if (num == 0) {
            return 1;
        }
        else {
            dfs_back_slash(x+1, y + 1, num,user_id);
        }
    }
    else {
        return;
    }
}
int dfs_slash(int x, int y, int num, int user_id) {
    if (arr[y][x] == 0) {
        visited[y][x]=1;
        return 0;
    }
    else if (visited[y][x] == 1) {
        return 0;
    }
    else if(arr[y][x]==user_id){
        visited[y][x] = 1;
        num--;
        if (num == 0) {
            return 1;
        }
        else {
            dfs_slash(x + 1, y - 1, num, user_id);
        }
    }
    else {
        return;
    }
}
void CHACKSU(int user_id) {

    //4���ΰ� ������ 5����
    //����
    init_visited();
    for (int i = 0; i < 19;i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_row(i, j, 4,1) == 1) {
                if (0 < i && arr[j][i-1] == 0) {
                    arr[j][i-1] = 1;
                    return;
                }
                else if (i < 18 && arr[j][i+1] == 0) {
                    arr[j][i+1] = 1;
                    return;
                }
            }

        }
    }
    //����
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_col(i, j, 4,1) == 1) {
                if (0 < j && arr[j-1][i] == 0) {
                    arr[j-1][i] = 1;
                    return;
                }
                else if (j < 18 && arr[j+1][i] == 0) {
                    arr[j+1][i] = 1;
                    return;
                }
            }

        }
    }
    // '\'
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_back_slash(i, j, 4,1) == 1) {
                if (0<i && 0 < j && arr[j - 1][i-1] == 0) {
                    arr[j - 1][i-1] = 1;
                    return;
                }
                else if (i<18 && j < 18 && arr[j + 1][i+1] == 0) {
                    arr[j + 1][i+1] = 1;
                    return;
                }
            }

        }
    }

    // '/'
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_slash(i, j, 4,1) == 1) {
                if (i < 18 && 0 < j && arr[j - 1][i + 1] == 0) {
                    arr[j - 1][i + 1] = 1;
                    return;
                }
                else if (0 < i && j < 18 && arr[j + 1][i - 1] == 0) {
                    arr[j + 1][i - 1] = 1;
                    return;
                }
            }

        }
    }
    //������ 4���ΰ� ������ ����
    //����
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_row(i, j, 4, user_id) == 1) {
                if (0 < i && arr[j][i - 1] == 0) {
                    arr[j][i - 1] = 1;
                    return;
                }
                else if (i < 18 && arr[j][i + 1] == 0) {
                    arr[j][i + 1] = 1;
                    return;
                }
            }

        }
    }
    //����
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_col(i, j, 4, user_id) == 1) {
                if (0 < j && arr[j - 1][i] == 0) {
                    arr[j - 1][i] = 1;
                    return;
                }
                else if (j < 18 && arr[j + 1][i] == 0) {
                    arr[j + 1][i] = 1;
                    return;
                }
            }

        }
    }
    // '\'
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_back_slash(i, j, 4, user_id) == 1) {
                if (0 < i && 0 < j && arr[j - 1][i - 1] == 0) {
                    arr[j - 1][i - 1] = 1;
                    return;
                }
                else if (i < 18 && j < 18 && arr[j + 1][i + 1] == 0) {
                    arr[j + 1][i + 1] = 1;
                    return;
                }
            }

        }
    }

    // '/'
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_slash(i, j, 4, user_id) == 1) {
                if (i < 18 && 0 < j && arr[j - 1][i + 1] == 0) {
                    arr[j - 1][i + 1] = 1;
                    return;
                }
                else if (0 < i && j < 18 && arr[j + 1][i - 1] == 0) {
                    arr[j + 1][i - 1] = 1;
                    return;
                }
            }

        }
    }
    //3���ΰ� ������ 4����
    //����
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_row(i, j, 3, 1) == 1) {
                if (0 < i && arr[j][i - 1] == 0) {
                    arr[j][i - 1] = 1;
                    return;
                }
                else if (i < 18 && arr[j][i + 1] == 0) {
                    arr[j][i + 1] = 1;
                    return;
                }
            }

        }
    }
    //����
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_col(i, j, 3, 1) == 1) {
                if (0 < j && arr[j - 1][i] == 0) {
                    arr[j - 1][i] = 1;
                    return;
                }
                else if (j < 18 && arr[j + 1][i] == 0) {
                    arr[j + 1][i] = 1;
                    return;
                }
            }

        }
    }
    // '\'
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_back_slash(i, j, 3, 1) == 1) {
                if (0 < i && 0 < j && arr[j - 1][i - 1] == 0) {
                    arr[j - 1][i - 1] = 1;
                    return;
                }
                else if (i < 18 && j < 18 && arr[j + 1][i + 1] == 0) {
                    arr[j + 1][i + 1] = 1;
                    return;
                }
            }

        }
    }

    // '/'
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_slash(i, j, 3, 1) == 1) {
                if (i < 18 && 0 < j && arr[j - 1][i + 1] == 0) {
                    arr[j - 1][i + 1] = 1;
                    return;
                }
                else if (0 < i && j < 18 && arr[j + 1][i - 1] == 0) {
                    arr[j + 1][i - 1] = 1;
                    return;
                }
            }

        }
    }
    //������ 3���ΰ� ������ ����
    //����
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_row(i, j, 3, user_id) == 1) {
                if (0 < i && arr[j][i - 1] == 0) {
                    arr[j][i - 1] = 1;
                    return;
                }
                else if (i < 18 && arr[j][i + 1] == 0) {
                    arr[j][i + 1] = 1;
                    return;
                }
            }

        }
    }
    //����
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_col(i, j, 3, user_id) == 1) {
                if (0 < j && arr[j - 1][i] == 0) {
                    arr[j - 1][i] = 1;
                    return;
                }
                else if (j < 18 && arr[j + 1][i] == 0) {
                    arr[j + 1][i] = 1;
                    return;
                }
            }

        }
    }
    // '\'
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_back_slash(i, j, 3, user_id) == 1) {
                if (0 < i && 0 < j && arr[j - 1][i - 1] == 0) {
                    arr[j - 1][i - 1] = 1;
                    return;
                }
                else if (i < 18 && j < 18 && arr[j + 1][i + 1] == 0) {
                    arr[j + 1][i + 1] = 1;
                    return;
                }
            }

        }
    }

    // '/'
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_slash(i, j, 3, user_id) == 1) {
                if (i < 18 && 0 < j && arr[j - 1][i + 1] == 0) {
                    arr[j - 1][i + 1] = 1;
                    return;
                }
                else if (0 < i && j < 18 && arr[j + 1][i - 1] == 0) {
                    arr[j + 1][i - 1] = 1;
                    return;
                }
            }

        }
    }
    //2���ΰ� ������ 3��
    //����
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_row(i, j, 2, 1) == 1) {
                if (0 < i && arr[j][i - 1] == 0) {
                    arr[j][i - 1] = 1;
                    return;
                }
                else if (i < 18 && arr[j][i + 1] == 0) {
                    arr[j][i + 1] = 1;
                    return;
                }
            }

        }
    }
    //����
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_col(i, j, 2, 1) == 1) {
                if (0 < j && arr[j - 1][i] == 0) {
                    arr[j - 1][i] = 1;
                    return;
                }
                else if (j < 18 && arr[j + 1][i] == 0) {
                    arr[j + 1][i] = 1;
                    return;
                }
            }

        }
    }
    // '\'
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_back_slash(i, j, 2, 1) == 1) {
                if (0 < i && 0 < j && arr[j - 1][i - 1] == 0) {
                    arr[j - 1][i - 1] = 1;
                    return;
                }
                else if (i < 18 && j < 18 && arr[j + 1][i + 1] == 0) {
                    arr[j + 1][i + 1] = 1;
                    return;
                }
            }

        }
    }

    // '/'
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_slash(i, j, 2, 1) == 1) {
                if (i < 18 && 0 < j && arr[j - 1][i + 1] == 0) {
                    arr[j - 1][i + 1] = 1;
                    return;
                }
                else if (0 < i && j < 18 && arr[j + 1][i - 1] == 0) {
                    arr[j + 1][i - 1] = 1;
                    return;
                }
            }

        }
    }
    //1���ΰ� �ֿ�� 2��
    //����
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_row(i, j, 1, 1) == 1) {
                if (0 < i && arr[j][i - 1] == 0) {
                    arr[j][i - 1] = 1;
                    return;
                }
                else if (i < 18 && arr[j][i + 1] == 0) {
                    arr[j][i + 1] = 1;
                    return;
                }
            }

        }
    }
    //����
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_col(i, j, 1, 1) == 1) {
                if (0 < j && arr[j - 1][i] == 0) {
                    arr[j - 1][i] = 1;
                    return;
                }
                else if (j < 18 && arr[j + 1][i] == 0) {
                    arr[j + 1][i] = 1;
                    return;
                }
            }

        }
    }
    // '\'
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_back_slash(i, j, 1, 1) == 1) {
                if (0 < i && 0 < j && arr[j - 1][i - 1] == 0) {
                    arr[j - 1][i - 1] = 1;
                    return;
                }
                else if (i < 18 && j < 18 && arr[j + 1][i + 1] == 0) {
                    arr[j + 1][i + 1] = 1;
                    return;
                }
            }

        }
    }

    // '/'
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_slash(i, j, 1, 1) == 1) {
                if (i < 18 && 0 < j && arr[j - 1][i + 1] == 0) {
                    arr[j - 1][i + 1] = 1;
                    return;
                }
                else if (0 < i && j < 18 && arr[j + 1][i - 1] == 0) {
                    arr[j + 1][i - 1] = 1;
                    return;
                }
            }

        }
    }
    //��� 9ĭ�� ��
    for (int i = 8; i <= 10; i++) {
        for (int j = 8; j <= 10; j++) {
            if (arr[j][i]==0){
                arr[j][i] = 1;
                return;
            }

        }
    }
}
int main(void){
    CHACKSU(2);
    for (int i = 0; i < 20; i++) {
        printf("%s", " - - - - - - - - - - - - - - - - - - -\n");
        
        for (int j = 0; j < 19; j++) {

            if (i != 19) {
                printf("%s", "|");
                printf("%d", arr[j][i]);
            }

        }
        if (i != 19) {
            printf("%s", "|\n");
        }
    }


    return 0;
}   