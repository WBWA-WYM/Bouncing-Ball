#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
void startup();
void DateupWithInput();
void DateupWithoutInput();
void show();
int velocity_x, velocity_y;
int bottom,top;
int left, right;
int ball_x, ball_y;
int i, j;
int m, n;
int position_x;
int position_y;
int ridus;
int coin_x, coin_y;
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
	velocity_x = 1;
	velocity_y = 1;
	bottom = 30;
	top = 0;
	left = 0;
	right = 30;
	ball_x = rand()%30-1;
	ball_y =15;
	position_x=15;
	position_y=25;
	ridus=6;
	//更新coin
	coin_x = rand() % 30;
	coin_y = rand() % 10;
	srand((unsigned)time(NULL));
}
void DateupWithInput() {
	char input;
	if (_kbhit()) {
		input = _getch();
		if (input=='w') {
			position_y--;
		}
		if (input == 's') {
			position_y++;
		}
		if (input == 'a') {
			position_x--;
		}
		if (input == 'd') {
			position_x++;
		}
	}
}
void DateupWithoutInput() {
		system("cls");
		//更新位置 
		ball_x = ball_x + velocity_x;
		ball_y = ball_y + velocity_y;

		//检测是否碰撞
		if (ball_x == left || ball_x == right) {
			velocity_x = -velocity_x;
			printf("\a");
		}
		if (ball_y == top || ball_y == bottom) {
			velocity_y = -velocity_y;
			printf("\a");
		}
		if ((ball_y == position_y) && ((ball_x < position_x + ridus) && ball_x > (position_x - ridus))) {
			velocity_y = -velocity_y;
			printf("\a");
		}
		if (ball_y == coin_y && ball_y == coin_x) {
			coin_x = rand() % 30;
			coin_y = rand() % 10;
			scores++;
		}
}
void show() {
	//i控制行
	for (i = 0; i <= bottom; i++) {
		//j控制列
		for (j = 0; j <= right; j++) {
			if ((i==top||i==bottom)&&(j==left||j==right)) {
				printf("+");
			}
			else if (i == top || i == bottom) {
				printf("-");
			}
			else if (j==right||j==left) {
				printf("|");
			}
			else if ((j == ball_x) && (i == ball_y)) {
				printf("o");
			}
 			else if (i==position_y && j<= position_x + ridus && j>=position_x - ridus) {
				printf("#");
			}
			else if (j==coin_x&&i==coin_y) {
				printf("B");
			}
			
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("The scores is %d", scores);
	Sleep(50);
}
