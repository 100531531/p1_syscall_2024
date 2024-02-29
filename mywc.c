//P1-SSOO-23/24

#include <stdio.h>

// For mywc you must use the calls related to file manipulation (open, read, write, and close).

int main(int argc, char *argv[])
{
	/*If less than two arguments (argv[0] -> program, argv[1] -> file to process) print an error y return -1*/
	if(argc < 2)
	{
		printf("Too few arguments\n");
		return -1;
	}

	FILE *fptr;
	fptr = fopen(argv[1], "r");

	// If the file does not exist, print an error and return -1
	if (fptr == NULL)
	{
		printf("Error opening file\n");
		return -1;
	}

	int byteCount = 0;
	int lineCount = 0;
	int wordCount = 0;
	int character;

	// Read the file byte by byte and count the number of bytes
	while ((character = fgetc(fptr)) != EOF)
	{
		byteCount++;

		if (character == '\n') {
			lineCount++;
		}

		if (character == ' ' || character == '\t')
		{
			wordCount++;
		}

	}

	printf("Number of bytes: %d\n", byteCount);
	printf("Number of lines: %d\n", lineCount);
	printf("Number of words: %d\n", wordCount + lineCount + 1);

	fclose(fptr);

	return 0;
}

