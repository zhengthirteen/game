#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void manu(void)
{
	printf("*************************\n");
	printf("******1. ������   *******\n");
	printf("******2. ɨ��     *******\n");
	printf("******0. �˳���Ϸ  ******\n");
	printf("*************************\n");
}
void game_1(void)
{
	char board[row][col];
	init_broad(board,row,col);//��ʼ������
	display_board(board, row, col,0);//��ӡ����
	int a,b=0;
	printf("\n1.�������\n2.��������\n��ѡ��:");
	scanf("%d",&a);
	printf("����ʱ�������꣬����a,b\n");
	if (a == 1)
	{
		while(1)
		{
			player(board, row, col);
			display_board(board, row, col,0);
			b = judge(board, row, col);
			if (b ==1)
			{
				printf("���ʤ\n\n");
				break;
			}
			else if (b ==-1)
			{
				printf("��Ҹ�\n\n");
				break;
			}
			else if (b == 2)
			{
				printf("ƽ��\n\n");
				break;
			}
			printf("\n");
			computer(board, row, col);
			display_board(board, row, col,0);
			b = judge(board, row, col);
			if (b == 1 )
			{
				printf("���ʤ\n\n");
				break;
			}
			else if (b == -1 )
			{
				printf("��Ҹ�\n\n");
				break;
			}
			else if (b == 2)
			{
				printf("ƽ��\n\n");
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
				printf("���ʤ\n\n");
				break;
			}
			else if (b ==-1)
			{
				printf("��Ҹ�\n\n");
				break;
			}
			else if (b == 2)
			{
				printf("ƽ��\n\n");
				break;
			}
			player(board, row, col);
			display_board(board, row, col,0);
			b = judge(board, row, col);
			if (b == 1)
			{
				printf("���ʤ\n\n");
				break;
			}
			else if (b == -1)
			{
				printf("��Ҹ�\n\n");
				break;
			}
			else if(b==2)
			{
				printf("ƽ��\n\n");
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
	printf("Ĭ��9*9��10����\n");
		char mine[ROW + 2][COL + 2], show[ROW + 2][COL + 2];
		init_broad2(mine, 11, 11,'0');
		init_broad2(show, 11, 11,'*');
		dig_boom(mine, 11, 11, 10);
		show_boom(show, 9, 9);
		printf("���������꣬����a,b:");
		a = find_boom(mine, show, 11, 11);
		show_boom(show, 9, 9);
		if (a)
			return;
		do 
		{
			printf("1.��������\n2.�����\n3.ȡ�������\n��ѡ��:");
				scanf("%d", &x);
			switch (x)
			{
			case 1:
				printf("���������꣺");
				a = find_boom(mine, show, 11, 11);
				show_boom(show, 9, 9);
				if (a)
					return;
				break;
			case 2:
				printf("����������:");
				sum=sum+mark_boom(mine,show, 9, 9);
				show_boom(show, 9, 9);
				break;
			case 3:
				printf("����������:");
				sum=sum+demark_boom(mine, show, 9, 9);
				show_boom(show, 9, 9);
				break;
			default:
				printf("�������������\n");
			}
			if (judge_boom(show, 9, 9, '@') && sum == 10)
			{
				printf("��ϲ������Ϸʤ��\n");
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
		printf("���������\n");
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
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("���������������\n");
			break;
		}
	} while (a != 0);
	return 0;
}