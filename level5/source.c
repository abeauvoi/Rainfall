/* compiled with:
 * gcc -Wno-format-security -fno-stack-protector -o level5 */
#include <stdio.h>
#include <stdlib.h>

void	o(void) {
	system("/bin/sh");
	exit(1);
}

void 	n(void) {
	char 	buf[512];

	fgets(buf, sizeof(buf), stdin);
	printf(buf);
	exit(1);
}

void 	main(void) {
	n();
}
