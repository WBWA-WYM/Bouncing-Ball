#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
int main() {
	int top = 0;
	int bottom = 30;
	int left = 0;
	int right = 30;
	int x = 5;
	int y = 10;
	int i, j;
	char input = '0';
	while (1) {
		system("cls");
		for (j = 0; j <= bottom; j++) {
			for (i = 0; i <= right; i++) {
				if (i == x && j == y) {
					printf("*");
				}
				else {
					printf(" ");
				}
			}
			printf("\n");
		}
		if (_kbhit()) {
				input=_getch();
				if (input == 'w') {
					y--;
				}
				else if (input == 's') {
					y++;
				}
				else if (input == 'a') {
					x--;
				}
				else if (input == 'd') {
					x++;
				}
			//±ß½çÂß¼­
					x = (x < left) ? left : (x > right) ? right : x;
					y = (y > bottom) ? bottom : (y < top) ? top : y;
		}
	}
	return 0;
}