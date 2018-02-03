#define _CRT_SECURE_NO_WARNINGS 1


#include "LinkedList.h"
#include "CrossReference.h"

int main(int argc, char *argv[])
{
	FILE *f; 
	int size = 1024, pos; 
	int c;
	const char *file;
	char *garbage = "\\#\t\"\'\\%*&><";
	file = "LinkedList.c";
	char *buffer = (char *)malloc(size);

	f = fopen(file, "r");
	if (f)
	{
		do
		{ // Read all lines in file
			pos = 0;
			do
			{ // read one line
				c = fgetc(f);
				if (c != EOF) buffer[pos++] = (char)c;
				if (pos >= size - 1) { // increase buffer length - leave room for 0
					size *= 2;
					buffer = (char*)realloc(buffer, size);
				}
			} while (c != EOF && c != '\n');
			buffer[pos] = 0;
			// line is now in buffer
			handle_line(buffer);
			removeChars(buffer, garbage);
			handle_line(buffer);
		} while (c != EOF);
		fclose(f);
	}

	else if (f == NULL)
	{
		printf("File cannot be found");
	}

	free(buffer);
	
	getchar();
	
	return 0;
}