#ifndef CROSSREFERENCE_H
#define CROSSREFERENCE_H
#include <stdio.h>
#include <string.h>

void handle_line(char *line)
{
	printf("%s", line);
}

void removeChars(char *str, char *garbage)
{
	char *pr = str, *pw = str;

	while (*pr)
	{
		for (int i = 0; i < strlen(garbage); ++i)
		{

			if (*pw != garbage[i])
			{
				if ((i == strlen(garbage) - 1))
				{
					pw += (*pw != garbage[i]);
					break;
				}

				else
				{
					continue;
				}
			}

			else
			{
				break;
			}
			*pw = *pr++;
		}
	}
	*pw = '\0';
}

#endif