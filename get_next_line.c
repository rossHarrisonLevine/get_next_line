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
	int		ret;
	char	*tmp;

	while (ft_strchr(buf, '\n') == NULL && \
	(ret = read(cur->content_size, buf, BUFF_SIZE)) > 0)
	{

	}
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
	snip(*line, cur, buf);
	//while (!ft_strchr(buf, '\n') && read(curr->content_size, buf,  BUFF_SIZE);
	//	ft_strcat(*line, buf);
	
	return (1);
}
