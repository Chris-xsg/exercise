#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int set_daemon() {
	switch ( fork() ) {
		case 0:
			break;
		default:
			exit(0);
	}

	if ( setsid() == -1 ) 
		perror("setsid"),exit(1);

	umask(0);
	chdir("/");

	int fd = open("/dev/null", O_RDWR);
	dup2(fd, STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	
	return 0;
}
