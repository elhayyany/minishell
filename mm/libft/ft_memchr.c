/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:03:26 by ael-hayy          #+#    #+#             */
/*   Updated: 2021/11/23 11:24:15 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int a, size_t b )
{
	unsigned char	*str;
	size_t			i;
	unsigned char	c;

	str = (unsigned char *)s;
	i = 0;
	c = (unsigned char)a;
	while (i < b)
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (0);
}
