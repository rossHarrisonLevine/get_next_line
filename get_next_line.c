/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 19:38:24 by rlevine           #+#    #+#             */
/*   Updated: 2017/08/02 14:50:23 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
		char		*buf;
		static int	i;
		int			c;

		c = 0;
		buf = ft_strnew(BUFF_SIZE);
		while (read(fd, buf, 1) && !ft_strstr("\n", buf) && c < BUFF_SIZE)
			c++;
		ft_memmove(line[i], buf, BUFF_SIZE);
		free(buf);
		return(1);
}
