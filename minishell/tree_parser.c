/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:49:57 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/05/24 20:32:48 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"



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

int	len_without_quotes(char *str)
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
		if (ft_isalpha(str[i]))
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
	char	*new_str;
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

char	*get_valuue(char *var, t_cmd *pipe)
{
	int		i;
	char	*str;

	i = 0;
	printf("^%s^\n",var);
	if (isdigit(var[0]))
	{
		str = ft_strdup(&var[1]);
		free(var);
		return (str);
	}
	while (pipe->env_var[i])
	{
		if (!ft_strncmp(var, pipe->env_var[i], sizeof(var)))
		{
			free(var);
			return(ft_strdup(pipe->env_var[i]));
		}
		i++;
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
	printf("####%c\n", str[0]);
	if (str[i] == ' ')
		return (str);
	//return (rv_quote(str));
	while (str[i] && str[i] != ' ')
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
	printf("####_____~~~~: %s\n", tem);
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

char	*change_vall(char *str,char *var)
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
	char	*tem_tw;;

	i = 0;
	while (str[i])
	{
		printf("*%c\n", str[i]);
		if (str[i] == '\'')
			i += next_qoute(&str[i], '\'');
		if (str[i] == '$')
		{
			tem_tw = variable(&str[i + 1], pipe);
			str = change_vall(str, tem_tw);
			printf("~~%s\n", tem_tw);
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
		str1[*j] = str2[i];
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

	str = get_val(str, pipe);
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
			ft_concat(new_str, get_quotesd_word(&str[i]), &j);
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
	new_str = malloc(sizeof(char *) * (j + 1));
	while (i < j)
	{
		new_str[i] = remove_quotes_str(str[i], pipe);
		i++;
	}
	new_str[j] = 0;
	free_db_str(str);
	return (new_str);
}

void	process_quotes(t_cmd *pipe)
{
	pipe->cmd = remove_quotes_str(pipe->cmd, pipe);
	// printf("2\n");
	pipe->args = remove_quotes(pipe->args, pipe);
	// printf("3\n");
	pipe->filesin = remove_quotes(pipe->filesin, pipe);
	// printf("4\n");
	pipe->filesout = remove_quotes(pipe->filesout, pipe);
	// printf("5\n");
	pipe->her_limit = remove_quotes(pipe->her_limit, pipe);
	// printf("6\n");
	pipe->files_appends = remove_quotes(pipe->files_appends, pipe);
}

