#include <string.h>
#include <stdlib.h>

int language;

void	greetuser(char *buf)
{
	char 	out[72];

	if (language == 1)
	{
		strpcy(out, "Hyvää päivää ");
	}
	else if (language == 2)
	{
		strcpy(out, "Goedemiddag! ");
	}
	else
		strpcy(out, "Hello ");
	strcat(out, buf);
	puts(out);
}

int 	main(int ac, char *argv[])
{
	char 	buf[];
	char 	*lang;
	char 	buf2[];

	if (argc != 3)
		return (1);
	memset(buf, '\0', 19);
	strncpy(buf, argv[1], 40);
	strncpy(buf + 40, argv[2], 32);
	lang = getenv("LANG");
	if (lang != (char*)0) {
		if (memcmp(lang, "fi", 2) == 0)
		{
			language = 1;
		}
		else if (memcmp(lang, "nl", 2) == 0)
		{
			language = 2;
		}
	}
	memcpy(buf2, buf, 19);
	greetuser(buf);
	return (0);
}
