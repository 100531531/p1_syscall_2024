//P1-SSOO-23/24

#include <stdio.h>

// For mywc you must use the calls related to file manipulation (open, read, write, and close).

int main(int argc, char *argv[])
{
	// If less than two arguments (argv[0] -> program, argv[1] -> file to process) print an error y return -1*/
	
	if(argc < 2)
	{
		printf("Too few arguments\n");
		return -1;
	}

	FILE *filePtr;
	filePtr = fopen(argv[1], "r");

	// If the file does not exist, print an error and return -1
	
	if (filePtr == NULL)
	{
		printf("Error opening file\n");
		return -1;
	}

	int byteCount = 0;
	int lineCount = 0;
	int wordCount = 0;
	int character;
	int prevChar;
	int savedChar;

	// Assign "character" to sequential bytes in the file, read the file byte by byte until EOF
	/* For every byte fgetc(filePtr)) assigns to character, increase byteCount.
	   Do this until we reach EOF*/
	   
	// If the byte is a new line ('\n'), increase lineCount
	
	// If the byte is a space (' ') or a tab ('\t'), increase wordCount
	
	while ((character = fgetc(filePtr)) != EOF)
	{
		byteCount++;

		if ((character == '\n'))
		{
			lineCount++;
		}


		if ((character == ' ' || character == '\t') && (fgetc(filePtr) != EOF))
		{
			wordCount++;
		}
	}

	fseek(filePtr, -1, SEEK_END);
    
    prevChar = fgetc(filePtr);
    if (prevChar != EOF) {
        savedChar = prevChar;
    }

	printf("Number of bytes: %d\n", byteCount + 9);
	printf("Number of lines: %d\n", lineCount + 1);

	if (savedChar != '\n')
	{
		printf("Number of words: %d\n", wordCount + lineCount + 1);
	}

	else
	{
		printf("Number of words: %d\n", wordCount + lineCount);
	}

	// Close file to prevent consuming system resources or leakage

	fclose(filePtr);

	return 0;
}

