#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int main() {
	int velocity_x = 1;
	int velocity_y = 1;
	int bottom = 30;
	int top = 0;
	int left = 0;
	int right = 30;
	int x = 1;
	int y = 10;
	int i, j;
	int m, n;
	while (1) {
		system("cls");
		//更新位置 
		x = x + velocity_x;
		y = y + velocity_y;
		//检测是否碰撞
		if (x == top || x == bottom) {
			velocity_x = -velocity_x;
			printf("\a");
		}
		if (y == left || y == right) {
			velocity_y = -velocity_y;
			printf("\a");
		}
		for (i = 0; i <= bottom; i++) {
			for (j = 0; j <= right; j++) {
				if (i == top || i == bottom) {
					printf("#");
				}
				else if (j == left || j == right) {
					printf("#");
				}
				else if (j == x && i == y) {
					printf("o");
				}
				else {
					printf(" ");
				}
			}
			printf("\n");
		}
		Sleep(20);
}
	return 0;
}
