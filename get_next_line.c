/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 19:38:24 by rlevine           #+#    #+#             */
/*   Updated: 2017/08/12 18:28:09 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list		*check_fd(t_list **used, int fd)
{
	t_list *tmp;

	tmp = *used;
	while (tmp)
	{
		if (fd == (int)tmp->content_size)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(used, tmp);
	tmp = *used;
	return(tmp);
}

void		snip(char *line, t_list *cur, char *buf)
{
	int i;
	int j;

	j = 0;
	i = -1;
	ft_strcpy(line, cur->content);
	while (buf[++i] != '\n')
		line[i + ft_strlen((char*)cur->content)] = buf[i];
	ft_bzero(cur->content, ft_strlen(cur->content));
	i++;
	while (buf[i])
		((char*)cur->content)[j++] = buf[i++];
}
int			get_next_line(const int fd, char **line)
{
	static t_list	*used;
	char			*buf;
	t_list			*cur;
//	int				ret;
	if (!line || fd < 0 || !(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	cur = check_fd(&used, fd);
	if (!read(cur->content_size, buf, BUFF_SIZE))
		return (0);
	snip(*line, cur, buf);
	//while (!ft_strchr(buf, '\n') && read(curr->content_size, buf,  BUFF_SIZE);
	//	ft_strcat(*line, buf);
	
	return (1);
}
