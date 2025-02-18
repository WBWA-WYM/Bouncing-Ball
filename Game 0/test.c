#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
#include<stdio.h>
int main() {
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		printf("请输入:>\n");
		menu();
		scanf_s("%d", &input);
		switch (input) {
		case 1:
			printf("扫雷游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}
