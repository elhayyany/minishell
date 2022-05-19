/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:37:23 by ael-hayy          #+#    #+#             */
/*   Updated: 2021/11/21 14:41:27 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*br;

	if (lst != NULL || !del)
	{
		while ((*lst) != NULL)
		{
			br = (*lst)->next;
			del((*lst)->content);
			free((*lst));
			(*lst) = br;
		}
	}
}
