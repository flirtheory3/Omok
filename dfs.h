#pragma once
#include <stdio.h>
#include <string.h>

typedef struct _Queue {
	char* Q[6];
	int top;
	int size;
}Queue;
void init_q(Queue*);
void push_q(Queue* ,char*);
char* pop_q(Queue*);


void init_visited();
int dfs_row(int , int , int , char*, char* arr[19][20],int,Queue*);
int dfs_col(int, int, int, char*, char* arr[19][20], int,Queue*);
int dfs_back_slash(int, int, int, char*, char* arr[19][20], int,Queue*);
int dfs_slash(int, int, int, char*, char* arr[19][20], int,Queue*);
int dfs_check_row(int, int, int, char*, char* arr[19][20], int,Queue*);
