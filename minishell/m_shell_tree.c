/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_shell_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:33:33 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/05/22 10:34:33 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parser.h"
 
 void	check_malloc(void *p, void **ptr, int i)
 {
	 if (i)
	 {
		if (!p)
		{
			printf("can't allocate more space\n");
			exit(1);
		}
		return ;
	 }
	if (!ptr)
	{
			printf("can't allocate more space\n");
			exit(1);
	}
 }

int strsnums(char  **slices)
{
	int i;
 
	if (!slices)
		return (0);
	i = 0;
	while (slices[i])
		i++;
	return (i);
}
 
int closed_parentheses(char *line)
{
	int i;
	int j;
 
	i = 1;
	j = 1;
	while (line[i])
	{
		if (line[i] == '(')
			j++;
		if (line[i] == ')')
			j--;
		if (j == 0)
			return (i);
		i++;
	}
	return (i);
}
 
int calulate_cmds(char *line)
{
	int i;
	int j;
 
	i = 0;
	j = 0;;
	while (line[i])
	{
		if (line[i] == '|' || line[i] == '&')
		{
			if (line[i + 1] == '|' || line [i + 1] == '&')
				i++;
			j++;
		}
		if (line[i] == '(')
			i += closed_parentheses(&line[i]);
		if (line[i] == '\'' || line[i] == '\"')
			i += next_qoute(&line[i], line[i]);
		i++;
	}
	j++;
	return (j);
}
 
void    calulate_cmds_lens(char *line, int *arr)
{
	int i;
	int j;
	int l;
	int k;
 
	i = 0;
	j = 0;
	l = 0;
	k = 0;
	while (line[i])
	{
		if (line[i] == '(')
		{
			k += closed_parentheses(&line[i]);
			i += closed_parentheses(&line[i]);
			k++;
			i++;
			continue ;
		}
		if (line[i] == '\'' || line[i] == '\"')
		{
			printf("%d **\n",i);
			k += next_qoute(&line[i], line[i]);
			i += next_qoute(&line[i], line[i]);
			printf("%d **\n", i);
			i++;
			k++;
			continue ;
		}
		if (line[i] == '|' || line[i] == '&')
		{
			arr[l++] = k - j;
			j = k;
			i++;
			if (line[i + 1] == '|' || line [i + 1] == '&')
				i++;
		}
		i++;
		k++;
	}
	arr[l] = k - j;
}

char    **allocate(int *lens, int i)
{
	char    **slices;
 
	slices = malloc(sizeof(char *) * i + 1);
	check_malloc(0, (void **)slices, 0);
	(void)lens;
	slices[i] = NULL;
	// slices[i] = NULL;
	// while (i-- > 0)
	// {
	//  slices[i] = malloc(sizeof(char) * lens[i]);
	//  check_malloc(slices[i], 0, 1);
	// }
	return (slices);
}
 
int lenplusstar(int *len, int start)
{
	int i;
	int j;
 
	i = 0;
	j = 0;
	while (i < start)
	{
		j += len[i];
		j++;
		i++;
	}
	return (j);
}

char	*clean_slice(char *slice)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = ft_strlen(slice) - 1;
	while (slice[i] && (slice[i] == ' ' || slice[i] == '|' || slice[i] == '&'))
		i++;
	while (j >= 0 && (slice[j] == ' ' || slice[j] == '|' || slice[j] == '&'))
		j--;
	line = malloc(sizeof(char) * (j - i + 1));
	while (i < j)
	{
		line[i] = slice[i];
		i++;
	}
	line[i] = '\0';
	free(slice);
	return (line);
}

char    *get_substr(char *line, int *len, int start, char **operator)
{
	char    *slice;
	int     i;
	int     j;
	int     k;
 
	i = 0;
	j = 0;
	k = 0;
	slice = malloc(sizeof(char) * len[start] + 1);
	operator[start] = malloc(sizeof(char) * 3);
	check_malloc(slice, 0, 1);
 
	if (start == 0)
	{
		while (i < len[start])
		{
			slice[i] = line[i];
			i++;
		}
		while (line[i] == ' ')
			i++;
		while (line[i] == '|' || line[i] == '&')
			operator[start][j++] = line[i++];
		operator[start][j++] = '\0';
		slice[i] = '\0';
		return (slice);
	}
	i = lenplusstar(len, start);
	
	while (line[i] == ' ' || line[i] == '|' || line[i] == '&')
	{
		k++;
		i++;
	}

	j = 0;
	while (j < len[start] - k)
	{
		slice[j] = line[i];
		i++;
		j++;
	}
	slice[j] = '\0';
	while (line[i] == ' ')
		i++;
	while (line[i] == ')')
		i++;
	j =0;
	while (line[i] == '|' || line[i] == '&')
	{
		operator[start][j] = line[i];
		j++;
		i++;
	}
	operator[start][j] = '\0';
	return (slice);
}
 
char    **ft_split_pro(char *line, char ***operators)
{
	char    **slices;
	int     num_of_cmds;
	int     *lens;
	int     i;
 
	num_of_cmds = calulate_cmds(line);
	lens = malloc(sizeof(int) * (num_of_cmds));
	calulate_cmds_lens(line, lens);
	slices = allocate(lens, num_of_cmds);
	*operators = allocate(0, num_of_cmds);
	i = 0;
	while (i < num_of_cmds)
	{
		slices[i] = get_substr(line, lens, i, *operators);
		i++;
	}
	slices[i] = NULL;
	free(lens);
	return (slices);
}

char	*new_slice(char *slice, int i, int j)
{
	int		k;
	char	*line;

	k = 0;
	line = malloc(sizeof(char *) * (j - i + 1));
	while (i <= j)
	{
		line[k] = slice[i];
		k++;
		i++;
	}
	line[k] = '\0';
	return (line);
}

char *clear_it(char *slice)
{
	char	*line;
	int		i;
	int		k;

	i = 0;
	k = ft_strlen(slice) - 1;
	line = slice;
	while (slice[i] && slice[i] == ' ')
		i++;
	if (slice[i] == '(')
		i++;
	while (slice[i] && slice[i] == ' ')
		i++;
	while (k >= 0 && slice[k] == ' ')
		k--;
	if (slice[k] == ')')
		k--;
	while (line[k] == ' ')
		k--;
	line = new_slice(slice, i, k);
	free (slice);
	return (line);
}
t_prior*    m_shell_parser(char *line, char *** operators)
{
	char    **slices;
	t_prior *script;
	int     i;

	slices = ft_split_pro(line, operators);
	script = malloc(sizeof(t_prior));
	check_malloc(script, 0, 1);
	script->operator = *operators;
	script->numofchilds = strsnums(slices);
	script->line = line;
	script->slices = slices;
	if (strsnums(slices) == 1)
	{
		printf("%s\n", slices[0]);
		i = 0;
		script->numofchilds = 0;
		return (script);
	}
	script->next = malloc(sizeof(t_prior *) * strsnums(slices));
	i = 0;
	while (slices[i])
	{
		slices[i] = clear_it(slices[i]);
		i++;
	}
	i = 0;
	while (slices[i])
	{
	
		script->next[i] = m_shell_parser(slices[i], operators);
		//printf("{%d}\t + %s + \t%s\n",i, script->slices[i], script->operator[i]);
		i++;
	}
	return (script);
}