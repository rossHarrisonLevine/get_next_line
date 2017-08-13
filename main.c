#include "get_next_line.h"

int main(int ac, char **av)
{
	int fd;
	char *line;

	ac = 2;
	line = (char*)malloc(sizeof(char)*500);
	fd = open(av[1], O_RDONLY);
	
	get_next_line(fd, &line);

	printf("%s\n", line);
	get_next_line(fd, &line);

	printf("%s\n", line);

			get_next_line(fd, &line);

	printf("%s\n", line);
	
	get_next_line(fd, &line);

	printf("%s\n", line);

}
