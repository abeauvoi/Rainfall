#include <stdlib.h>
#include <string.h>

int 	main(int ac, char *argv[])
{
	int 	count;
	char 	buf[40];

	count = atoi(argv[1]);
	if (count > 9)
		return (1);
	memcpy(buf, argv[2], count * sizeof(int));
	if (count == 0x574f4c46)
		execl("/bin/sh", "sh", (char*)0);
	return (0);
}
