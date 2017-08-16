#include "get_next_line.h"

int main(int ac, char **av)
{
	int fd;
	char *line;
	int d;

	ac = 2;
	line = ft_strnew(500);
	fd = open(av[1], O_RDONLY);
	
	d = get_next_line(fd, &line);

	printf("line:%s \n ret:%d \n", line, d);
ft_strclr(line);
		d = get_next_line(fd, &line);

	printf("line:%s \n ret:%d \n", line, d);
	ft_strclr(line);
	d = get_next_line(fd, &line);

	printf("line:%s \n ret:%d\n", line, d);
ft_strclr(line);
	d = get_next_line(fd, &line);

printf("line:%s \n ret:%d \n", line, d);
ft_strclr(line);
	d = get_next_line(fd, &line);

printf("line:%s \n ret:%d\n", line, d);
ft_strclr(line);
	d = get_next_line(fd, &line);

printf("line:%s \n ret:%d\n", line, d);
ft_strclr(line);
}
