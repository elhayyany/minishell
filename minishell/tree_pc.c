/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:49:57 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/05/23 18:47:05 by ael-hayy         ###   ########.fr       */
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

int	its_int_and_char(char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;

	while (str[i])
	{
		if (ft_salpha(str[i])
			j = 1;
		else if (ft_isdigit(str[i]))
			k = 1;
		i++;
	}
	if (k && j)
		return (1);
	return (0);
}

char	*str_without_char(char *str)
{
	char	*enw_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ft_isdigit(str[i]))
		i++;
	new_str = malloc(sizeof(char) * ft_strlen(&str[i]) + 1);
	while (str[i])
	{
		new_str[j] = str[i];
		i++;
	}
	new_str[j] = '\0';
	free(str);
	return (new_str);
}



// char	*get_value(char *str, char **env)
// {
// 	char	*new_str;
// 	int		i;
// 	char	*tem;

// 	i = 1;
// 	tem = malloc(sizeof(char) * 2);
// 	tem[1] = '\0';
// 	new_str = 0;
// 	while (str[i] && str[i] != ' ')
// 	{
// 		tem[0] = str[i];
// 		new_str = ft_strjoin(new_str, tem);
// 		i++;
// 	}
// 	free(tem);
// 	if (its_int_and_char(new_str))
// 		new_str = ft_strjoin_pro(str_without_char(new_str)," ", &str[i];//if nos str then new_str no change
// 	else
// 		new_str = its_value(new_str, env); "*******************************************************"
// 	return (new_str);
// }

char	*get_valuue(char *var, t_cmd *pipe)
{
	int		i;
	char	*str;

	i = 0;
	while (pipe->env_var[i])
	{
		if (!ft_strncmp(var, pipe->env_var[i], sizeof(var)))
			return(pipe->env_var[i]);
		i++;
	}
	if (isdigit(var[0]))
	{
		str = ft_strdup(var[1]);
		free(var);
		return (str);
	}
	free(var);
	return (0);
}

char *variable(char *str, t_cmd *pipe)
{
	int		i;
	int		j;
	char	*tem;

	i = 0;
	while (str[i] || str[i] != ' ')
		i++;
	tem = malloc(sizeof(char) * i + 1);
	j = 0;
	while (j < i)
	{
		tem[j] = str[j];
		j++;
	}
	tem[j] = '\0';
	tem = get_valuue(tem, pipe);
	return (tem);
	
}

int	untill_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	after_var(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i])
		j++;
	return (j);
}

char	*change_vall(char *str, int i, char *var)
{
	int		j;
	char	*tem;
	char	*tem_tw;
	char	*tem_th;

	tem_th = str;
	j = untill_char(str, '$');
	tem = ft_substr(str, 0, j - 1);
	j = after_var(&str[j + 1]);
	tem_tw = ft_substr(str, j, ft_strlen(str));
	str = ft_strjoin(tem, var);
	str = ft_strjoin(str, tem_tw);
	if (var)
		free(var);
	if (tem_th)
		free(tem_th);
	return (str);
}

char	*get_val(char *str, t_cmd *pipe)
{
	int		i;
	int		j;
	char	*tem_tw;;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			i += next_qoute(&str[i], '\'');
		if (str[i] == '$')
		{
			tem_tw = variable(&str[i + 1], pipe);
			str = change_vall(str, i, tem_tw);
		}
		i++;
	}
	return (str);
}

char *get_quotesd_word(char *str)
{
	int 	i;
	int 	j;
	char	*tem;

	i = 1;
	j = 0;
	while (str[i] && str[i] != str[0])
		i++;
	tem = malloc(sizeof(char) * i + 1);
	while (j < i)
	{
		tem[j] = str[j + 1];
		j++;
	}
	tem[j] = '\0';
	return (tem);
}

void	ft_concat(char *str1, char *str2, int *j)
{
	int	i;

	i = 0;
	while (str2[i])
	{
		str1[*j] = str[2][i];
		(*j)++;
		i++;
	}
	free(str2);
}

char	*remove_quotes_str(char *str, t_cmd *pipe)
{
	int		len;
	int		i;
	int		j;
	char	*new_str;

	str = get_val(str, pipe);  "*******************************************************"
	if (no_quote_found(str))
		return (str);
	len = len_without_quotes(str);
	//j = ft_strlen(str);
	new_str = malloc(sizeof(char) * len + 1);
	i = 0;
	j = 0;
	ft_bzero(new_str, len + 1);
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			ft_concat(new_str, get_quotesd_word(&str[i]), &j); "*******************************************************"
			i += next_qoute(&str[i], str[i]);
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

char	**remove_quotes(char **str, t_cmd *pipe)
{
	int		i;
	int		j;
	char	**new_str;
	
	i = 0;
	j = strsnums(str);
	new_str = malloc(sizeof(char **) * j + 1);
	while (i < j)
	{
		new_str[i] = remove_quotes_str(str[i], pipe);
		i++;
	}
	new_str[j] = 0;
	free(str);
	return (new_str);
}

void	process_quotes(t_cmd *pipe)
{
	pipe->cmd = remove_quotes_str(pipe->cmd, pipe);
	pipe->args = remove_quotes(pipe->args, env, pipe);
	pipe->filesin = remove_quotes(pipe->filesin, pipe);
	pipe->filesout = remove_quotes(pipe->filesout, pipe);
	pipe->her_limit = remove_quotes(pipe->her_limit, pipe);
	pipe->files_appends = remove_quotes(pipe->files_appends, pipe);
}

void	redirections(t_cmd *pipe)
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
	process_quotes(pipe);
	//files_open(pipe);

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
	pipe->env_valuue = 0;
	pipe->env_var = 0;
}

void	set_env(t_cmd *pipe, char **env)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	k = 0;
	while (env[i])
		i++;
	if (pipe->env_valuue)
		free(pipe->env_valuue);
	if (pipe->env_var)
		free(pipe->env_var);
	pipe->env_var = malloc(sizeof(char *) * i + 1);
	pipe->env_valuue = malloc(sizeof(char *) * i + 1);
	while (env[i])
	{
		j = lenuntillequal(env[i]);
		pipe->env_var[i] = (malloc(sizeof(char *) * j + 1));
		k = 0;
		while (k < j)
		{
			pipe->var[i][k] = env[i][k];
			k++;
		}
		pipe->env_var[i][k] = '\0';
		j = lenafterequal(env[i]);
		pipe->env_valuue[i] = (malloc(sizeof(char *) * j + 1));
		l = 0;
		k++;
		while (l < j)
		{
			pipe->env_valuue[i][l] = env[i][k]
			l++;
			k++;
		}
		pipe->env_valuue[i][l] = '\0';
		i++;
	}
	pipe->env_var[i] = 0;
	pipe->env_valuue[i] = 0;
}

t_cmd	*cmd_parse(char *line, char **env)
{
	t_cmd	*pipe;
	pipe = malloc(sizeof(t_cmd));
	ft_srtuct_bzero(pipe);
	pipe->line = line;
	set_env(pipe, env);
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
