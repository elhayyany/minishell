/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   being_ready.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:44:45 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/05/26 10:45:56 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_srtuct_bzero(t_cmd *pipe)
{
	pipe->line = 0;
	pipe->cmd = 0;
	pipe->args = 0;
	pipe->inputs_num = 0;
	pipe->outputs_num = 0;
	pipe->outputs = 0;
	pipe->inputs = 0;
	pipe->filesin = 0;
	pipe->filesout = 0;
	pipe->her_doc = 0;
	pipe->her_limit = 0;
	pipe->append_num = 0;
	pipe->appends = 0;
	pipe->files_appends = 0;
	pipe->env_valuue = 0;
	pipe->env_var = 0;
	pipe->lastout = 0;
}



t_cmd	*cmd_parse(char *line, char **env)
{
	t_cmd	*pipe;
	pipe = malloc(sizeof(t_cmd));
	ft_srtuct_bzero(pipe);
	pipe->line = line;
	set_env(pipe, env);
	pipe->inputs_num = malloc(sizeof(int));
	pipe->outputs_num = malloc(sizeof(int));
	pipe->append_num = malloc(sizeof(int));
	pipe->her_doc = malloc(sizeof(int));
	pipe->inputs_num[0] = 0;
	pipe->outputs_num[0] = 0;
	pipe->append_num[0] = 0;
	pipe->her_doc[0] = 0;
	redirections(pipe);
	return (pipe);
}

void	tree_parser(t_prior *script, char **env)
{
	int	i;
	int	j;

	if (script->numofchilds == 0)
	{
		script->cmd = cmd_parse(script->slices[0], env);
		return ;
	}
	i = script->numofchilds;
	j = 0;
	while (j < i)
	{
		tree_parser(script->next[j], env);
		j++;
	}
}