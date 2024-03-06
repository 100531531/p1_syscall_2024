//P1-SSOO-23/24

#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

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


		if ((character == ' ' || character == '\t'))
		{
			wordCount++;
		}
	}

    fseek(filePtr, 0, SEEK_SET);

	char buffer[1024];
	int isEmpty = 0;
	bool hasCharacters = false;
	
    while (fgets(buffer, sizeof(buffer), filePtr) != NULL)
	{
        hasCharacters = false; 
        for (int i = 0; buffer[i] != '\0'; i++)
		{
            if (buffer[i] != ' ' && buffer[i] != '\t' && buffer[i] != '\n' && buffer[i] != '\r')
			{
                hasCharacters = true;
                break;
            }
        }

        if (!hasCharacters)
        {
            isEmpty++;
        }
    }

	fseek(filePtr, 0, SEEK_SET);

	char line[MAX_LINE_LENGTH];
	int hasSpace = 0;
	bool endsWithSpace = false;

	while (fgets(line, sizeof(line), filePtr) != NULL)
	{
        line[strcspn(line, "\n")] = '\0';

        size_t length = strlen(line);

        if (length > 0 && line[length - 1] == ' ')
		{
            endsWithSpace = true;
            hasSpace++;
            break; 
        }
    }

	fseek(filePtr, -1, SEEK_END);

	int prevChar;
	int savedChar;
    
    prevChar = fgetc(filePtr);

    if (prevChar != EOF)
	{
        savedChar = prevChar;
    }

	printf("%d ", lineCount);

	if (savedChar == 10)
	{
		printf("%d ", wordCount + lineCount - isEmpty);
	}

	else if (isEmpty != 0)
	{
		printf("%d ", wordCount + lineCount + 1 - isEmpty);
	}
	
	else
	{
		printf("%d ", wordCount + lineCount + 1 - hasSpace);
	}

	printf("%d\n", byteCount);

	// Close file to prevent consuming system resources or leakage

	fclose(filePtr);

	return 0;
}

