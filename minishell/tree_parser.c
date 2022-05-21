/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:49:57 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/05/21 11:25:40 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmd	*cmd_parse(char *line)
{
	t_cmd	*c;
	c = malloc(sizeof(t_cmd));
	(void)line;
	return (c);
}

void	tree_parser(t_prior *script)
{
	int	i;
	int	j;

	if (script->numofchilds == 0)
	{
		script->cmd = cmd_parse(script->slices[0]);
		return ;
	}
	i = script->numofchilds;
	j = 0;
	while (j < i)
	{
		tree_parser(script->next[j]);
		j++;
	}
}
