/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:50:24 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/05/21 09:50:27 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parser.h"

void	free_tree(t_prior *script)
{
	int	i;
	int	j;

	i = script->numofchilds;
	j = 0;
	if (i == 0)
	{
		while (script->slices[j])
		{
			free(script->slices[j]);
			free(script->operator[j]);
			j++;
		}
		free(script->slices[j]);
		free(script->operator[j]);
		free(script->operator);
		free(script->slices);
		return ;
	}
	j = 0;
	while (script->operator[j])
	{
		free(script->operator[j]);
		j++;
	}
	j= 0;
	while (script->slices[j])
	{
		free(script->slices[j]);
		j++;
	}
	free(script->slices[j]);
	free(script->operator[j]);
	free(script->slices);
	free(script->operator);
	
	j = 0;
	while (j < i)
	{
		free_tree(script->next[j]);
		j++;
	}
	j = 0;
	while (j < i)
	{
		free(script->next[j]);
		j++;
	}
	free(script->next);
}