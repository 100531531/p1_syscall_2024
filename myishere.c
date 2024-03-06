//P1-SSOO-23/24

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[])
{
	/* If less than three arguments (argv[0] -> program, argv[1] -> directory to search, argv[2] -> file to find) print an error y return -1 */
	if(argc < 3)
	{
		printf("Too few arguments\n");
		return -1;
	}

	DIR *direc = opendir(argv[1]);

	if (direc == NULL) {
        printf("failed to open");
		return -1;
    }

	// struct to represent an entry in a directory
	struct dirent *entry;

	char *fileName = argv[2];

	while ((entry = readdir(direc)) != NULL) {

		if (strcmp(entry->d_name, fileName) == 0) {
			printf("File %s is in directory %s\n", fileName, argv[1]);
            closedir(direc);
			return 0;  // Exit the function once the file is found
		} 

	}

	printf("File %s is not in directory %s\n", fileName, argv[1]);
	closedir(direc);
	return 0;
}


