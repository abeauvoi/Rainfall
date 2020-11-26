/* compiled with :
 * gcc -fno-stack-protector -Wno-format -o level7 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char 	c[69];

struct s {
	int 	i;
	char 	*buf;
}

void	m(void) {
	printf("%s - %d\n", c, time(NULL));
}

int 	main(int argc, char *argv[])
{
	struct s	*var1, var2;
	FILE		*fp;
	
	var1 = (struct s *)malloc(8);
	var1->i = 1;
	var1->buf = (char *)malloc(8);
	var2 = (struct s *)malloc(8);
	var2->i = 2;
	var2->buf = (char *)malloc(8);
	strcpy(var1->buf, argv[1]);
	strcpy(var2->buf, argv[2]);
	fp = fopen("/home/user/level8/.pass", "r");
	fgets(c, 0x44, fp);
	puts("~~");
	return 0;
}
