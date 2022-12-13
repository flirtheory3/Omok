#include "dfs.h"
#include "check.h"

Queue stack;
int check33(char* arr[19][20], char* user_id, int x, int y) {
    int num = 0;
    int blank = 0;
    init_visited();
    init_q(&stack);
    
    blank = dfs_row(x, y, 3, user_id, arr,0,&stack);
    

    if (stack.size - blank == 3) {
        num++;
    }

    init_visited();
    init_q(&stack);

    blank = dfs_col(x, y, 3, user_id, arr,0,&stack);
    
    if (stack.size - blank == 3) {
        num++;
    }

    init_visited();
    init_q(&stack);

    blank = dfs_back_slash(x, y, 3, user_id, arr,0,&stack);
    
    if (stack.size - blank == 3) {
        num++;
    }

    init_visited();
    init_q(&stack);

    blank = dfs_slash(x, y, 3, user_id, arr, 0,&stack);
    
    if (stack.size - blank == 3) {
        num++;
    }

    if (num >= 2) {
        return 0;
    }

    return 1;
}

int check44(char* arr[19][20], char* user_id, int x, int y) {
    int num = 0;
    int blank =0;
    init_visited();
    init_q(&stack);
    
    blank = dfs_row(x, y, 4, user_id, arr,0,&stack);
    

    if (stack.size - blank == 4) {
        num++;
    }
    printf("stack_size : %d blank : %d num : %d\n", stack.size,blank,num);
    init_visited();
    init_q(&stack);

    blank = dfs_col(x, y, 4, user_id, arr,0,&stack);
    
    if (stack.size - blank == 4) {
        num++;
    }

    init_visited();
    init_q(&stack);

    blank = dfs_back_slash(x, y, 4, user_id, arr,0,&stack);
    
    if (stack.size - blank == 4) {
        num++;
    }

    init_visited();
    init_q(&stack);

    blank = dfs_slash(x, y, 4, user_id, arr, 0,&stack);
    
    if (stack.size - blank == 4) {
        num++;
    }

    if (num >= 2) {
        return 0;
    }

    return 1;
}

int check(char* arr[19][20],char* user_id, int x, int y) {
    char* tmp[19][20];
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if(strcmp(arr[i][j],"@")==0){
            	tmp[j][i] = "1";
            }
            else if(strcmp(arr[i][j],"0")==0){
            	tmp[j][i] = "2";
            }
            else{
            	tmp[j][i] = "0";
            }
        }
    }
    
    /*for(int i=0;i<10; i++){
    	for(int j=0;j<19;j++){
    		printf("%s",arr[i][j]);
    	}
    	printf("\n");
    }*/
    tmp[y][x] = user_id;
    /*for(int i=0;i<10; i++){
    	for(int j=0;j<19;j++){
    		printf("%s",tmp[j][i]);
    	}
    	printf("\n");
    }*/
    if (!check33(tmp,user_id,x,y)) {
        return 33;
    }
    
    else if (!check44(tmp,user_id ,x, y)) {
        return 44;
    }
    
    return 1;
}
