/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 19:38:24 by rlevine           #+#    #+#             */
/*   Updated: 2017/08/14 19:36:30 by rlevine          ###   ########.fr       */
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

int		snip(char *line, t_list *cur, char *buf)
{
	int		ret;
	int		i;
	char	*tmp;

	i = 0;
	if (ft_strlen((char*)cur->content) && (tmp = (char*)cur->content) != NULL)
	{
		i = ft_strchr(tmp, '\n') - tmp;
		ft_strncpy(line, (char*)cur->content, i);
		ft_strclr(&((char*)cur->content)[i + 1]);
	}
	while ((ret = read(cur->content_size, buf, BUFF_SIZE)) > 0 && \
			ft_strchr(buf, '\n') == NULL)
		ft_strcat(line, buf);
	if (ret > 0 && (i = ft_strchr(buf, '\n') - buf) > 0)
	{
		ft_strncat(line, buf, i);
		ft_strcpy((char*)cur->content, &buf[i + 1]);
	}
	ft_strdel(&buf);
	return (ret);
}
int			get_next_line(const int fd, char **line)
{
	static t_list	*used;
	char			*buf;
	t_list			*cur;
	int				ret;

	if (!line || fd < 0 || !(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	cur = check_fd(&used, fd);
	ret = snip(*line, cur, buf);
	if (ret > 0)
		return (1);
	return (ret);
}
