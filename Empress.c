#define _CRT_SECURE_NO_WARNINGS 1
//八皇后问题（回溯算法）
#include<stdio.h>
#define N 8
void Init(void);
void Show(void);
int Check(int row, int col);
void Find(int row);
char board[N + 2][N + 2];//定义一个棋盘8*8
int count = 0;
struct Pos
{
	int yos;//行偏移量
	int xos;//列偏移量
};
struct Pos pos[3] = { {-1,-1},{-1,0},{-1,1} };
int main()
{
	Init();
	Find(1);
	system("pause");
	return 0;
}
void Init(void)//初始化棋盘
{
	for (int row = 0; row < N + 2; row++)
	{
		for (int col = 0; col < N + 2; col++)
		{
			board[0][col] = '#';
			board[N + 1][col] = '#';
			board[row][0] = '#';
			board[row][N + 1] = '#';
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void Show(void)//打印棋盘
{
	for (int i = 0; i < N + 2; i++)
	{
		for (int j = 0; j < N + 2; j++)
		{
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}
int Check(int row, int col)//检查该位置是否能放置
{
	int ret = 1;
	int nr;
	int nc;
	for (int i = 0; i < 3 && ret; i++)
	{
		nr = row;
		nc = col;
		while (ret && board[nr][nc] != '#')
		{
			if (board[nr][nc] == '*')
			{
				ret = 0;
				break;
			}
			nr = nr + pos[i].yos;
			nc = nc + pos[i].xos;
		}
	}
	return ret;
}
void Find(int row)//放置
{
	if (row > N)
	{
		Show();
		count++;
		printf("%d\n", count);
	}
	else
	{
		for (int col = 1; col <= N; col++)
		{
			if (Check(row, col))
			{
				board[row][col] = '*';
				Find(row + 1);
				board[row][col] = ' ';
			}
		}
	}
}




