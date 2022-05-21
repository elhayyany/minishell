/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_line_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:50:03 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/05/21 15:34:08 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int next_qoute(char *line, char c)
{
	int i;

	i = 1;
	while (line[i])
	{
		if (line[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int check_parentheses(char *line)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
			i += next_qoute(&line[i], line[i]);
		else if (line[i] == '(')
		{
			if (i == 0)
				j++;
			else
			{
				k = i - 1;
				while (k >= 0)
				{
					if (line[k] == ' ')
					{
						k--;
						continue ;
					}
					if (line[k] != '|' && line[k] != '&' && line[k] != '(')
						return (1);
					else
						break ;
					k--;
				}
				j++;
			}
		}     
		else if (line[i] == ')')
			j--;
		if (j != 0 )
			return (1);
		i++;
	}
	return (0);
}
int	check_andor(char *line)
{
	int	i;
	int	k;
	int	l;

	i = 0;
	k = 0;
	l = 0;
	while (line[i])
	{
		if (line[i] == '|' || line[i] == '&')
		{
			if (l == 0)
				return (1);
			if (line[i] == '&' && line[i + 1] != '&')
				return (1);
			if (i == 0)
				return (1);
			else
			{
				k = i - 1;
				while (k >= 0)
				{
					if (line[k] == ' ')
					{
						k--;
						continue ;
					}
					if (line[k] == '|' || line[k] == '&' || line[i] == '(')
						return (1);
					else
						break ;
				}
				if (k == 0 && line[k] == ' ')
					return (1);
			}
			if (line[i + 1] == '|' || line[i + 1] == '&')
				i++;
			l = 0;
		}
		if (line[i] != ' ' && !(line[i] == '|' || line[i] == '&'))
			l = 1;
		i++;
	}
	if (l == 0)
		return (1);
	return(0);
}
int	revcheck(char *line)
{
	int	i;
	int	k;

	i = ft_strlen(line) - 1;
	while (i >= 0)
	{
		if (line[i] == '|' || line[i] == '&')
		{
			if (i == ft_strlen(line) - 1)
				return (1);
			else
			{
				k = i + 1;
				while (k < ft_strlen(line))
				{
					if (line[k] == ' ')
					{
						k++;
						continue ;
					}
					if (line[k] == '|' || line[k] == '&' || line[i] == ')')
						return (1);
					else
						break ;
				}
				if (k == ft_strlen(line) - 1 && line[k] == ' ')
					return (1);
			}
			if (line[i - 1] == '|' || line[i - 1] == '&')
				i--;
		}
		i--;
	}
	return (0);
}

int pre_check_line(char *line)
{
	if (check_parentheses(line) || check_andor(line)
			|| revcheck(line))
	{
		write(2, ">$ syntax error near unexpected token\n", 38);
		return (1);
	}
	return (0);
}