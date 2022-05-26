/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:26:15 by ael-hayy          #+#    #+#             */
/*   Updated: 2021/11/24 09:34:37 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hmd(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i++;
		n /= 10;
	}
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	strng(int m, int i, int n, char *s)
{
	int	k;

	while (m <= i)
	{
		k = n % 10;
		s[i--] = k + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		m;

	m = 0;
	i = hmd(n);
	if (i == 0)
		i = 1;
	s = (char *) malloc((i + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[i--] = '\0';
	if (n == -2147483648)
	{
		n /= 10;
		s[i--] = 8 + '0';
	}
	if (n < 0)
	{
		n *= -1;
		s[m++] = '-';
	}
	strng(m, i, n, s);
	return (s);
}
