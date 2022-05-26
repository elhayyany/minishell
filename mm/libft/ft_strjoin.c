/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:32:13 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/05/23 22:08:53 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	a;
	size_t	b;
	size_t	c;

	if (!(s1) || !(s2))
		return (NULL);
	c = 0;
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	p = (char *)malloc(a + b + 1);
	if (!p)
		return (NULL);
	while (c++ < a)
		p[c - 1] = s1[c - 1];
	c = 0;
	while (c < b)
	{
		p[a] = s2[c];
		a++;
		c++;
	}
	p[a] = '\0';
	if (s1)
		free(s1);
	return (p);
}
