#include <stdio.h>

int 	m;

void 	v() {
	char 	buf[512];

	fgets(buf, sizeof(buf), stdin); 
	printf(buf);
	if (m == 0x40)
	{
		fwrite("Wait what?!\n", sizeof(char), 12, stdout);
		system("/bin/sh");
	}
}

void	main() {
	v();
}
