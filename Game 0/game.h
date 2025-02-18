#pragma once
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define ROW 9
#define COL 9
#define ROWS 11
#define COLS 11
#define Easy_Count 5
#include<stdlib.h>
#include<time.h>

void Init(char board[ROWS][COLS], int x, int y, char ch);
void game();
void menu();
void Display(char board[][COLS], int x, int y);
void SetMine(char board[ROWS][COLS], int x, int y);
void FindMine(char board_mine[ROWS][COLS], char board_show[ROWS][COLS], int x, int y);
void bomb_clear(char board_mine[][COLS], char board_show[][COLS], int x, int y);
int count_bomb(char board_mine[][COLS], int x, int y);
int is_bomb(char board_mine[][COLS], char board_show[][COLS], int x, int y);