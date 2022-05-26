/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:07:51 by ael-hayy          #+#    #+#             */
/*   Updated: 2021/11/23 14:04:57 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*test;

	test = (t_list *)malloc(sizeof(t_list));
	if (test == NULL)
		return (NULL);
	test->content = content;
	test->next = NULL;
	return (test);
}
