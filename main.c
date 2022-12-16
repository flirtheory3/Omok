#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "omokncurses.h"
#include "com.h"

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int initsem(key_t semkey) {
    union semun semunarg;
    int status = 0, semid;

    semid = semget(semkey, 1, IPC_CREAT | IPC_EXCL | 0600);
    if (semid == -1) {
        if (errno == EEXIST)
            semid = semget(semkey, 1, 0);
    }
    else {
        semunarg.val = 1;
        status = semctl(semid, 0, SETVAL, semunarg);
    }

    if (semid == -1 || status == -1) {
        perror("initsem");
        return (-1);
    }

    return semid;
}

int semlock(int semid) {
    struct sembuf buf;
	
    buf.sem_num = 0;
    buf.sem_op = -1;
    buf.sem_flg = SEM_UNDO;
    printf("%d : semlock started\n",getpid());
    
    if (semop(semid, &buf, 1) == -1) {
        perror("semlock failed");
        exit(1);
    }
    printf("%d : semlock end\n",getpid());
    return 0;
}

int semunlock(int semid) {
    struct sembuf buf;

    buf.sem_num = 0;
    buf.sem_op = 1;
    buf.sem_flg = SEM_UNDO;
    if (semop(semid, &buf, 1) == -1) {
        perror("semunlock failed");
        exit(1);
    }
    return 0;
}

void semhandle(int semid, int shmid, char* user1, char* user2, char* user_id) {
    
    
    
    pid_t pid = getpid();
	char* board[19][20];
	
	
    semlock(semid);
    
    sleep(1);
    
    char* shmaddr = shmat(shmid, (char *)NULL, 0);
    for(int i = 0; i < 19; i++){
		for(int j = 0; j < 19; j++){
			char data = shmaddr[2*(19*i+j)];
			if(data=='0'){
				board[i][j] = "+";
			}
			else if(data=='1'){
				board[i][j] = "@";
			}
			else if(data == '2'){
				board[i][j] = "0";
			}
		}
	}
    
    int pos = omokManager(user1, user2, board,user_id);
    if(pos == 0){
    	exit(0);
    }
    shmaddr[pos] = *user_id;
    
    shmdt((char *)shmaddr);
    
    semunlock(semid);
    return;
}

int main() {
	//main
    int status;
    pid_t pid[2] = {-1, -1};
    int cur_child_num = 2;
    int semid = initsem(1);
	
    int shmid = shmget(IPC_PRIVATE, 20, IPC_CREAT|0644);
    char* shmaddr = shmat(shmid, (char *)NULL, 0);
    char* init_data = "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0";
    strcpy(shmaddr,init_data);
    shmdt((char *)shmaddr);
    //ncurses definition
    char *user1;
	char *user2;
	char mesg[] = "HELLO OMOK";
	int yMax, xMax;
	int c;
	
    
    //starting screen
    initscr();
	getmaxyx(stdscr,yMax,xMax);	
	attron(A_BOLD | A_BLINK);
	mvprintw(yMax/2, (xMax-strlen(mesg))/2, "%s", mesg);
	attroff(A_BLINK);
	mvprintw(yMax/2+1, (xMax-19)/2, "%s", "Press 's' to Start");
	
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	
 	while(true){
 	c = getch();
		if (c == 's'){
			attroff(A_BOLD | A_BLINK);
			int choice = chooseModeWindow();
			if (choice == 0){
				
				break;
			}
			if(choice == 1){
				user1 = "user1";
				user2 = "user2";
				for (int a = 0; a < 2; a++){



					
					if(pid[0]!=0 && pid[1]!=0){
						pid[a] = fork();
						if(pid[0]!=0 && pid[1]!=0){

							if(a == 1){
								wait(&status);
								kill(pid[0],SIGINT);
								kill(pid[1],SIGINT);
								shmctl(shmid, IPC_RMID, (struct shmid_ds *)NULL);
								
								exit(0); 
								
							}
						
						}
						else if(pid[0] == 0 || pid[1] == 0){
							break;
						}
							
						
					}
					
					

				}
				while(pid[0] == 0){
					
					semhandle(semid,shmid,user1, user2, "1");
					

					
				}
				while(pid[1] == 0){
					
					semhandle(semid,shmid, user1, user2, "2");
					

				}
				while(1);
				
			}
			 else {
				break;
			}
		} 
	}
    
    
	endwin();
}
