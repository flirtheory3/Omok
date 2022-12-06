#pragma once
#include <stdio.h>

int visited[19][19];
typedef struct _Queue {
	int Q[6];
	int top;
	int size;
}Queue;
void init_q(Queue*);
void push_q(Queue* ,int);
int pop_q(Queue*);

Queue stack;
void init_visited();
int dfs_row(int , int , int , int arr[19][19],int);
int dfs_col(int, int, int, int arr[19][19], int);
int dfs_back_slash(int, int, int, int arr[19][19], int);
int dfs_slash(int, int, int, int arr[19][19], int);
int dfs_check_row(int, int, int, int arr[19][19], int);
