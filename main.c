#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	int fd;
	char *line;

	fd = open(argv[1],O_RDONLY);
	while (get_next_line(fd,&line))
	{
		printf("%s$\n",line);
	}
	return (0);
}