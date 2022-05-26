/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:02:03 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/05/26 11:28:00 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor/minishell.h"

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
		{
		return (j);
		}	
		i++;
		j++;
	}
	return (j);
}

int	get_file_name(t_cmd *pipe, int i, char **word)
{
	int	j;
	int	k;

	k = 0;
	j = word_length(pipe, i);
	(*word) = malloc(sizeof(char) * j);
	while (k < j)
	{
		(*word)[k] = pipe->line[i];
		i++;
		k++;
	}
	(*word)[k] = '\0';
	return (i);
}

void	free_db_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	push_back(char	***stack, char *word)
{
	int		i;
	char	**newstack;

	if (!(*stack))
	{
		*stack = malloc(sizeof(char *) * 2);
		(*stack)[0] = word;
		(*stack)[1] = 0;
	}
	else
	{
		i = strsnums(*stack);
		newstack = malloc(sizeof(char *) * (i + 2));
		i = 0;
		while ((*stack)[i])
		{
			newstack[i] = ft_strdup((*stack)[i]);
			i++;
		}
		newstack[i] = word;
		i++;
		newstack[i] = NULL;
		free_db_str(*stack);
		(*stack) = newstack;
	}
}

int	her_doc(t_cmd *pipe, int i)
{
	char	*limiter;

	i += 2;
	while (pipe->line[i] && pipe->line[i] == ' ')
		i++;
	i = get_file_name(pipe, i, &limiter);
	pipe->her_doc[0] += 1;
	push_back(&(pipe->her_limit), limiter);
	return (i);
}

int	redirectinp(t_cmd *pipe, int i)
{
	char	*file_name;

	i++;
	while (pipe->line[i] && pipe->line[i] == ' ')
		i++;
	i = get_file_name(pipe, i, &file_name);
	pipe->inputs_num[0] += 1;
	push_back(&(pipe->filesin), file_name);
	return (i);
}

int	redirectappend(t_cmd *pipe, int i)
{
	char	*file_name;

	i += 2;
	while (pipe->line[i] && pipe->line[i] == ' ')
		i++;
	i = get_file_name(pipe, i, &file_name);
	pipe->append_num[0] += 1;
	push_back(&(pipe->files_appends), file_name);
	return (i);
}

int redirectout(t_cmd *pipe, int i)
{
	char	*file_name;

	i++;
	while (pipe->line[i] && pipe->line[i] == ' ')
		i++;
	i = get_file_name(pipe, i, &file_name);
	pipe->outputs_num[0] += 1;
	push_back(&(pipe->filesout), file_name);
	return (i);
}

int	cmd_and_args(t_cmd *pipe, int i)
{
	char	*word;

	while (pipe->line[i] && pipe->line[i] == ' ')
		i++;
	i = get_file_name(pipe, i, &word);
	if (!pipe->cmd)
		pipe->cmd = word;
	else
		push_back(&(pipe->args), word);
	return (i);
}

void	redirections(t_cmd *pipe)
{
	int	i;

	i = 0;
	pipe->lastout = malloc(sizeof(int));
	pipe->lastin = malloc(sizeof(int));
	pipe->lastout[0] = 0;
	pipe->lastin[0] = 0;
	while (pipe->line[i])
	{
		if (pipe->line[i] == '<' && pipe->line[i + 1] == '<')
		{
			pipe->lastout[0] = 1;
			i = her_doc(pipe, i);
		}
		else if (pipe->line[i] == '<'  && pipe->line[i + 1] != '<')
		{
			pipe->lastout[0] = 2;
			i = redirectinp(pipe, i);
		}
		else if (pipe->line[i] == '>' && pipe->line[i + 1] == '>')
		{
			pipe->lastin[0] = 1;
			i = redirectappend(pipe, i);
		}
		else if (pipe->line[i] == '>' && pipe->line[i + 1] != '>')
		{
			pipe->lastin[0] = 2;
			i = redirectout(pipe, i);
		}
		else if (pipe->line[i] != ' ')
			i = cmd_and_args(pipe, i);
		else if (pipe->line[i] == ' ')
			i++;
	}
	process_quotes(pipe);
	files_open(pipe);
}