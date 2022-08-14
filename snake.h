#pragma once
#include <cstdio>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

extern int W;
extern int H;

extern char map[22][52];
extern char key;

extern int direct;
extern int food[2];
extern int head;

extern int snake[400][3];

void init(char map[22][52], int snake[400][3]);
void makeMap(char map[22][52], int snake[400][3], int food[]);
void move(int snake[400][3],int direct);
void makeFood(int food[]);
void showView(char map[22][52]);
int ifEat(int head, int food[2]);
int ifReprat(int snake[400][3], int x, int y);
int ifBump(int head);
void getKey();
