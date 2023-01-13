#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//符号的定义
#define row 3
#define col 3
#define ROW 9
#define COL 9

//函数的声明
void init_broad(char board[row][col], int a, int b);
void init_broad2(char board[ROW + 2][COL + 2], int a, int b,char set);
void display_board(char board[row][col], int a, int b,int c);
void player(char board[row][col], int a, int b);
void computer(char board[row][col], int a, int b);
int judge(char board[row][col], int a, int b);
void dig_boom(char board[ROW + 2][COL + 2], int a, int b, int c);
void show_boom(char board[ROW + 2][COL + 2], int a, int b);
int find_boom(char board1[ROW + 2][COL + 2], char board2[ROW + 2][COL + 2],int a, int b);
int judge_boom(char board[ROW + 2][COL + 2], int a, int b,char set);
int mark_boom(char board1[ROW + 2][COL + 2], char board2[ROW + 2][COL + 2], int a, int b);
int demark_boom(char board1[ROW + 2][COL + 2], char board2[ROW + 2][COL + 2], int a, int b);