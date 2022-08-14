#include <iostream>
#include "snake.h"
using namespace std;

int main() 
{
	init(map, snake);
	while (1) 
	{
		getKey();
		system("cls");
		Sleep(33);
		move(snake, direct);//移动蛇
		if (!food[0] && !food[1]) 
		{
			makeFood(food);//生成食物
		}
		makeMap(map, snake, food);
		showView(map);
		if (ifBump(head))
		{
			cout << "GameOver!" << " " << "Your score is : " << head << endl;
			break;
		}
		getKey();
	}
	getchar();
	return 0;
}