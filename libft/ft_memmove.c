/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 09:09:18 by ael-hayy          #+#    #+#             */
/*   Updated: 2021/11/22 14:30:24 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dest;
	char		*source;

	dest = (char *)dst;
	source = (char *)src;
	i = 0;
	if (!dest && !source)
		return (NULL);
	if (source < dest)
		while (++i <= len)
			dest[len - i] = source[len - i];
	else
		while (++i <= len)
			dest[i - 1] = source[i - 1];
	return ((void *)dest);
}
