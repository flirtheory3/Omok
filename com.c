#include "com.h"

Queue stack_com;
int CHACKSU(char* user_id, char* board[19][20]) {
	printf("user_id : %s\n",user_id);
    char* arr[19][20];
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if(strcmp(board[i][j],"@")==0){
            	arr[j][i] = "1";
            }
            else if(strcmp(board[i][j],"0")==0){
            	arr[j][i] = "2";
            }
            else{
            	arr[j][i] = "0";
            }
        }
    }
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            printf("%s ",arr[j][i]);
        }
        printf("\n");
    }
    
    //4개인게 있으면 5개로
    //가로
    printf("chacksu entered\n");
    
    printf("ATTACK 4\n");
    for (int i = 0; i < 19;i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_row(i, j, 4, "1", arr, 0,&stack_com);
            if (stack_com.size - blank == 4) {
                if (blank == 1) {
                    for (int k = i - 3; k <= i + 3; k++) {
                        if (arr[k - 1][j] == "1" && arr[k + 1][j] == "1") {
                            arr[k][j] = "1";
                            return 2*(19*j+k);
                        }

                    }
                }
                if (0 < i &&arr[j][i]=="1" && arr[j][i - 1] == "0") {
                        arr[j][i - 1] = "1";
                        return 2*(19*i+j);
                    }
                    else if (i < 18 &&arr[j][i]=="1" && arr[j][i + 1] == "0") {
                        arr[j][i + 1] = "1";
                        return 2*(19*i+j);
                    }
            }
            

        }
    }
    //세로
    
    printf("ATTACK 4\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_col(i, j, 4, "1", arr, 0,&stack_com);

            if (stack_com.size - blank == 4) {
            	for(int i=0;i<stack_com.size;i++){
            		printf("%s ",stack_com.Q[i]);
            	}
            	printf("\n");
                if (blank == 1) {
                    for (int k = -3; k <= 3; k++) {
                        if (arr[i+k][j-k-1] == "1" && arr[i+k][j-k+1] == "1") {
                            arr[i+k][j-k] = "1";
                            return 2*(19*(j-k)+(i+k));
                        }

                    }
                }
                if (0 < j &&arr[j][i]=="1" && arr[j - 1][i] == "0") {
                        arr[j - 1][i] = "1";
                        return 2*(19 * (i) + j-1);
                    }
                    else if (j < 18 &&arr[j][i]=="1" && arr[j + 1][i] == "0") {
                        arr[j + 1][i] = "1";
                        return 2 * (19 *(i) + j+1);
                    }
            }
           

        }
    }
    // '\'
    
    printf("ATTACK 4\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_back_slash(i, j, 4, "1", arr, 0,&stack_com);
            if (stack_com.size - blank == 4) {
                if (blank == 1) {
                    for (int k = -3; k <= 3; k++) {
                        if (arr[i + k - 1][j - k + 1] == "1" && arr[i + k + 1][j - k - 1] == "1") {
                            arr[i + k][j - k] = "1";
                            return 2 * (19 * (j-k) + (i+k));
                        }

                    }
                }
                if (0 < j &&arr[j][i]=="1" && arr[j - 1][i-1] == "0"&& arr[j][i]=="1") {
                        arr[j - 1][i-1] = "1";
                        return 2 * (19 * (i-1) + j-1);
                    }
                    else if (j < 18 &&arr[j][i]=="1" && arr[j + 1][i+1] == "0" && arr[j][i]=="1") {
                        arr[j + 1][i+1] = "1";
                        return 2 * (19 * (i+1) + j+1);
                    }
            }
            
            
            

        }
    }

    // '/'
    
    printf("ATTACK 4\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_slash(i, j, 4, "1", arr, 0,&stack_com);
            if (stack_com.size - blank == 4) {
                if (blank == 1) {
                    for (int k = -3; k <= 3; k++) {
                        if (arr[i + k - 1][j + k + 1] == "1" && arr[i + k + 1][j + k - 1] == "1") {
                            arr[i + k][j + k] = "1";
                            return 2 * (19 * (j+k) + (i+k));
                        }

                    }
                }
                if (i < 18 && 0 < j &&arr[j][i]=="1" && arr[j - 1][i + 1] == "0") {
                        arr[j - 1][i + 1] = "1";
                        return 2 * (19 * (i+1) + (j-1));
                    }
                    else if (0 < i && j < 18 &&arr[j][i]=="1" && arr[j + 1][i - 1] == "0") {
                        arr[j + 1][i - 1] = "1";
                        return 2 * (19 * (i-1) + (j+1));
                    }
            }
            

        }
    }
    //상대방이 4개인게 있으면 막아
    //가로
    
    printf("DEFENCE 4\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_row(i, j, 4, user_id, arr, 0,&stack_com);
            if (stack_com.size - blank == 4) {
                if (blank == 1) {
                    for (int k = i - 3; k <= i + 3; k++) {
                        if (arr[k - 1][j] == user_id && arr[k + 1][j] == user_id) {
                            arr[k][j] = "1";
                            return 2 * (19 * j + k);
                        }

                    }
                }
                if (0 < i && arr[j][i - 1] == "0") {
                        arr[j][i - 1] = "1";
                        return 2 * (19 * (i-1) + j);
                    }
                    else if (i < 18 && arr[j][i + 1] == "0") {
                        arr[j][i + 1] = "1";
                        return 2 * (19 * (i+1) + j);
                    }
            }

        }
    }
    //세로
    
    printf("DEFENCE 4\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_col(i, j, 4, user_id, arr, 0,&stack_com);
            if (stack_com.size - blank == 4) {
                if (blank == 1) {
                    for (int k = -3; k <= 3; k++) {
                        if (arr[i + k][j - k - 1] == user_id && arr[i + k][j - k + 1] == user_id) {
                            arr[i + k][j - k] = "1";
                            return 2 * (19 * (j-k) + (i+k));
                        }

                    }
                }
                if (0 < j && arr[j - 1][i] == "0") {
                        arr[j - 1][i] = "1";
                        return 2 * (19 * (i) + j-1);
                    }
                    else if (j < 18 && arr[j + 1][i] == "0") {
                        arr[j + 1][i] = "1";
                        return 2 * (19 * (i) + j+1);
                    }
            }

        }
    }
    // '\'
    
    printf("DEFENCE 4\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_back_slash(i, j, 4, user_id, arr, 0, &stack_com);
            if (stack_com.size - blank == 4) {
                if (blank == 1) {
                    for (int k = -3; k <= 3; k++) {
                        if (arr[i + k - 1][j - k + 1] == user_id && arr[i + k + 1][j - k - 1] == user_id) {
                            arr[i + k][j - k] = "1";
                            return 2 * (19 * (j-k) + (i+k));
                        }

                    }
                }
                if (0 < j && arr[j - 1][i-1] == "0" && arr[i][j]==user_id) {
                        arr[j - 1][i-1] = "1";
                        return 2 * (19 * (i-1) + j-1);
                    }
                    else if (j < 18 && arr[j + 1][i+1] == "0" && arr[j][i]==user_id) {
                        arr[j + 1][i+1] = "1";
                        return 2 * (19 * (i+1) + j+1);
                    }
            }

        }
    }

    // '/'
    
    printf("DEFENCE 4\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_slash(i, j, 4, user_id, arr, 0, &stack_com);
            if (stack_com.size - blank == 4) {
                if (blank == 1) {
                    for (int k = -3; k <= 3; k++) {
                        if (arr[i + k - 1][j + k + 1] == user_id && arr[i + k + 1][j + k - 1] == user_id) {
                            arr[i + k][j + k] = "1";
                            return 2 * (19 * (j+k) + (i+k));
                        }

                    }
                }
                if (i < 18 && 0 < j && arr[j - 1][i + 1] == "0") {
                        arr[j - 1][i + 1] = "1";
                        return 2 * (19 * (i+1) + j-1);
                    }
                    else if (0 < i && j < 18 && arr[j + 1][i - 1] == "0") {
                        arr[j + 1][i - 1] = "1";
                        return 2 * (19 *(i-1) + j+1);
                    }
            }

        }
    }
    //3개인게 있으면 4개로
    //가로
    
    printf("ATTACK 3\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_row(i, j, 3, "1", arr, 0, &stack_com);
            if (stack_com.size - blank == 3) {

                if (blank == 1) {
                    for (int k = i - 2; k <= i + 2; k++) {
                        if (arr[k - 1][j] == "1" && arr[k + 1][j] == "1") {
                            arr[k][j] = "1";
                            return 2 * (19 * j + k);
                        }

                    }
                }
                if (0 < i &&arr[j][i]=="1" && arr[j][i - 1] == "0") {
                        arr[j][i - 1] = "1";
                        return 2 * (19 * (i-1) + j);
                    }
                    else if (i < 18 &&arr[j][i]=="1" && arr[j][i + 1] == "0") {
                        arr[j][i + 1] = "1";
                        return 2 * (19 * (i+1) + j);
                    }
            }
        }
    }
    //세로
    
    printf("ATTACK 3\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_col(i, j, 3, "1", arr, 0, &stack_com);
            if (stack_com.size - blank == 3) {

                if (blank == 1) {
                    for (int k = -2; k <= 2; k++) {
                        if (arr[i + k][j - k - 1] == "1" && arr[i + k][j - k + 1] == "1") {
                            arr[i + k][j - k] = "1";
                            return 2 * (19 * (j-k) + (i+k));
                        }

                    }
                }
                if (0 < j &&arr[j][i]=="1" && arr[j - 1][i] == "0") {
                        arr[j - 1][i] = "1";
                        return 2 * (19 * (i) + j-1);
                    }
                    else if (j < 18 &&arr[j][i]=="1" && arr[j + 1][i] == "0") {
                        arr[j + 1][i] = "1";
                        return 2 * (19 * (i) + j+1);
                    }
            }

        }
    }
    // '\'
    
    printf("ATTACK 3\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_back_slash(i, j, 3, "1", arr, 0, &stack_com);
            if (stack_com.size - blank == 3) {
            	//printf("%d %d",stack_com.size,blank);
                if (blank == 1) {
                    for (int k = -2; k <= 2; k++) {
                        if (arr[i + k - 1][j - k + 1] == "1" && arr[i + k + 1][j - k - 1] == "1") {
                            arr[i + k][j - k] = "1";
                            return 2 * (19 * (j-k) + (i+k));
                        }

                    }
                }
                if (0 < j &&arr[j][i]=="1" && arr[j - 1][i-1] == "0") {
                        arr[j - 1][i-1] = "1";
                        return 2 * (19 * (i-1) + j-1);
                    }
                    else if (j < 18 &&arr[j][i]=="1" && arr[j + 1][i+1] == "0") {
                        arr[j + 1][i+1] = "1";
                        return 2 * (19 * (i+1) + j+1);
                    }
            }

        }
    }

    // '/'
    
    printf("ATTACK 3\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_slash(i, j, 3, "1", arr, 0, &stack_com);
            if (stack_com.size - blank == 3) {
            	//printf("state : %d %d",stack_com.size,blank);
                if (blank == 1) {
                    for (int k = -2; k <= 2; k++) {
                        if (arr[i + k - 1][j + k + 1] == "1" && arr[i + k + 1][j + k - 1] == "1") {
                            arr[i + k][j + k] = "1";
                            return 2 * (19 * (j+k) + (i+k));
                        }

                    }
                }
                if (i < 18 && 0 < j &&arr[j][i]=="1" && arr[j - 1][i + 1] == "0") {
                        arr[j - 1][i + 1] = "1";
                        return 2 * (19 * (i+1) + (j-1));
                    }
                    else if (0 < i && j < 18 &&arr[j][i]=="1" && arr[j + 1][i - 1] == "0") {
                        arr[j + 1][i - 1] = "1";
                        return 2 * (19 * (i-1) + (j+1));
                    }
            }

        }
    }
    //상대방이 3개인게 있으면 막아
    //가로
    
    printf("DEFENCE 3\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_row(i, j, 3, user_id, arr, 0, &stack_com);
            printf("%d %d : %d\n", i, j, stack_com.size - blank);
            if (stack_com.size - blank == 3) {
                if (blank == 1) {
                    for (int k = i - 2; k <= i + 2; k++) {
                        if (arr[k - 1][j] == user_id && arr[k + 1][j] == user_id) {
                            arr[k][j] = "1";
                            return 2 * (19 * j + k);
                        }

                    }
                }
                else {

                    if (0 < i && arr[j][i - 1] == "0") {
                        arr[j][i - 1] = "1";
                        return 2 * (19 * (i-1) + j);
                    }
                    else if (i < 18 && arr[j][i + 1] == "0") {
                        arr[j][i + 1] = "1";
                        return 2 * (19 * (i+1) + j);
                    }


                }
            }

        }
    }
    //세로
    
    printf("DEFENCE 3\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_col(i, j, 3, user_id, arr, 0, &stack_com);
            
            if (stack_com.size - blank == 3) {
            	printf("1\n");
                if (blank == 1) {
                    for (int k = -2; k <= 2; k++) {
                        if (arr[i + k][j - k - 1] == user_id && arr[i + k][j - k + 1] == user_id) {
                            arr[i + k][j - k] = "1";
                            return 2 * (19 * (j-k) + (i+k));
                        }

                    }
                }
                if (0 < j && arr[j - 1][i] == "0"&& arr[j][i]==user_id) {
                    arr[j - 1][i] = "1";
                    return 2 * (19 * (i) + (j-1));
                }
                else if (j < 18 && arr[j + 1][i] == "0" && arr[j][i]==user_id) {
                    arr[j + 1][i] = "1";
                    return 2 * (19 * (i) + (j+1));
                }
            }

        }
    }
    // '\'
    
    printf("DEFENCE 3\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_back_slash(i, j, 3, user_id, arr, 0, &stack_com);
            if (stack_com.size - blank == 3) {
                if (blank == 1) {
                    for (int k = -2; k <= 2; k++) {
                        if (arr[i + k - 1][j - k + 1] == user_id && arr[i + k + 1][j - k - 1] == user_id) {
                            arr[i + k][j - k] = "1";
                            return 2 * (19 * (j-k) + (i+k));
                        }

                    }
                }
                if (0 < j && arr[j - 1][i-1] == "0"&& arr[j][i]==user_id) {
                    arr[j - 1][i=1] = "1";
                    return 2 * (19 * (i - 1) + (j-1));
                }
                else if (j < 18 && arr[j + 1][i-1] == "0" && arr[j][i]==user_id) {
                    arr[j + 1][i+1] = "1";
                    return 2 * (19 * (i-1) + (j+1));
                }
            }

        }
    }


    // '/'
    
    printf("DEFENCE 3\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_slash(i, j, 3, user_id, arr, 0, &stack_com);
            if (stack_com.size - blank == 3) {
                if (blank == 1) {
                    for (int k = -2; k <= 2; k++) {
                        if (arr[i + k - 1][j + k + 1] == user_id && arr[i + k + 1][j + k - 1] == user_id) {
                            arr[i + k][j + k] = "1";
                            return 2 * (19 * (j+k) + (i+k));
                        }

                    }
                }
                if (i < 18 && 0 < j  && arr[j - 1][i + 1] == "0") {
                        arr[j - 1][i + 1] = "1";
                        return 2 * (19 * (i+1) + (j-1));
                    }
                    else if (0 < i  && j < 18 && arr[j + 1][i - 1] == "0") {
                        arr[j + 1][i - 1] = "1";
                        return 2 * (19 * (i-1) + (j+1));
                    }
            }

        }
    }
    //2개인게 있으면 3개
    //가로
    
    printf("ATTACK 2\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_row(i, j, 2, "1", arr, 0,&stack_com);
            if (stack_com.size - blank == 2) {
            	printf("pos : %d %d state : %d %d",j, i, stack_com.size,blank);
                if (0 < i &&arr[j][i]=="1" && arr[j][i - 1] == "0") {
                    arr[j][i - 1] = "1";
                    return 2 * (19 * (i-1) + (j));
                }
                else if (i < 18 &&arr[j][i]=="1" && arr[j][i + 1] == "0") {
                    arr[j][i + 1] = "1";
                    return 2 * (19 * (i+1) + (j));
                }
            }

        }
    }
    //세로
    
    printf("ATTACK 2\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_col(i, j, 2, "1", arr, 0, &stack_com);
            if (stack_com.size - blank == 2) {
           		printf("pos : %d %d state : %d %d",j, i, stack_com.size,blank);
                if (0 < j && arr[j][i]=="1"&&arr[j - 1][i] == "0") {
                    arr[j - 1][i] = "1";
                    return 2 * (19 * (i) + (j-1));
                }
                else if (j < 18 &&arr[j][i]=="1" && arr[j + 1][i] == "0") {
                    arr[j + 1][i] = "1";
                    return 2 * (19 * (i) + (j+1));
                }
            }

        }
    }
    // '\'
    
    printf("ATTACK 2\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
			init_visited();
    		init_q(&stack_com);
            int blank = dfs_back_slash(i, j, 2, "1", arr, 0, &stack_com);
            if (stack_com.size - blank == 2) {
            	printf("state : %d %d",stack_com.size,blank);
                if (0 < i && 0 < j &&arr[j][i]=="1" && arr[j - 1][i - 1] == "0") {
                    arr[j - 1][i - 1] = "1";
                    return 2 * (19 * (i-1) + (j-1));
                }
                else if (i < 18 && j < 18 &&arr[j][i]=="1" && arr[j + 1][i + 1] == "0") {
                    arr[j + 1][i + 1] = "1";
                    return 2 * (19 * (i+1) + (j+1));
                }
            }

        }
    }

    // '/'
    
    printf("ATTACK 2\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_slash(i, j, 2, "1", arr, 0,&stack_com);
            if (stack_com.size - blank == 2) {
            	printf("state : %d %d",stack_com.size,blank);
                if (i < 18 && 0 < j && arr[j][i]=="1" && arr[j - 1][i + 1] == "0") {
                    arr[j - 1][i + 1] = "1";
                    return 2 * (19 * (j-1) + (i+1)); 
                }
                else if (0 < i && j < 18 && arr[j][i]=="1" && arr[j + 1][i - 1] == "0") {
                    arr[j + 1][i - 1] = "1";
                    return 2 * (19 * (i-1) + (j+1));
                }
            }
        }
    }
    //1개인게 있우면 2개
    //가로
    
    printf("ATTACK 1\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
    		printf("fuck : %s %s\n",arr[8][7],arr[8][8]);
            int blank = dfs_row(i, j, 1, "1", arr, 0,&stack_com);
            if (stack_com.size - blank == 1) {
            printf("%d %d : stack : %d, blank : %d\n",i,j,stack_com.size,blank);
                if (0 < i && arr[j][i]=="1" && arr[j][i - 1] == "0") {
                    arr[j][i - 1] = "1";
                    return 2 * (19 * (i-1) + (j));
                }
                else if (i < 18 && arr[j][i]=="1" && arr[j][i + 1] == "0") {
                    arr[j][i + 1] = "1";
                    return 2 * (19 * (i+1) + (j));
                }
            }

        }
    }
    //세로
    
    printf("ATTACK 1\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_col(i, j, 1, "1", arr, 0, &stack_com);
            if (stack_com.size - blank == 1) {
            printf("%d %d : stack : %d, blank : %d\n",i,j,stack_com.size,blank);
                if (0 < j && arr[j][i]=="1" && arr[j - 1][i] == "0") {
                    arr[j - 1][i] = "1";
                    return 2 * (19 * (i) + (j-1));
                }
                else if (j < 18 && arr[j][i]=="1" && arr[j + 1][i] == "0") {
                    arr[j + 1][i] = "1";
                    return 2 * (19 * (i) + (j+1));
                }
            }
        }
    }
    // '\'
    
    printf("ATTACK 1\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_back_slash(i, j, 1, "1", arr, 0,&stack_com);
            if (stack_com.size - blank == 3) {
            	printf("%d %d : stack : %d, blank : %d\n",i,j,stack_com.size,blank);
                if (0 < i && 0 < j && arr[j - 1][i - 1] == "0") {
                    arr[j - 1][i - 1] = "1";
                    return 2 * (19 * (i-1) + (j-1));
                }
                else if (i < 18 && j < 18 && arr[j + 1][i + 1] == "0") {
                    arr[j + 1][i + 1] = "1";
                    return 2 * (19 * (i+1) + (j+1));
                }
            }
        }
    }

    // '/'
    
    printf("ATTACK 1\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
        	init_visited();
    		init_q(&stack_com);
            int blank = dfs_slash(i, j, 1, "1", arr, 0, &stack_com);
            if (stack_com.size - blank == 1) {
            	printf("%d %d : stack : %d, blank : %d\n",i,j,stack_com.size,blank);
                if (i < 18 && 0 < j && arr[j - 1][i + 1] == "0") {
                    arr[j - 1][i + 1] = "1";
                    return 2 * (19 * (i+1) + (j-1));
                }
                else if (0 < i && j < 18 && arr[j + 1][i - 1] == "0") {
                    arr[j + 1][i - 1] = "1";
                    return 2 * (19 * (i-1) + (j+1));
                }
            }
        }
    }
    //가운데 9칸에 놔
    printf("ATTACK 0\n");
    for (int i = 8; i <= 10; i++) {
        for (int j = 8; j <= 10; j++) {
            if (arr[j][i]=="0"){
                arr[j][i] = "1";
                return 2 * (19 * (i) + (j));
            }

        }
    }
}
