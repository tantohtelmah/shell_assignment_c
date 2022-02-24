#include <stdio.h>
#include <stdlib.h>

long getFileSize(FILE* fp)
{
	long size = 0;
	fpos_t pos;
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	return size;
}

int main(int argc, char** argv)
{
	long fileSize;
	char* fileContents;
	ssize_t nr;
	char** buf[fileSize];
	
	if (argc > 1)
	{
		char* file = argv[1];
		char* file2 = argv[2];
		char* flie3 = argv[3];
		FILE* fp = fopen(file, "r");
		FILE* fp2 = fopen(file2, "w");
		//FILE* fp3 = fopen(file3, "w");
		if (fp != NULL)
		{
			fileSize = getFileSize(fp);
			fileContents = malloc(fileSize + 1);
			fread(fileContents, 1, fileSize, fp);
			fileContents[fileSize] = '\0';
			printf("\n%s", fileContents);
			
			long fs = fileSize/2;
			fileContents[fs] = '\0';
			printf("\n%ld", fs);
			printf("\n%s", fileContents);
			nr = fprintf(fp2, fileContents, 0);
			
			for(int i=0; i>(fileSize); i++){
				printf("\n%d", fileContents[i]);
				printf("working");
		        }
			fclose(fp);
		}
		
	}

}
	
	
	//nr = write (fd, buf, strlen (buf));
	
