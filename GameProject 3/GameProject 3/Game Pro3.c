#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
void startup(); 
void show(); 
void updateWithoutinput(); 
void updateWithinput();
void gotoxy(int x, int y);
void HindCursor();
int position_x;
int position_y;
int bullet_x;
int bullet_y;
int enemy_x;
int enemy_y;
int high;
int width;
int scores;
int main() {
	startup();//��ʼ��
	HindCursor();
	while (1) {
		show();
		updateWithoutinput();
		updateWithinput();
	}
	return 0;
}
void startup() {
	bullet_x = position_x;
	bullet_y = -1;
	enemy_x = 15;
	enemy_y = 0;
	high = 40;
	width = 30;
	position_x= width/2;
	position_y= high/2;
}
void show() {
	gotoxy(0, 0);
	int i, j;
	//i������
	for (i = 0; i <= high;i++) {
		//j������
		for (j = 0; j <= width;j++) {
			if (i == position_y && j == position_x) {
				printf("*");
			}
			else if (i == bullet_y && j == bullet_x) {
				printf("|");
			}
			else if (i == enemy_y && j == enemy_x){
				printf("#");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("�÷�Ϊ%d", scores);
}
void updateWithoutinput() {
	static int speed = 0;
	if (bullet_y>-1) {
		bullet_y--;
	}
	if (speed < 10) {
		speed++;
	}
	if (speed == 10) {
		enemy_y++;
		speed = 0;
	}
	//���ел�
	if (bullet_x == enemy_x && bullet_y == enemy_y) {
		scores++;
		enemy_y = -1;//�����µл�
		enemy_x = rand() % 30;
		bullet_y = -2;//�ӵ���Ч
	}
	if (enemy_y > 40) {
		scores--;
		enemy_y = -1;//�����µл�
		enemy_x = rand() % 30;
	}
}
void updateWithinput() {
	char input;
	if (_kbhit()) {
		input = _getch();
		if (input == 'w') {
			position_y--;
		}
		else if (input == 's') {
			position_y++;
		}
		else if (input == 'a') {
			position_x--;
		}
		else if (input == 'd') {
			position_x++;
		}
		else if (input == ' ') {
			bullet_y = position_y-1;
			bullet_x = position_x;
		}
	}
	position_x = (position_x < 0) ? 0 : (position_x > width) ? width : position_x;
	position_y = (position_y < 0) ? 0 : (position_y > high) ? high : position_y;
}
void gotoxy(int x, int y) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
void HindCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };//�ڶ���ֵΪ0��ʾ���ع��
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
