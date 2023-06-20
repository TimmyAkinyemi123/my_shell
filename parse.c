/*nclude "shell.h"

int parse_input(char *line)
{
	size_t position = _strcspn(line, "\n");
	line[position] = '\0';

	if (_strcmp(line, "exit") == 0)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == '\0')
	{
		if (s1[i] == s2[i])
			return (0);
		i++;
	}
	return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
}

size_t _strcspn(char *str, char *charset)
{
	char *ptr = str, *ch = charset;

	while (*ptr)
	{
		while (*ch)
		{
			if (*ptr == *ch)
				return (ptr - str);
			ch++;
		}
		ptr++;
	}
	return (ptr - str);
}*/
