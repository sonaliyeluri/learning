#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int cash = 100;
void play(int bet)
{
	char c[3]={'J','Q','K'};
	printf("Shuffling.....");
	srand(time(NULL));
	int i;
	for(i=0;i<5;i++)
	{
		int x=rand()%3;
		int y=rand()%3;
		int temp=c[x];
		c[x]=c[y];
		c[y]=temp;		
	}
	int playerGuess;
	printf("What is the position of Queen - 1, 2 or 3? ");
	scanf("%d",&playerGuess);
	if(c[playerGuess - 1]=='Q')
	{
		cash+= 3*bet;
		printf("You Win! Result = %c%c%c Total cash = %d\n",c[0],c[1],c[2],cash);
	}
	else
	{
		cash-=bet;
		printf("You Loose! Result = %c%c%c Total cash = %d\n",c[0],c[1],c[2],cash);
	}
}

int main()
{
	int bet;
	while (cash>0)
	{
		printf("What is your bet? $");
		scanf("%d",&bet);
		if ((bet==0)||(bet>cash))
			break;
		play(bet);
	}
}

