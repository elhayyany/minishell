/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 10:46:15 by ael-hayy          #+#    #+#             */
/*   Updated: 2021/11/24 09:35:03 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ar;

	ar = *lst;
	if (*lst != NULL)
	{
		while (ar->next != NULL)
			ar = ar->next;
		ar->next = new;
	}
	else
		*lst = new;
}
