#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPalindrome(char *a) {
	int i = 0, n;
	n = strlen(a);
	int j = n-1;
	while (a[i] != '\0') {
		if (a[i] != a[j])
			return 0;
		i++;
		j--;
	}
	return 1;
}

long strCount(char *s, int n) {
	int i, j, k, l;
	long count = 0;
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			char a[n];
			l = 0;
			int flag = 0;
			for (k=i;k<=j;k++) {
				a[l] = s[k];
				l++;
			}
			a[l] = '\0';
			printf("%s\n",a);
			//flag = isPalindrome(a);
			//printf("%d\n",flag);
			//if (flag == 1)
			//	count++;
		}
		flag = isPalindrome(a);
		if (flag == 1)
			count++;
	}
	return count;
}

int main() {
	char s[] = "asasd";
	long count = strCount(s,strlen(s));
	printf("%ld\n",count);
	return 0;
}
