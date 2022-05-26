/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:58:13 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/05/23 22:17:38 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*p;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	p = (char *)malloc((len + 1) * sizeof(const char));
	if (!p)
		return (0);
	while (i++ < len)
		p[i - 1] = s[i - 1];
	p[i - 1] = '\0';
	return (p);
}
