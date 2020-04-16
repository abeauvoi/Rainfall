/* compiled with :
 * gcc -fno-stack-protector -o level8 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s {
	char 	buf[0x20];
	int 	i;
};

struct s	*auth;
char 		*service;

int		main(void) {
	char 	buf[0x80];

	while (1) {

		printf("%p, %p\n", auth, service);

		if (fgets(buf, sizeof(buf), stdin) != NULL)
			break ;

		if (strncmp("auth ", buf, 5) == 0) {
			auth = malloc(4);
			memset(auth, 0, 4);
			if (strlen(buf + 5) < 31)
				strcpy(auth->buf, buf + 5);
		}

		if (strncmp("reset", buf, 5) == 0)
			free(auth);

		if (strncmp("service", buf, 7) == 0)
			service = strdup(buf + 7);

		if (strncmp("login", buf, 5) == 0) {
			if (auth->i != 0)
				system("/bin/sh");
			else
				fwrite("Password:\n", sizeof(char), 10, stdout);
		}

	}
	return 0;
}
