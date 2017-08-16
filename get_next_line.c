/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 19:38:24 by rlevine           #+#    #+#             */
/*   Updated: 2017/08/15 20:29:31 by rlevine          ###   ########.fr       */
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

int		snip(t_list *cur, char **buf)
{
	int		ret;
	char	*tmp;

	if(!(*buf))
		return (-1);
	while ((ft_strchr(*buf, '\n') == NULL && \
				(ret = read(cur->content_size, *buf, BUFF_SIZE)) > 0))
		{
			tmp = cur->content;
			cur->content = ft_strjoin(tmp, *buf);
			ft_strdel(&tmp);
		}
		ft_strdel(&(*buf));
		if (ret == -1)
			return (-1);
		return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*used;
	char			*buf;
	t_list			*cur;
	char			*tmp;

	if (!line || fd < 0 || !(buf = ft_strnew(BUFF_SIZE)) || BUFF_SIZE < 0)
		return (-1);
	cur = check_fd(&used, fd);
	if (snip(cur, &buf) == -1)
		return (-1);
	if (!cur->content)
		return (0);
	ft_strclr(buf);
	buf = ft_strnew(ft_strlen(cur->content));
	if ((buf = ft_strchr((char*)cur->content, '\n')) != NULL)
	{
		*line = ft_strsub(cur->content, 0, buf - (char*)cur->content);
		tmp = cur->content;
		cur->content = ft_strdup(buf + 1);
		ft_strdel(&tmp);
		return(1);
	}
	*line = ft_strdup(cur->content);
	cur->content = NULL;
	return (ft_strlen(*line) > 0 ? 1 : 0);
}
