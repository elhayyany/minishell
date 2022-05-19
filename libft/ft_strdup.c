/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:58:13 by ael-hayy          #+#    #+#             */
/*   Updated: 2021/11/23 11:39:35 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	p = (char *)malloc((len + 1) * sizeof(const char));
	if (!p)
		return (NULL);
	while (i++ < len)
		p[i - 1] = s[i - 1];
	p[i - 1] = '\0';
	return (p);
}
