/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:51:15 by ael-hayy          #+#    #+#             */
/*   Updated: 2021/11/24 20:36:02 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		a;
	t_list	*curr;

	if (!lst)
		return (0);
	a = 1;
	curr = lst;
	while (curr->next)
	{
		a++;
		curr = curr->next;
	}
	return (a);
}
