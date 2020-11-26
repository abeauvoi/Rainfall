/* compiled with :
 * gcc -Wno-format-security -fno-stack-protector -o level4
 * */
#include <stdio.h>
#include <stdlib.h>

int	m;

void 	p(char *buf) {
	printf(buf);
}

void	n(void) {
	char	buf[512];

	fgets(buf, sizeof(buf), stdin);
	p(buf);
	if (m == 0x1025544)
		system("/bin/cat /home/user/level5/.pass");
}

void 	main(void) {
	n();
}
