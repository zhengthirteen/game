#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void manu(void)
{
	printf("*************************\n");
	printf("******1. 三子棋   *******\n");
	printf("******2. 扫雷     *******\n");
	printf("******0. 退出游戏  ******\n");
	printf("*************************\n");
}
void game_1(void)
{
	char board[row][col];
	init_broad(board,row,col);//初始化棋盘
	display_board(board, row, col,0);//打印棋盘
	int a,b=0;
	printf("\n1.玩家先手\n2.电脑先手\n请选择:");
	scanf("%d",&a);
	printf("下棋时输入坐标，形如a,b\n");
	if (a == 1)
	{
		while(1)
		{
			player(board, row, col);
			display_board(board, row, col,0);
			b = judge(board, row, col);
			if (b ==1)
			{
				printf("玩家胜\n\n");
				break;
			}
			else if (b ==-1)
			{
				printf("玩家负\n\n");
				break;
			}
			else if (b == 2)
			{
				printf("平局\n\n");
				break;
			}
			printf("\n");
			computer(board, row, col);
			display_board(board, row, col,0);
			b = judge(board, row, col);
			if (b == 1 )
			{
				printf("玩家胜\n\n");
				break;
			}
			else if (b == -1 )
			{
				printf("玩家负\n\n");
				break;
			}
			else if (b == 2)
			{
				printf("平局\n\n");
				break;
			}
		}
	}
	else if (a == 2)
	{
		while (1)
		{
			computer(board, row, col);
			display_board(board, row, col,0);
			b = judge(board, row, col);
			if (b ==1)
			{
				printf("玩家胜\n\n");
				break;
			}
			else if (b ==-1)
			{
				printf("玩家负\n\n");
				break;
			}
			else if (b == 2)
			{
				printf("平局\n\n");
				break;
			}
			player(board, row, col);
			display_board(board, row, col,0);
			b = judge(board, row, col);
			if (b == 1)
			{
				printf("玩家胜\n\n");
				break;
			}
			else if (b == -1)
			{
				printf("玩家负\n\n");
				break;
			}
			else if(b==2)
			{
				printf("平局\n\n");
				break;
			}
			printf("\n");
		}
	}
}
void game_2(void)
{
	int a,x;
	int sum = 0;
	printf("默认9*9，10颗雷\n");
		char mine[ROW + 2][COL + 2], show[ROW + 2][COL + 2];
		init_broad2(mine, 11, 11,'0');
		init_broad2(show, 11, 11,'*');
		dig_boom(mine, 11, 11, 10);
		show_boom(show, 9, 9);
		printf("请输入坐标，形如a,b:");
		a = find_boom(mine, show, 11, 11);
		show_boom(show, 9, 9);
		if (a)
			return;
		do 
		{
			printf("1.继续排雷\n2.标记雷\n3.取消标记雷\n请选择:");
				scanf("%d", &x);
			switch (x)
			{
			case 1:
				printf("请输入坐标：");
				a = find_boom(mine, show, 11, 11);
				show_boom(show, 9, 9);
				if (a)
					return;
				break;
			case 2:
				printf("请输入坐标:");
				sum=sum+mark_boom(mine,show, 9, 9);
				show_boom(show, 9, 9);
				break;
			case 3:
				printf("请输入坐标:");
				sum=sum+demark_boom(mine, show, 9, 9);
				show_boom(show, 9, 9);
				break;
			default:
				printf("输入错误，请重试\n");
			}
			if (judge_boom(show, 9, 9, '@') && sum == 10)
			{
				printf("恭喜您，游戏胜利\n");
				return;
			}
		} while (1);
}
int main(void)
{
	int a;
	srand((unsigned int)time(NULL));
	do
	{
		manu();
		printf("请输入序号\n");
		scanf("%d",&a);
		switch (a)
		{
		case 1:
			game_1();
			break;
		case 2:
			game_2();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，重新输入\n");
			break;
		}
	} while (a != 0);
	return 0;
}