#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

long getFileSize(FILE* first)
{
	long size = 0;
	fpos_t pos;
	fseek(first, 0, SEEK_END);
	fseek(first, 0, SEEK_SET);
	size = ftell(first);
	return size;
}

int main(int argc, char** argv)

{
		int reading_fd;
		reading_fd = open ("first.txt", O_RDONLY);
		if (reading_fd == -1)
			printf("This file doesnt exit. Creat and try again");
		int writing_fd;
		writing_fd = open ("second.txt", O_WRONLY || O_CREAT);
		printf("%d", reading_fd);
		printf("\n%d", writing_fd);
		if (argc < 1){
		
			char* reading_fdf = argv[1];
			char* writing_fdf = argv[2];
			FILE* first = fopen(reading_fdf, "r");
			FILE* second = fopen(writing_fdf, "w");
			
			if(first != NULL){
				long fileSize;
				char* fileContents;
				ssize_t nr;
				fileSize = getFileSize(first);
				fileContents = malloc(fileSize + 1);
				fread(fileContents, 1, fileSize, first);
				fileContents[fileSize] = '\0';
				printf("\n%s ", fileContents);
				printf("\n%ld", fileSize);
				
				nr = fprintf(second, fileContents, 0);
			}
			else printf("file is empty");
		}
}
