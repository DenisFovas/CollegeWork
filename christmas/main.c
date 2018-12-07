// Fiecare colinda - fisier diferit. Extrage un fisier random.
// User will get insert the tree size.
// Will display the tree based on the colinde.
// Step 4: Aranjeaza codul sub forma de brad.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CAROLS 7
#define GREEN "\x1B[32m"

char *content;

void get_file_content(const char *fileName)
{
	char c;
	int size = 0;
	FILE *fp = fopen(fileName, "r");

	if (fp == NULL)
	{
		perror("Invalid brad content.. Merry Christmas anyway!\n");
		exit(EXIT_FAILURE);
	}

	while ((c = fgetc(fp)) != EOF)
		size++;
	size = 0;

	fclose(fp);
	content = malloc(sizeof(char) * size + 2);
	fp = fopen(fileName, "r");
	while ((c = fgetc(fp)) != EOF)
		content[size++] = c;

	content[++size] = '\0';
	fclose(fp);
}

char define_random_char()
{
	char rand_char = 32 + rand() % 221;
	if (rand_char == ' ' || rand_char == '\t' || rand_char == '\n')
		return define_random_char();
	if (rand_char < 0)
		return define_random_char();
	return rand_char;
}

void rand_leaf()
{
	int color = rand() % 18 - 10;
	char rand_char = define_random_char();
	/* if (color < 0) */
	printf(GREEN "%c", rand_char);
	/* else */
	/* 		printf("\x1B[%im" "%c", 32+color, rand_char); */
}

const char *define_file_name()
{
	char *dest = strdup("./res/a.txt");
	dest[6] = ('0' + rand() % MAX_CAROLS);

	return dest;
}

int main(int argc, char **argv)
{
	int i, j, w;
	char t, l;
	srand(time(NULL));

	const char *fileName = define_file_name();

	get_file_content(fileName);

	// fprintf(stdout, "%s", content);

	// w = 20;
	// t = 'a';
	// for (i = 0; i < (w - 1); i++)
	// {
	// 	printf("%*s", (w + 1) - i, "");
	// 	for (j = 0; j < 1 + i * 2; j++)
	// 		rand_leaf();
	// 	printf("\n");
	// }
	// printf("%*s"
	// 	   "%c%c%c\n",
	// 	   w, " ", t, t, t);

	return 0;
}
