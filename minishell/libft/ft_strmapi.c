/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:43:19 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/05/25 10:27:25 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ptr;
	size_t	j;

	if (!s)
		return (NULL);
	j = 0;
	i = ft_strlen((char *)s);
	ptr = (char *) malloc((1 + i) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[j])
	{
		ptr[j] = (f)(j, s[j]);
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
