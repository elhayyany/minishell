/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:06:28 by ael-hayy          #+#    #+#             */
/*   Updated: 2021/11/12 16:18:54 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		a;
	char		*p;
	size_t		n;

	a = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
		return (((char *)ft_calloc(1, 1)));
	n = ft_strlen(s + start);
	if (n > len)
		n = len;
	p = (char *)malloc(n + 1);
	if (!p)
		return (NULL);
	while (a++ < n)
		p[a - 1] = s[start + a - 1];
	p[a - 1] = '\0';
	return (p);
}
