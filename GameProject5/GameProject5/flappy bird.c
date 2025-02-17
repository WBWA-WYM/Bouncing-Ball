#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include <WinBase.h>
#include <wincontypes.h>
void startup();
void DateupWithInput();
void DateupWithoutInput();
void show();
int bird_x, bird_y;
int block_x, block_y_up, block_y_down;
int i, j;
int width, high;
char input = '0';
int speed = 0;
int crack;
int scores;
int main() {
	startup();
	while (1) {
		show();
		DateupWithInput();
		DateupWithoutInput();
	}
	return 0;
}
void startup() {
	crack = 4;
	high = 20;
	width = 20;
	bird_x = 3;
	bird_y = 7;
	block_x = 21;
	block_y_up = 8;
	block_y_down = 12;
	i = 0;
	j = 0;
	scores = 0;
}
void DateupWithInput() {
	if (_kbhit()) {
		//按空格小鸟上升
		input = _getch();
		if (input) {
			bird_y--;
			input = '0';
		}
	}
}
void DateupWithoutInput() {
	while (crack = (block_y_down - block_y_up) != 4) {
		block_y_down = rand() % 20;
		block_y_up = rand() % 20;
	}
	if (speed < 10) {
		speed++;
	}
	if (speed == 3) {
		speed = 0;
		bird_y++;
	}
	if (block_x > -1) {
		block_x--;
		Sleep(50);
	}
	else if (block_x == -1) {
		block_x = 21;
		block_y_down = rand() % 20;
		block_y_up = rand() % 20;
	}
	if (bird_x == block_x) {
		if (bird_y >= block_y_down || bird_y <= block_y_up) {
			printf("游戏结束\n");
			system("pause");
			exit(0);
		}
		else {
			scores++;
		}
	}
}
void show() {
	system("cls");
	for (i = 0; i < high;i++) {
		for (j = 0; j < width;j++) {
			if (j == bird_x && i == bird_y) {
				printf("@");
			}
			else if ((j == block_x) && (i <= block_y_up || i>=block_y_down)) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("The Scores is %d", scores);
}