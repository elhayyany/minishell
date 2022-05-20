/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:15:28 by ael-hayy          #+#    #+#             */
/*   Updated: 2021/11/23 11:37:09 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp( const void *str1, const void *str2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			c;

	c = 0;
	a = (unsigned char *) str1;
	b = (unsigned char *) str2;
	while ((*a == *b) && c < n - 1)
	{
		c++;
		a++;
		b++;
	}
	if (c == n)
		return (0);
	return (*a - *b);
}
