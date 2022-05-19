/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:24:36 by ael-hayy          #+#    #+#             */
/*   Updated: 2021/11/23 11:57:20 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*allocate(char const *s, char c)
{
	int		j;
	char	*p;

	j = 0;
	while (s[j] != '\0' && s[j] != c)
		j++;
	p = (char *)malloc((j + 1) * sizeof(char));
	if (!p)
		return (NULL);
	p[j] = '\0';
	while (j > 0)
	{
		p[j - 1] = s[j - 1];
		j--;
	}
	return (p);
}

static int	hmw(char const *s, char c)
{
	int	j;
	int	i;
	int	k;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		k = 0;
		while (s[j] != '\0' && s[j] == c)
			j++;
		while (s[j] != '\0' && s[j] != c)
		{
			j++;
			k = 1;
		}
		if (k == 1)
			i++;
	}
	return (i);
}

char	**free_array(char **res, int len)
{
	while (len)
	{
		free(res[len--]);
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**splt;
	int		n;
	int		j;

	n = 0;
	j = 0;
	if (!s)
		return (NULL);
	splt = (char **)malloc ((hmw(s, c) + 1) * sizeof(char *));
	if (!splt)
		return (0);
	while (s[j] != '\0' )
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		if (s[j])
			splt[n++] = allocate(s + j, c);
		if (splt[(n - 1)] == NULL)
			return (free_array(splt, n));
		while (s[j] != '\0' && s[j] != c)
			j++;
	}
	splt[n] = NULL;
	return (splt);
}
