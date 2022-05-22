/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:49:57 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/05/22 17:08:16 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	word_length(t_cmd *pipe, int i)
{
	int	j;

	j = 0;
	while (pipe->line[i])
	{
		if (pipe->line[i] == '\'' || pipe->line[i] == '\"')
		{
			j += next_qoute(&pipe->line[i], pipe->line[i]);
			i += next_qoute(&pipe->line[i], pipe->line[i]);
		}
		if (pipe->line[i] == ' ' || pipe->line[i] == '|' || pipe->line[i] == '&' || pipe->line[i] == '<' || pipe->line[i] == '>')
			return (j);
		i++;
		j++;
	}
	return (j);
}

int	get_file_name(t_cmd *pipe, int i, char **word)
{
	int	j;
	int	;

	k = 0;
	j = word_length(pipe, i);
	(*word) = malloc(sizeof(char) * j + 1);
	while (k < j)
	{
		(*word)[k] = pipe->line[i];
		i++;
		k++;
	}
	(*word)[k] = '\0';
	i--;
	return (i);
}

int	her_doc(t_cmd *pipe, int i)
{
	char	*limiter;

	i += 2;
	i += get_file_name(pipe, i, &limiter);
	(pipe->her_doc)++;
	push_back(&(pipe->her_limite), limiter);
	return (i);
}

int	redirectinp(t_cmd *pipe, int i)
{
	char	*file_name;

	i++;
	i += get_file_name(pipe, i, &file_name);
	(pipe->inputs_num)++;
	push_back(&(pipe->filesin), file_name);
	return (i);
}

int	redirectappend(t_cmd *pipe, int i)
{
	char	*file_name;

	i += 2;
	i += get_file_name(pipe, i, &file_name);
	(pipe->append_num)++;
	push_back(&(pipe->files_appends), file_name);
	return (i);
}

int redirectout(t_cmd *pipe, int i)
{
	char	*file_name;

	i++;
	i += get_file_name(pipe, i, &file_name);
	(pipe->outputs_num)++;
	push_back(&(pipe->filesout), file_name);
	return (i);
}

int	cmd_and_args(t_cmd *pipe, int i)
{
	char	*word;
	i += get_file_name(pipe, i, &word);
	if (!pipe->cmd)
		pipe->cmd = word;
	else
		push_back(&(pipe->args), word);
	return (i);
}

void	redirectio(t_cmd *pipe)
{
	int	i;

	i = 0;
	while (pipe->line[i])
	{
		// if (pipe->line[i] == '\''|| pipe->line[i] == '\"')
		// 	i += next_qoute(pipe->line[i]);
		else if (pipe->line[i] == '<' && pipe->line[i + 1] == '<')
			i += her_doc(pipe, i);
		else if (pipe->line[i] == '<')
			i += redirectinp(pipe, i);
		else if (pipe->line[i] == '>' && pipe->line[i + 1] == '>')
			i += redirectappend(pipe, i);
		else if (pipe->line[i] == '>')
			i += redirectout(pipe, i);
		else if (pipe->line[i] != ' ')
			i += cmd_and_args(pipe, i);
		i++;
	}
}

// void	quote_removal(t_cmd *pipe)
// {
	
// }


void	ft_srtuct_bzero(t_cmd *pipe)
{
	pipe->s_there_herd = 0;
	pipe->where_herc = 0;
	pipe->line = 0;
	pipe->cmd = 0;
	pipe->args = 0;
	pipe->inputs_num = 0;
	pipe->outputs_num = 0;
	pipe->outputs = 0;
	pipe->inputs = 0;
	pipe->filesin = 0;
	pipe->filesout = 0;
	pipe->here_doc = 0;
	pipe->her_limit = 0;
	pipe->cmd_and_args = 0;
	pipe->append_num = 0;
	pipe->appends = 0;
	pipe->files_appends = 0;
}

t_cmd	*cmd_parse(char *line)
{
	t_cmd	*pipe;
	pipe = malloc(sizeof(t_cmd));
	ft_srtuct_bzero(pipe);
	pipe->line = line;
	return (c);
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
