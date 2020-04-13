#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int	main(int argc, char *argv[])
{
	char	*str;
	gid_t	gid;
	uid_t	uid;

	if (atoi(argv[1]) == 423) {
		str = strdup("/bin/sh");
		gid = getegid();
		uid = geteuid();
		setresgid(gid, gid, gid);
		setresuid(uid, uid, uid);
		execve(str, NULL, NULL);
	}
	else
		fwrite("No !\n", sizeof(char), 5, stderr);
	return 0;
}
