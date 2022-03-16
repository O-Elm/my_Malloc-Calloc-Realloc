#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <stddef.h>

//test with make
//export LD_LIBRARY_PATH=.
// ./tester
int main()
{
	char *juju = malloc(1000);
	free(juju);
	malloc(1000000);
    puts("mama");
    DIR *d;
	struct dirent *dir;
	d = opendir(".");
	if (d) {
		while ((dir = readdir(d)) != NULL) {
			printf("%s\n", dir->d_name);
		}
		closedir(d);
	}

    return 0;
}