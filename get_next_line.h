/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 12:53:12 by rlevine           #+#    #+#             */
/*   Updated: 2017/08/15 16:59:37 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"
# define BUFF_SIZE 40

int get_next_line(const int fd, char **line);
#endif
