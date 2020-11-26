/* compiled with:
 * gcc -fno-stack-protector -o level6 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void 	n(void) {
	system("/bin/cat /home/user/level7/.pass");
}

void 	m(void) {
	puts("Nope");
}

void	main(int argc, char *argv[]) {
	char *p1 = malloc(0x40);
	void (**p2)(void) = malloc(0x4);

	*p2 = &m;
	strcpy(p1, argv[1]);
	(*p2)();
}
