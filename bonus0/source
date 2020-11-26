#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	p(char *s1, char *s2) {
	char 	buf[4096];

	puts(s2);
	read(0, buf, sizeof(buf));
	*(strchr(buf, '\n')) = '\0';
	strncpy(s1, buf, 0x14);
}

void 	pp(char *buf0) {
	char 	buf1[0x14];
	char 	buf2[0x14];

	p(buf1, " - ");
	p(buf2, " - ");
	strcpy(buf0, buf1);
	strcat(buf0 + strlen(buf0), buf2);
}

int		main(int ac, char *av[]) {
	char 	buf[0x32];

	pp(buf);
	puts(buf);
	return 0;
}
