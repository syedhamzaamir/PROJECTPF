#include<stdio.h>
#include<windows.h>

struct data
{
	char name[50];
	int score;			
}user[12], input,temp,disp;

void gotoxy(short x, short y)                                             
{
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int menu()
{
	int selection;
	box();
	gotoxy(59,14);	
	printf("1 - Play game");
	gotoxy(59,16);
	printf("2 - Quit");
	gotoxy(59,19);
	printf("Enter a selection: ");
	gotoxy(80,19);
	scanf("%d",&selection);
	return selection;
}
void line()
{
	int l1,l2;
	gotoxy(0,20);
	for(l1=1;l1<=70;l1++)
	printf("^");
	for(l2=0;l2<=19;l2++)
	{
	gotoxy(70,l2);
	printf("<");
	}	
}
void box()
{
	int i,j,k,l;
	gotoxy(43,5);
	for(i=43;i<=70;i++)
	{
		printf("* ");
	}
	for(j=6;j<=30;j++)
	{
		gotoxy(43,j);
		printf("*");
	}
	gotoxy(43,j);
	for(k=43;k<=70;k++)
	{
		printf("* ");
	}
	for(l=6;l<=30;l++)
	{
		gotoxy(97,l);
		printf("*");
	}

}
void letterpress1(int *score)
{
//	system("COLOR F9");
	int c=0;
	int row,life,sflag,lflag,sp,rr2,rr3,rl1,rl2,rl3,sp1,sp2,sp3,ch1,ch2,ch3,r2,r3;
	//srand(time(NULL));
	life=5;
	sflag=0;
	lflag=0;
	sp1=rand()%70;
	sp2=rand()%70;
	sp3=rand()%70;
	ch1='A'+ (rand()%26);
	ch2='A'+ (rand()%26);
	ch3='A'+ (rand()%26);
	r2=rand()%20;
	r3=rand()%20;
	for(rr2=1,rr3=1,rl1=1,rl2=1,rl3=1;;rl1++,rr2++,rr3++)
	{	
		if(kbhit())//to check key is pressed
	    c=getch();
	//	hidecursor();				
		for(row=1;row<rl1;row++)
		{	
			printf("\n");
		}
		for(sp=1;sp<sp1;sp++)
	    printf(" ");
		printf("%c",ch1);
		gotoxy(0,0);
		if(rr2>=r2)
		{
			for(row=1;row<rl2;row++)
			printf("\n");
			for(sp=1;sp<sp2;sp++)
	    	printf(" ");
	    	printf("%c",ch2);
			if(rl2==20)
			{
				rr2=1;
				ch2='A'+ (rand()%26);
				sp2=rand()%70;
				rl2=1;
				lflag=1;
			}
			else if(c==ch2 || c==ch2+32) //+32 to ignore capslock issue
			{
				rr2=1;
				ch2='A'+ (rand()%26);
				sp2=rand()%70;
				rl2=1;
				sflag=1;
			}
			rl2++;
			gotoxy(0,0);	
		}
		if(rr3>=r3)
		{
			
			for(row=1;row<rl3;row++)
			printf("\n");
			for(sp=1;sp<sp3;sp++)
	    	printf(" ");
	    	printf("%c",ch3);
			if(rl3==20)
			{
				rr3=1;
				ch3='A'+ (rand()%26);
				sp3=rand()%70;
				rl3=1;
				lflag=1;
			}
			else if(c==ch3 || c==ch3+32)
			{
				rr3=1;
				ch3='A'+ (rand()%26);
				sp3=rand()%70;
				rl3=1;
				sflag=1;
			}
			rl3++;
			gotoxy(0,0);	
		}
		if(rl1==20)
		{
			ch1='A'+ (rand()%26);	
			sp1=rand()%70;
			rl1=1;
			lflag=1;
		}
		else if(c==ch1 || c==ch1+32)
		{
			ch1='A'+ (rand()%26);	
			sp1=rand()%70;
			rl1=1;
			sflag=1;	
		}
		line();
		if(sflag==1)
		*score=*score+1;
		if(lflag==1)
		life=life-1;
		if(life<=0)
		{
			system("cls");
			box();
			gotoxy(59,13);
			printf("GAME OVER !");
			input.score=*score;
			gotoxy(59,16);
			printf("SCORE : %d",input.score);
			gotoxy(59,19);
			printf("Press any key to exit...");
			getch();
			system("cls");
			return;
		}
		gotoxy(72,5);
		printf("score %d",*score);
		gotoxy(72,8);
		printf("life %d",life);
		float milli_seconds = 1000 * 0.2; 
		system("cls");
		c=0;
		sflag=0;
		lflag=0;
	}
}

int main()
{
	system("cls");
	int choice,lvl,score=0;
	int A;
	A:
	choice=menu();
	system("cls");
	if(choice==1)
	{
	    box();
		gotoxy(59,15);	
		printf("ENTER NAME : ");
		scanf("%s",input.name);
		system("cls");	
		letterpress1(&score);
		score=0;
		goto A;
	}
	else if(choice==2)
	{
		return 0;
	}
	else
	{
		gotoxy(59,15);	
		printf("WRONG SELECTION");
		float milli_seconds = 1000000 * 4;
		system("cls");
		goto A; 
	}
}
