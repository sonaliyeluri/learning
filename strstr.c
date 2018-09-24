#include <stdio.h>
#include <string.h>

int main(void) 
{
	/* Define a pointer of type char, a string and the substring to be found*/
	char *cptr;
	char str[] = "Wikipedia, be bold";
	char substr[] = "edia, b";

	/* Find memory address where substr "edia, b" is found in str */
	cptr = strstr(str, substr);

	/* Print out the character at this memory address, i.e. 'e' */
	printf("%c\n", *cptr);

	/* Print out "edia, be bold" */
	printf("%s\n", cptr);
	
	return 0;
}
