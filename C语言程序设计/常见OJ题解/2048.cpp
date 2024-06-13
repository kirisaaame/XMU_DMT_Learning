#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void initBoard();
void drawBoard();
char getInput();
void addRandom();
int GameEnded();
void showResult();
void moveByDirect(char);


int main()
{
	char start;
	printf("Welcome to game 2048!\n");
	printf("Try to get a 2048 and win the game!\n");
	printf("press 'y' to start the game and 'q' to quit:");
	start=getchar();
	while(start=='y')
		{
		printf("Good luck!\n");
		while(getchar()!='\n')
			continue;
		_sleep(500);
		system("cls");
		game_start()
		printf("Do you want to try")
		start=getchar();
		}
	
		printf("Bye!\n");

	//游戏开头问候语
	
	
	
	return 0;
}

void game_start()//游戏主控制函数
{
	char ch;
	int sign;
	initBoard();
	drawBoard();
	while(1)
	{
		ch=getInput();
		moveByDirect(c);
		addRandom();
		drawBoard();
		if (gameEnded())
		{
			showResult();
			break;
		}
	}
}

void initBoard()
{
	
}