#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int decimal(char *a)
{
	int i, sum=0,temp;
	for(i=(strlen(a)-1);i>=0;i--)
	{
		temp=a[i]-'0';
		printf("\n%d",temp);
		sum=sum+(temp*pow(2,i));
		printf("\n%d",sum);
	}
	return sum;
}
char* binary(int num)
{
	printf("\nIn Binary Function");
	char str[10],s[10],ch;
	char *ptr;
	ptr=s;
	int remainder,i=0,j=0,temp;
	while(num!=0)
	{	
		remainder=num%2;
		num=num/2;
		temp=remainder;
		ch=remainder+'0';
		str[i]=ch;
		i++;
	}
	for(i=(strlen(str))-1;i>=0;i--)
	{
		s[j]=str[i];
		j++;
	}
	printf("\nString: %s",s);
	printf("\n");
	return ptr;
}

int main()
{
	char s1[10],s2[10],sum[10];
	printf("\nEnter first Binary string: ");
	scanf("%s",&s1);
	int decimala=decimal(s1);
	printf("\nDecimal value of Binary string %s is %d\n",s1, decimala);
	printf("\nEnter second Binary string: ");
        scanf("%s",&s2);
        int decimalb=decimal(s2);
        printf("\nDecimal value of Binary string %s is %d\n",s2, decimala);
	int binarySum=decimala+decimalb;
	char *ptr;
	ptr=sum;
	ptr=binary(binarySum);
	printf("\nSum of %s and %s is: %s",s1,s2,*ptr);
}
