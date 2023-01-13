#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void init_broad(char board[row][col], int a, int b)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			board[i][j] = ' ';
		}
	}
	return;
}
void init_broad2(char board[ROW+2][COL+2], int a, int b,  char set)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			board[i][j] = set;
		}
	}
	return;
}
void display_board(char board[row][col], int a, int b,int c)
{
	printf("\n");
	for (int i = c; i < a-c; i++)
	{
		printf("%d ", a - i);
		for (int j = c; j < b-c; j++)
		{
			printf(" %c ",board[i][j]);
			if(j<b-1-c)
				printf("|");
		}
		printf("\n  ");
		if (i < a - 1 - c)
		{
			for (int j = c; j < b-c; j++)
			{
				printf("----");
			}
			printf("\n");
		}
	}
	for (int i = 0; i < a-2*c; i++)
	{
		printf(" %d  ", i+1);
	}
	printf("\n");
	return;
}
void player(char board[row][col], int a, int b)
{
	printf("请输入落子坐标:");
	int x, y;
	scanf("%d,%d",&x,&y);
	if (a-y>=0&&a-y<=a&&x-1>=0&x-1<=b&&board[a - y][x - 1] == ' ')
	{
		board[a - y][x - 1] = '*';
		return;
	}
	printf("坐标非法，请重新输入:");
	player(board, a, b);
}
void computer(char board[row][col], int a, int b)
{
	int x, y,i,j;
	if (board[1][1] == ' ')
	{
		board[1][1] = '#';
		return;
	}
	else
	{
		for (i = 0; i < a; i++)//判断电脑横行上是否会赢
		{
			if ((board[i][0] == board[i][1])
				&& (board[i][1] == '#')
				&& (board[i][2] == ' '))
			{
				board[i][2] = '#';
				return;
			}
			if ((board[i][0] == board[i][2])
				&& (board[i][0] == '#')
				&& (board[i][1] == ' '))
			{
				board[i][1] = '#';
				return;
			}

			if ((board[i][1] == board[i][2])
				&& (board[i][1] == '#')
				&& (board[i][0] == ' '))
			{
				board[i][0] = '#';
				return;
			}
		}
		for (i = 0; i < a; i++)//判断玩家横行上是否会赢
		{
			if ((board[i][0] == board[i][1])
				&& (board[i][1] == '*')
				&& (board[i][2] == ' '))
			{
				board[i][2] = '#';
				return;
			}
			if ((board[i][0] == board[i][2])
				&& (board[i][0] == '*')
				&& (board[i][1] == ' '))
			{
				board[i][1] = '#';
				return;
			}

			if ((board[i][1] == board[i][2])
				&& (board[i][1] == '*')
				&& (board[i][0] == ' '))
			{
				board[i][0] = '#';
				return;
			}
		}
		for (j = 0; j < b; j++)//判断电脑列上是否回赢
		{
			if ((board[0][j] == board[1][j])
				&& (board[1][j] == '#')
				&& (board[2][j] == ' '))
			{
				board[2][j] = '#';
				return;
			}

			if ((board[0][j] == board[2][j])
				&& (board[2][j] == '#')
				&& (board[1][j] == ' '))
			{
				board[1][j] = '#';
				return;
			}
			if ((board[1][j] == board[2][j])
				&& (board[2][j] == '#')
				&& (board[0][j] == ' '))
			{
				board[0][j] = '#';
				return;
			}
		}
		for (j = 0; j < b; j++)//判断玩家列上是否回赢
		{
			if ((board[0][j] == board[1][j])
				&& (board[1][j] == '*')
				&& (board[2][j] == ' '))
			{
				board[2][j] = '#';
				return;
			}

			if ((board[0][j] == board[2][j])
				&& (board[2][j] == '*')
				&& (board[1][j] == ' '))
			{
				board[1][j] = '#';
				return;
			}
			if ((board[1][j] == board[2][j])
				&& (board[2][j] == '*')
				&& (board[0][j] == ' '))
			{
				board[0][j] = '#';
				return;
			}
		}
		if ((board[0][0] == board[1][1])//判断电脑对角线上是否会赢
			&& (board[1][1] == '#')
			&& (board[2][2] == ' '))
		{
			board[2][2] = '#';
			return;
		}
		if ((board[0][0] == board[2][2])
			&& (board[2][2] == '#')
			&& (board[1][1] == ' '))
		{
			board[1][1] = '#';
			return;
		}

		if ((board[1][1] == board[2][2])
			&& (board[1][1] == '#')
			&& (board[0][0] == ' '))
		{
			board[0][0] = '#';
			return;
		}
		if ((board[0][2] == board[1][1])
			&& (board[0][2] == '#')
			&& (board[2][0] == ' '))
		{
			board[2][0] = '#';
			return;
		}

		if ((board[0][2] == board[2][0])
			&& (board[2][0] == '#')
			&& (board[1][1] == ' '))
		{
			board[1][1] = '#';
			return;
		}
		if ((board[1][1] == board[2][0])
			&& (board[2][0] == '#')
			&& (board[0][2] == ' '))
		{
			board[0][2] = '#';
			return;
		}
		if ((board[0][0] == board[1][1])//判断玩家对角线上是否会赢
			&& (board[1][1] == '*')
			&& (board[2][2] == ' '))
		{
			board[2][2] = '#';
			return;
		}
		if ((board[0][0] == board[2][2])
			&& (board[2][2] == '*')
			&& (board[1][1] == ' '))
		{
			board[1][1] = '#';
			return;
		}

		if ((board[1][1] == board[2][2])
			&& (board[1][1] == '*')
			&& (board[0][0] == ' '))
		{
			board[0][0] = '#';
			return;
		}
		if ((board[0][2] == board[1][1])
			&& (board[0][2] == '*')
			&& (board[2][0] == ' '))
		{
			board[2][0] = '#';
			return;
		}

		if ((board[0][2] == board[2][0])
			&& (board[2][0] == '*')
			&& (board[1][1] == ' '))
		{
			board[1][1] = '#';
			return;
		}
		if ((board[1][1] == board[2][0])
			&& (board[2][0] == '*')
			&& (board[0][2] == ' '))
		{
			board[0][2] = '#';
			return;
		}
		do
		{
			x = rand() % a;
			y = rand() % b;
		} while (board[x][y] != ' ');
		board[x][y] = '#';
	}
	return;
}
int judge(char board[row][col], int a, int b)
{
	int x=0;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b - 1; j++)
		{
			if (board[i][j] == board[i][j + 1])
			{
				x = 1;
			}
			else
			{
				x = 0;
				break;
			}
		}
		if (x)
		{
			if (board[i][0] == '*')
				return 1;
			else if (board[i][0] == '#')
				return -1;
		}
	}
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < a - 1; j++)
		{
			if (board[j][i] == board[j+1][i])
			{
				x = 1;
			}
			else
			{
				x = 0;
				break;
			}
		}
		if (x)
		{
			if (board[0][i] == '*')
				return 1;
			else if (board[0][i] == '#')
				return -1;
		}
	}
	for (int i = 0, j = 0; i < a-1; i++, j++)
	{
		if (board[i][j] == board[i + 1][j + 1])
			x = 1;
		else
		{
			x = 0;
			break;
		}
	}
	if (x)
	{
		if (board[0][0] == '*')
			return 1;
		else if (board[0][0] == '#')
			return -1;
	}
	for (int i = 0, j = b-1; i < a - 1; i++, j--)
	{
		if (board[i][j] == board[i + 1][j - 1])
			x = 1;
		else
		{
			x = 0;
			break;
		}
	}
	if (x)
	{
		if (board[0][b-1] == '*')
			return 1;
		else if (board[0][b-1] == '#')
			return -1;
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if (board[i][j] == ' ')
			return 0;
		}
	}
	return 2;
}
void dig_boom(char board[ROW + 2][COL + 2], int a, int b, int c)
{
	int i = 0;
	while(i<c)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			i++;
		}
	}
	return;
}
void show_boom(char board[ROW + 2][COL + 2], int a, int b)
{
	printf("\n");
	for (int i = 1; i <=a ; i++)
	{
		printf("%d|", a+1 - i);
		for (int j = 1; j <= b; j++)
		{
			printf(" %c", board[i][j]);
		}
		printf("\n");
	}
	printf("  ");
	for (int i = 0; i < a; i++)
	{
		printf("--");
	}
	printf("\n0 ");
	for (int i = 0; i < a; i++)
	{
		printf(" %d", i + 1);
	}
	printf("\n");
	return;
}
void show(char board1[ROW + 2][COL + 2], char board2[ROW + 2][COL + 2], int a, int b)
{
	int x = 0;
	if (a >= 1 && b >= 1 && a <= 9 && b <= 9 && board2[a][b] == '*')
	{
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (board1[a + i][b + j] == '1')
					x++;
			}
		}
		if (x > 0)
		{
			board2[a][b] = x + '0';
			return;
		}
		else if (x == 0)
		{
			board2[a][b] = ' ';
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					if (a + i >= 1 && a + i <= 9 && b + j >= 1 && b + j <= 9 && board2[a + i][b + j] == '*')
					{
						show(board1, board2, a+i, b+j);
					}
				}
			}
			return;
		}
	}
	else
		return;
}
int find_boom(char board1[ROW + 2][COL + 2], char board2[ROW + 2][COL + 2], int a, int b)
{
	int x, y;
	scanf("%d,%d", &x, &y);
	if (board1[ROW + 1-y][x] == '1')
	{
		printf("抱歉，你被雷炸死了\n");
		board2[ROW + 1 - y][x] = '@';
		return 1;
	}
	else
	{
		show(board1, board2, ROW + 1 - y, x);
		return 0;
	}	
}

int judge_boom(char board[ROW + 2][COL + 2], int a, int b,char set)
{
	int m = 0;
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			if (board[i][j] == set)
				m++;
		}
	}
	if (m == 10)
		return 1;
	else
		return 0;
}

int mark_boom(char board1[ROW + 2][COL + 2], char board2[ROW + 2][COL + 2], int a, int b)
{
	int x, y;
	int z = 0;
	scanf("%d,%d", &x, &y);
	if (board1[ROW + 1 - y][x] == '1')
		z = 1;
	board2[ROW + 1 - y][x] = '@';
	return z;
}
int demark_boom(char board1[ROW + 2][COL + 2], char board2[ROW + 2][COL + 2], int a, int b)
{
	int x, y;
	int z = 0;
	scanf("%d,%d", &x, &y);
	if (board2[ROW + 1 - y][x] == '@')
	{
		board2[ROW + 1 - y][x] = '*';
		return -1;
	}
	else
		printf("该点并未标记\n");
	return 0;
}
