#include<stdio.h>
#include<string.h>

int isPalindrome(char *s) {
    int l = strlen(s);
    int i,j;
    if (l == 1)
        return 1;
    else {
        j=l-1;
        for (i=0;i<l;i++) {
            if (j >= 0) {
                if (s[i] != s[j])
                    return 0;
            }
            j--;
        }
    }
    return 1;
}

char* longestPalindrome(char* s) {
    int len = strlen(s);
    int maxLen, longestLen = 0;
    int isValid;
    char str[len], resStr[len];
    int i,j,k;
    for (i=0;i<len;i++){
        for (j=0;j<=i;j++)
            str[j] = s[j];
        maxLen = strlen(str);
        isValid = isPalindrome(str);
        if (isValid == 1) {
            if (maxLen > longestLen)
                for (k=0;k<maxLen;k++)
                    resStr[k] = str[k];
        }
    } 
    return resStr;
}

int main() {
	char *ptr;
	ptr = longestPalindrome("babad");
	printf("%s", *ptr);
}
