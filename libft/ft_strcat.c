/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 17:14:40 by rlevine           #+#    #+#             */
/*   Updated: 2016/12/27 14:56:58 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (s1[a])
		a++;
	while (s2[b])
		s1[a++] = s2[b++];
	s1[a] = '\0';
	return (s1);
}
