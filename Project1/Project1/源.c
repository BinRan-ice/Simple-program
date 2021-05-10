#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <Windows.h>

int main()
{
	int i, n;
	char *p;
	scanf("%d", &n);
	p = (char*)malloc(sizeof(char)*n);
	for ( i = 0; i < n; i++)
	{
		scanf("%c", (p + i));
	}
	for ( i = 0; i < n; i++)
	{
		if ((*(p + i) >= 'A') && (*(p + i) <= 'Z'))
			*(p + i) = *(p + i) + 4;
		printf("%5c", *(p + i));
	}
	system("pause");
	return EXIT_SUCCESS;
}