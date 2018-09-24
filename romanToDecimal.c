#include<stdio.h>
#include<stdlib.h>

int convert(char ch)
{
    int value=0;
    switch(ch)
    {
        case 'I': value=1;
            break;
        case 'V': value=5;
            break;
        case 'X':value=10;
            break;
        case 'L': value=50;
            break;
        case 'C': value=100;
            break;
        case 'D': value=500;
            break;
        case 'M': value=1000;
            break;
        case '\0': value=0;
            break;
        default: value=-1;
    }
    return value;
}

int romanToInt(char* s) {
    int i=0;
    int num=0;
    while(s[i]!='\0')
    {
        if(convert(s[i])<0)
        {
            printf("\nInvalid Roman Letter\n");
            return 0;
        }
        else
        {
            if(convert(s[i])>=convert(s[i+1]))
            {
                num=num+convert(s[i]);
            }
            else if(convert(s[i])<convert(s[i+1]))
            {
                num=num+(convert(s[i+1])-convert(s[i]));
                i++;
            }
            i++;
        }
    }
    return num;
}

int main()
{
	char str[10];
	int decimal;
	printf("Enter a Roman Number: ");
	scanf("%s",&str);
	decimal=romanToInt(str);
	printf("\nDecimal value for %s is: %d\n",str,decimal);
}
