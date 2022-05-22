/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:49:57 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/05/22 19:04:23 by ael-hayy         ###   ########.fr       */
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
		*stack = malloc(sizeof(char **) * 2);
		(*stack)[0] = word;
		(*stack)[1] = 0;
	}
	else
	{
		i = strsnums(*stack);
		newstack = malloc(sizeof(char *) * i + 2)
		i = 0;
		while ((*stack)[i])
		{
			newstack[i] = (*stack)[i];
			i++;
		}
		newstack[i] = word;
		newstack[i] = 0;
		free_db_str(*stack);
		(*stack) = newstack;
	}
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

int	no_quote_found(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (0);
		i++;
	}
	return (1);
}

int	*len_without_quotes(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			c = str[i++];
			while (str[i] != c)
			{
				i++;
				j++;
			}
		}
		else
			j++;
		i++;
	}
	return (j);
}

char	*get_value(char *str, char **env)
{
	char	*new_str;
	int		i;
	int		len;

	i = 1;
	if (!ft_isalpha(str[i])
	{
		
	}
	str = get_var(str[i]);
	len = ft_strlen(str);

}

char	*get_val(char *str, char **env)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			str = get_value(&str[i], env); "*******************************************************"
		i++;
	}
	return (str);
}

char	*remove_quotes_str(char *str, char **env)
{
	int		len;
	int		i;
	int		j;
	char	*new_str;

	str = get_val(str, env);  "*******************************************************"
	if (no_quote_found(str))
		return (str);
	len = len_without_quotes(str);
	//j = ft_strlen(str);
	new_str = malloc(sizeof(char) * len + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			i += ft_concat(new_str, get_quotesd_word(&str[i], i, &j)); "*******************************************************"
		}
		else
			new_str[j] = str[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

void	process_quotes(t_cmd *pipe, che **env)
{
	pipe->cmd = remove_quotes_str(pipe->cmd, env);
	pipe->args = remove_quotes(pipe->args, env);		"*******************************************************"
	pipe->filesin = remove_quotes(pipe->filesin, env);		"*******************************************************"
	pipe->filesout = remove_quotes(pipe->filesout, env);		"*******************************************************"
	pipe->her_limit = remove_quotes(pipe->her_limit, env);		"*******************************************************"
	pipe->files_appends = remove_quotes(pipe->files_appends, env);		"*******************************************************"
}

void	redirections(t_cmd *pipe, char **env)
{
	int	i;

	i = 0;
	while (pipe->line[i])
	{
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
	process_quotes(pipe, env);
	files_open(pipe);

}



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

t_cmd	*cmd_parse(char *line, char **env)
{
	t_cmd	*pipe;
	pipe = malloc(sizeof(t_cmd));
	ft_srtuct_bzero(pipe);
	pipe->line = line;
	redirections(pipe);
	return (c);
}
void	tree_parser(t_prior *script, char **env)
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
