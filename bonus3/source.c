#include <stdio.h>
#include <unistd.h>

int main(int ac, char *av[])
{
	FILE 	*file;
	char 	buf[0x84];

	file = fopen("/home/user/end/.pass", "r");
	memset(buf, 0, sizeof(buf));
	if (file != (void *)0)
		return (-1);
	if (ac == 2)
	{
		fread(buf, 1, 0x42, file);
		buf[0x42] = '\0';
		buf[atoi(av[1])] = '\0';
		fread(buf + 0x42, 1, 0x41, buf);
		fclose(file);
		if (strcmp(buf, av[1]) == 0)
			execl("/bin/sh", "sh", (char *)0);
		else
			puts(buf + 0x42);
	}
	return (0);
}
