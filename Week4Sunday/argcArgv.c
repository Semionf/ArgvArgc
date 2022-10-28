#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

void testCopy(char* []);

int main(int argc, char* argv[])
{
	
	testCopy(argv);
}

void testCopy(char* argv[])
{
	FILE* f = fopen(argv[1], "r");
	FILE* f2 = fopen(argv[2], "w");
	int count = 0;
	char temp;
	char* number;
	if (!f)
	{
		printf("File error");
		exit(1);
	}
	if(!f2)
	{
		printf("File error");
		exit(1);
	}
	while (fread(&temp, sizeof(char), 1, f))
	{
		count++;
	}
	number = (char*)malloc(count);
	fclose(f);
	f = fopen(argv[1], "r");
	printf("%s", argv[1]);
	printf("%s", argv[2]);
	fread(number, sizeof(char), count, f);
	fwrite(number, sizeof(char), count, f2);
	fclose(f);
	fclose(f2);
	free(number);
}