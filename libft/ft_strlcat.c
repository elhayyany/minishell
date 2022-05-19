/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:51:30 by ael-hayy          #+#    #+#             */
/*   Updated: 2021/11/22 14:54:45 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	y;
	size_t	z;

	x = 0;
	y = 0;
	z = ft_strlen(src);
	if (dstsize == 0)
		return (z);
	while (dst[x] && x < dstsize)
		x++;
	while (src[y] && (x + y) < (dstsize - 1))
	{
		dst[x + y] = src[y];
		y++;
	}
	if (x < dstsize)
		dst[x + y] = '\0';
	return (x + z);
}
