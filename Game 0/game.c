#include"game.h"
int clear_flag[ROWS][COLS] = { 0 };//�Ƿ�clear����ȫ�ֱ�����
void menu() {
	printf("-------1.play    -------\n");
	printf("-------0.exit    -------\n");
	printf("------------------------\n");
	printf("------------------------\n");
}
void game() {
	int n = 0;
	int m = 0;
	for (n = 0; n < ROWS;n++) {
		for (m = 0; m < COLS;m++) {
			clear_flag[n][m] = 0;
		}
	}//��ʼ��clear����
	char show[ROWS][COLS] = {'0'};//ʹ���±�1-9
	char mine[ROWS][COLS] = {'0'};//ʹ���±�1-9
	int row = ROW;
	int col = COL;
	char showch = '*';
	char minech = '0';
	Init(show, row, col,showch);//��ʼ��ȫΪ*
	Init(mine, row, col,minech);//��ʼ������0����1
	Display(show, row, col);
	SetMine(mine, row, col);
	Display(mine,row,col);
	FindMine(mine,show,row,col);
}
void Init(char board[ROWS][COLS], int x, int y,char ch) {
	int m = 0;
	int n = 0;
	for (m = 0; m <=ROWS-1;m++) {
		for (n =0; n <=COLS-1; n++) {
			board[m][n] = ch;
		}
	}
}
void Display(char board[ROWS][COLS], int x, int y) {
	printf("----------------ɨ��----------------\n");
	int m = 0;
	int n = 0;
	
	for (m = 0; m <= x; m++) {
		printf("%d ", m);
	}
	printf("\n");
	for (m = 1; m <= x; m++) {
		printf("%d ", m);
		for (n = 1; n <= y; n++) {
			printf("%c ", board[m][n]);
		}
			printf("\n");
	}
	printf("----------------ɨ��----------------\n");
}
void SetMine(char board[ROWS][COLS], int x, int y) {
	int bomb = Easy_Count;
	do {
		int m = rand() % ROW+1;
		int n = rand() % COL+1;
		if (m >= 1 && m <= ROW && n >= 1 && n <=COL) {
			if (board[m][n] !='1') {
				board[m][n] = '1';
				bomb--;
			}
		}
	} while (bomb);
}

void FindMine(char board_mine[ROWS][COLS], char board_show[ROWS][COLS], int x, int y) {
	int win = Easy_Count;
	do {
		printf("�������� ͬʱ����100����Mark Mode\n");
		scanf_s("%d %d", &x, &y);
		//Mark Mode
		if (x == 100 && y == 100) {
			do {
				printf("Mark Mode ����������\n");
				printf("ͬʱ����-100�˳�\n");
				scanf_s("%d %d", &x, &y);
				//�Ƿ��һ����ȷ����ը��
				if (board_mine[x][y] == '1' && board_show != '#')
				{
					board_show[x][y] = '#';
					win--;
					Display(board_show, ROW, COL);
				}
				else if (board_show != '#')
				{
					board_show[x][y] = '#';
					Display(board_show, ROW, COL);
					
				}
				if (x == -100 && y == -100)
				{
					break;
				}
			} while (1);
		}
		int tmp = 100;
		tmp = is_bomb(board_mine, board_show, x, y);
		//����ը��
		if (tmp == 0) {
			bomb_clear(board_mine, board_show, x, y);
			Display(board_show, ROW, COL);
		}
		//��ը��
		else if (tmp == 1) {
			printf("��ը�����㱻ը���ˣ���Ϸ����\n");
			Display(board_show, ROW, COL);
			break;
		}
	} while (win);
	if (win == 0)
		printf("��Ϸ����\n");
}

void bomb_clear(char board_mine[][COLS], char board_show[][COLS], int x, int y)
{	//�ж��Ƿ�clear�� 0Ϊû��clear 1Ϊclear����
	if (clear_flag[x][y] == 0) {
		clear_flag[x][y] = 1;
		int num = 0;
		if (!is_bomb(board_mine, board_show, x, y)) {
			num = count_bomb(board_mine, x, y);
			if (num == 0) {
				int i = 0;
				int j = 0;
				board_show[x][y] = num + '0';//��ӡ0
				for (i = x - 1; i <= x + 1; i++) {
					for (j = y - 1; j <= y + 1; j++)
					{
						if (i >= 1 && i <= ROW && j >= 1 && j <= COL && !(i == x && j == y))
							bomb_clear(board_mine, board_show, i, j);
					}

				}
			}
			else if (num != 0) {
				board_show[x][y] = num + '0';
			}//��ӡ��0
		}
		
	}
	else if (clear_flag[x][y] == 1)
	{
	}
}

int is_bomb(char board_mine[][COLS], char board_show[][COLS], int x, int y) {
	if (board_mine[x][y] == '1')
		return 1;
	else if (board_mine[x][y] == '0')
		return 0;
}

int count_bomb(char board_mine[ROWS][COLS], int x, int y) {
	int i = 0;
	int j = 0;
	int count = 0;
	int temp = 0;
	for (i = x - 1; i <= x + 1; i++) {
		for (j = y - 1; j <= y + 1; j++) {
			if (board_mine[i][j] == '1') {
				count++;
			}
			
		}
		

	}
	return count;
}
	
		
			
		

	

	