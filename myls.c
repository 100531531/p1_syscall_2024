//P1-SSOO-23/24

#include <stdio.h>		// Header file for system call printf
#include <unistd.h>		// Header file for system call gtcwd
#include <sys/types.h>	// Header file for system calls opendir, readdir y closedir
#include <dirent.h>     // Header file containing directory struct
#include <string.h>
#include <limits.h>     // Header file for defining constants for PATH_MAX

#define PATH_MAX 4096

// .. is representative of the parent directory
// . is representative of the current directory

int main(int argc, char *argv[])
{
    char dirPath[PATH_MAX]; 
    DIR *dirPtr; 
    struct dirent *dirEntry; 
    
    if (argc == 2)
	{
        strncpy(dirPath, argv[1], PATH_MAX);
    } 
	
	else if (argc == 1)
	{
        if (getcwd(dirPath, PATH_MAX) == NULL)
		{
            perror("Error getting current directory");
            return -1;
        }

    } 
	
	else 
	{
        fprintf(stderr, "Usage: %s [<directory name>]\n", argv[0]);
        return -1;
    }

    dirPtr = opendir(dirPath);

    if (dirPtr == NULL) 
	{
        perror("Error opening directory");
        return -1;
    }
    
    while ((dirEntry = readdir(dirPtr)) != NULL)
	{
        printf("%s\n", dirEntry->d_name);
    }
    
    closedir(dirPtr);
    
    return 0;
}

