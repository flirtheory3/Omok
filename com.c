#include "com.h"


void CHACKSU(int user_id, int arr[19][19]) {

    //4개인게 있으면 5개로
    //가로
    init_visited();
    for (int i = 0; i < 19;i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_row(i, j, 4,1,arr) == 1) {
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
    //세로
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_col(i, j, 4,1,arr) == 1) {
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
            if (dfs_back_slash(i, j, 4,1,arr) == 1) {
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
            if (dfs_slash(i, j, 4,1,arr) == 1) {
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
    //상대방이 4개인게 있으면 막아
    //가로
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_row(i, j, 4, user_id, arr) == 1) {
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
    //세로
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_col(i, j, 4, user_id, arr) == 1) {
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
            if (dfs_back_slash(i, j, 4, user_id, arr) == 1) {
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
            if (dfs_slash(i, j, 4, user_id, arr) == 1) {
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
    //3개인게 있으면 4개로
    //가로
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_row(i, j, 3, 1, arr) == 1) {
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
    //세로
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_col(i, j, 3, 1, arr) == 1) {
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
            if (dfs_back_slash(i, j, 3, 1, arr) == 1) {
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
            if (dfs_slash(i, j, 3, 1, arr) == 1) {
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
    //상대방이 3개인게 있으면 막아
    //가로
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_row(i, j, 3, user_id, arr) == 1) {
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
    //세로
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_col(i, j, 3, user_id, arr) == 1) {
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
            if (dfs_back_slash(i, j, 3, user_id, arr) == 1) {
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
            if (dfs_slash(i, j, 3, user_id, arr) == 1) {
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
    //2개인게 있으면 3개
    //가로
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_row(i, j, 2, 1, arr) == 1) {
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
    //세로
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_col(i, j, 2, 1, arr) == 1) {
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
            if (dfs_back_slash(i, j, 2, 1, arr) == 1) {
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
            if (dfs_slash(i, j, 2, 1, arr) == 1) {
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
    //1개인게 있우면 2개
    //가로
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_row(i, j, 1, 1, arr) == 1) {
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
    //세로
    init_visited();
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dfs_col(i, j, 1, 1, arr) == 1) {
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
            if (dfs_back_slash(i, j, 1, 1, arr) == 1) {
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
            if (dfs_slash(i, j, 1, 1, arr) == 1) {
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
    //가운데 9칸에 놔
    for (int i = 8; i <= 10; i++) {
        for (int j = 8; j <= 10; j++) {
            if (arr[j][i]==0){
                arr[j][i] = 1;
                return;
            }

        }
    }
}
