#include<stdio.h>
#include<stdlib.h>

char convert(int x)
{
    char ch;
    switch(x)
    {
        case '1': ch='A';
            break;
        case '2': ch='B';
            break;
        case '3': ch='C';
            break;
        case '4': ch='D';
            break;
        case '5': ch='E';
            break;
        case '6': ch='F';
            break;
        case '7': ch='G';
            break;
        case '8': ch='H';
            break;
        case '9': ch='I';
            break;
        case '10': ch='J';
            break;
        case '11': ch='K';
            break;
        case '12': ch='L';
            break;
        case '13': ch='M';
            break;
        case '14': ch='N';
            break;
        case '15': ch='O';
            break;
        case '16': ch='P';
            break;
        case '17': ch='Q';
            break;
        case '18': ch='R';
            break;
        case '19': ch='S';
            break;
        case '20': ch='T';
            break;
        case '21': ch='U';
            break;
        case '22': ch='V';
            break;
        case '23': ch='W';
            break;
        case '24': ch='X';
            break;
        case '25': ch='Y';
            break;
        case '26': ch='Z';
            break;
    }
    return ch;
}

int main()
{
	int n, remainder;
	char ch;
	printf("\nEnter a number: ");
	scanf("%d",&n);
	ch=convert(n);
	/*if (n > 0)
	{
		if (n > 26)
		{
			remainder=n%26;
			ch = convert(remainder);
			n=n/26;
		}
		else
		{
			ch= convert(n);
		}
	}*/
	printf("\n%c\n",ch);
}
