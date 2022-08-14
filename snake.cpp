#include <iostream>
#include "snake.h"
using namespace std;

int W = 52;
int H = 22;

char map[22][52];//�����ͼ
char key;//���������û�����ʱ����ļ�ֵ

int direct = 4;//�ߵ�ǰ���˶�����
int food[2];//food[0]ʳ�������  food[1]ʳ��������
int head;//��¼����

int snake[400][3];
/*
���˼·��

�ߵ�����������Լ�������(snake[i][0]=0)��
��ͷ(snake[i][0]=1)
��β����ͷ����
*/



// ��ʼ��
void init(char map[22][52], int snake[400][3]) 
{
	//��ʼ����
	snake[0][0] = 1, snake[0][1] = 9, snake[0][2] = 9;//��ͷ
	//��ʼ��ʳ��
	srand(time(0));
	food[0] = rand() % 19 + 2;
	food[1] = rand() % 49 + 2;//food[0]ʳ�������  food[1]ʳ��������
	//��ʼ����ͼ
	for (int i = 0; i < H; i++) 
	{
		for (int j = 0; j < W; j++) 
		{
			if (i == 0 || j == 0 || i == H - 1 || j == W - 1) 
			{
				map[i][j] = '*';
			}
			else 
			{
				map[i][j] = ' ';
			}
		}
	}
}

void getKey() 
{
	if (_kbhit()) 
	{
		key = _getch();
	}
	switch (key) 
	{
	case 'H'://�û��� �� ��
		if (direct != 2)
			direct = 1;
		break;
	case 'P'://�û��� �� ��
		if (direct != 1)
			direct = 2;
		break;
	case 'K'://�û��� �� ��
		if (direct != 4)
			direct = 3;
		break;
	case 'M'://�û��� �� ��
		if (direct != 3)
			direct = 4;
		break;
	}
}


// ����
void move(int snake[400][3], int direct) 
{
	int x, y;//��Ϊ��ʱ������ֵ  headΪ��ͷ
	for (int i = 0; i < 400; i++) 
	{
		if (snake[i][0] == 1) 
		{
			head = i;
			break;
		}
	}
	//�ҵ�ͷ����ͷ�����걣��������һ��������
	x = snake[head][1];
	y = snake[head][2];
	switch (direct) {
	case 1://����
		snake[head][1]--;//�����겻�䣬������-1
		break;
	case 2://����
		snake[head][1]++;//�����겻�䣬������+1
		break;
	case 3://����
		snake[head][2]--;//�����겻�䣬������-1
		break;
	case 4://����
		snake[head][2]++;//�����겻�䣬������+1
		break;
	}
	//ͷ�Ѿ�������һ��λ�ã����ж��Ƿ��Ե�ʳ�����֮ǰ������
	if (ifEat(head, food)) 
	{
		snake[head + 1][0] = 1, snake[head + 1][1] = food[0], snake[head + 1][2] = food[1];//���¶�����ͷ
		snake[head][0] = 0;//ȡ��֮ǰ����ͷ
		food[0] = 0, food[1] = 0;//����ǰ��food�ÿ�
		switch (direct) 
		{
		case 1://����
			snake[head][1]++;//�����겻�䣬������-1
			break;
		case 2://����
			snake[head][1]--;//�����겻�䣬������+1
			break;
		case 3://����
			snake[head][2]++;//�����겻�䣬������-1
			break;
		case 4://����
			snake[head][2]--;//�����겻�䣬������+1
			break;
		}
	}
	else
		for (int j = head - 1; j >= 0; j--) 
		{
			int temp;
			temp = x, x = snake[j][1], snake[j][1] = temp;
			temp = y, y = snake[j][2], snake[j][2] = temp;
		}
}

//��
int ifEat(int head, int food[2]) 
{
	if (snake[head][1] == food[0] && snake[head][2] == food[1])
		return 1;
	else
		return 0;
}

// ����ʳ��
void makeFood(int food[]) 
{
	srand(time(0));
	int x = rand() % 49 + 2, y = rand() % 19 + 2;//����һ��1-50������Ϊ������  1-20������Ϊ������
	while (ifReprat(snake, x, y)) 
	{//������ظ�����������һ��  ֱ�����ظ�Ϊֹ
		x = rand() % 49 + 2, y = rand() % 19 + 2;
	}
	food[0] = y;
	food[1] = x;
}

//�ж��Ƿ����ظ�����
int ifReprat(int snake[400][3], int x, int y) 
{
	for (int i = 0; i < 400; i++) 
	{
		if ((snake[i][1] == x && snake[i][2] == y))
		{//���ظ�����
			return 1;
			if (snake[i][0] == 1) break;
		}
	}
	return 0;
}

// ���Ƶ�ͼ
void makeMap(char map[22][52], int snake[400][3], int food[]) 
{
	int i;
	//���³�ʼ����ͼ
	for (int i = 0; i < H; i++) 
	{
		for (int j = 0; j < W; j++) 
		{
			if (i == 0 || j == 0 || i == H - 1 || j == W - 1)
			{
				map[i][j] = '*';
			}
			else 
			{
				map[i][j] = ' ';
			}
		}
	}
	//���»�����
	for (i = 0; i < 400; i++)
	{
		if (snake[i][0] == 1) break;
		map[snake[i][1]][snake[i][2]] = '#';
	}
	//����ͷ��ʳ��
	map[snake[i][1]][snake[i][2]] = '@';
	map[food[0]][food[1]] = '$';
}

void showView(char map[22][52]) 
{
	for (int i = 0; i < H; i++) 
	{
		for (int j = 0; j < W; j++) 
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}


// �ж��Ƿ�ײ
int ifBump(int head) 
{
	if ((snake[head][2] == 0 || snake[head][2] == 51) || (snake[head][1] == 0 || snake[head][1] == 21))//ײǽ
		return 1;
	for (int i = 0; i < head - 3; i++)
	{
		if ((snake[i][1] == snake[head][1] && snake[i][2] == snake[head][2])) 
		{//ײ�Լ�
			return 1;
		}
	}
	return 0;
}