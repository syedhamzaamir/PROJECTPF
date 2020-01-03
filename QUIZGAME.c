#include<stdio.h>
#include<windows.h>
void gotoxy(short x, short y)                                             
{
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int menu()
{
	int select;
	gotoxy(59,16);	
	printf("1 - Play game");
	gotoxy(59,18);
	printf("2 - Quit");
	gotoxy(59,20);
	printf("Enter selection: ");
	gotoxy(59,22);
	scanf("%d",&select);
	return select;
}

int intro()
{
	gotoxy(59,7);
	printf("QUIZ GAME");
	gotoxy(59,8);
	printf("__________");
	gotoxy(59,10);
	printf("WELCOME");
	gotoxy(59,11);
	printf("  TO   ");
	gotoxy(56,12);
	printf("THE QUIZ GAME");
	gotoxy(59,13);
	printf("__________");
}
void boxx()
{
	int i,j,k,l;
	gotoxy(35,5);
	for(i=43;i<=75;i++)
	{
		printf("* ");
	}
	for(j=6;j<=20;j++)
	{
		gotoxy(35,j);
		printf("*");
	}
	gotoxy(35,j);
	for(k=43;k<=75;k++)
	{
		printf("* ");
	}
	for(l=6;l<=20;l++)
	{
		gotoxy(99,l);
		printf("*");
	}

}

void quiz()
{
	char choice;
	int score=0;
	int life = 3;
	while(1){
	
	gotoxy(37,7);
	printf("QUESTION 1");
	gotoxy(37,9);
	printf("Who won the Player of The Year in the 2019 ESPN Esports Awards.");
	gotoxy(37,11);
	printf("A. Bugha/t/t B. Arsalan Ash");
	gotoxy(37,12);
	printf("C. Lioon/t/t D. sinatraa");
	gotoxy(40,15);
	printf("Select The correct answer: ");
	scanf("%c",&choice);
	if (choice=='B' || choice=='b')
	{
		score++;
	}
	else
	{
		life--;
	}
	if(life==0)
	{
		system("cls");
		boxx();
		gotoxy(59,8);
		printf("GAME OVER !");
		gotoxy(59,10);
		printf("SCORE : %d",score);
		gotoxy(59,12);
		printf("Press any key to exit...");
		getch();
		system("cls");
		return;
	}
}
}

int main()
{
	int choice;
	intro();
	choice = menu();
	if(choice==1)
	{
		system("cls");
		boxx();
		quiz();
	}
}

