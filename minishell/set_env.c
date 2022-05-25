/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:41:29 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/05/24 12:06:27 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	lenuntillequal(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

int	lenafterequal(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] == '=')
		i++;
	while (str[i++])
		j++;
	return (j);
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
	pipe->env_var = malloc(sizeof(char *) * (i + 1));
	pipe->env_valuue = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		j = lenuntillequal(env[i]);
		pipe->env_var[i] = (malloc(sizeof(char *) * (j + 1)));
		k = 0;
		while (k < j)
		{
			pipe->env_var[i][k] = env[i][k];
			k++;
		}
		pipe->env_var[i][k] = '\0';
		j = lenafterequal(env[i]);
		pipe->env_valuue[i] = (malloc(sizeof(char *) * (j + 1)));
		l = 0;
		k++;
		while (l < j)
		{
			pipe->env_valuue[i][l] = env[i][k];
			l++;
			k++;
		}
		pipe->env_valuue[i][l] = '\0';
		i++;
	}
	pipe->env_var[i] = 0;
	pipe->env_valuue[i] = 0;
}