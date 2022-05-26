/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:12:33 by ael-hayy          #+#    #+#             */
/*   Updated: 2021/11/22 14:29:00 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*destt;
	unsigned char	*srcc;
	size_t			c;

	destt = (unsigned char *)dest;
	srcc = (unsigned char *)src;
	if (!srcc && !destt)
		return (NULL);
	c = 0;
	while (c++ < n)
		destt[c - 1] = srcc[c - 1];
	return (destt);
}
