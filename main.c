#include "get_next_line.h"

int main(int ac, char **av)
{
	int fd;
	char **line;
	
	ac = 2;
	line = (char**)malloc(sizeof(char*)*sizeof(char*));
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, line);
	ft_putstr(line[0]);
}
