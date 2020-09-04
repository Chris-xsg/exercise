#include <stdio.h>
#include <stdlib.h>
#include "global.h"

int main( void ) {
	listen_init();
	epoll_init();
	epoll_process();
}

