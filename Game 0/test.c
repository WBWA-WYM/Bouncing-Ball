#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
#include<stdio.h>
int main() {
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		printf("������:>\n");
		menu();
		scanf_s("%d", &input);
		switch (input) {
		case 1:
			printf("ɨ����Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
}
