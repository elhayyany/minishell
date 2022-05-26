/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:09:49 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/05/26 11:36:49 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor/minishell.h"


void	get_herdoc(t_cmd *pipe, int j, char *limit)
{
	char	*line;

	
	while (1)
	{
		line = readline("> ");
		if (!line)
			continue ;
		if (!ft_strncmp(line, limit, ft_strlen(line)))
		{
			free(line);
			return ;
		}
		if (j == 1)
			line = get_val(line, pipe, 0);
		if (pipe->lastout[0] == 1)
		{
			write(pipe->fd[1], line, ft_strlen(line));
			write(pipe->fd[1], "\n", 1);
		}
		free(line);		
	}
	
}

void	open_her_doc(t_cmd *pip)
{
	int	i;

	if (!pip->her_limit)
		return ;
	i = 0;
	if (pip->lastout[0] == 1)
		pip->fd = malloc(sizeof(int) * 2);
	while (pip->her_limit[i])
	{
		if (pip->lastout[0] == 1)
		{
			if (pip->fd[0])
			{
				close(pip->fd[0]);
				close(pip->fd[1]);
			}
			pipe(pip->fd);
		}
		if (no_quote_found(pip->her_limit[i]))
		{
			get_herdoc(pip, 1, pip->her_limit[i]);
		}
		else
		{
			pip->her_limit[i] = remove_quotes_str(pip->her_limit[i], pip);
			get_herdoc(pip, 2, pip->her_limit[i]);
		}
		i++;
	}
}


void	open_output(t_cmd *pipe)
{
	int	i;

	i = 0;
	if (!pipe->filesout)
		return ;
	pipe->A = malloc(sizeof(int));
	pipe->outputs = malloc(strsnums(pipe->filesout) * sizeof(int));
	while (pipe->filesout[i])
	{
		pipe->outputs[i] = open(pipe->filesout[i], O_RDWR | O_CREAT ,0642);
		if (pipe->outputs[i] == -1)
		{
			pipe->A[0] = -1;
			printf("monosholo: %s:permission denied\n", pipe->filesout[i]);
			while (i++ > 0)
				close (pipe->outputs[i]);
			break ;
		}
		i++;
	}
	pipe->A[0] = 1;
}

void	open_input(t_cmd *pipe)
{
	int	i;

	i = 0;
	if (!pipe->filesin)
		return ;
	pipe->outputs = malloc(strsnums(pipe->filesin) * sizeof(int));
	while (pipe->filesin[i])
	{
		pipe->outputs[i] = open(pipe->filesin[i], O_RDWR,0642);
		if (pipe->outputs[i] == -1)
		{
			pipe->A[0] = -1;
			printf("monosholo: %s:permission denied or file doesnt exitst\n", pipe->filesin[i]);
			while (i++ > 0)
				close (pipe->outputs[i]);
			break ;
		}
		i++;
	}
	pipe->A[0] = 1;
}
void	open_append(t_cmd *pipe)
{
	int	i;

	i = 0;
	if (!pipe->files_appends)
		return ;
	pipe->appends = malloc(strsnums(pipe->files_appends) * sizeof(int));
	while (pipe->files_appends[i])
	{
		pipe->appends[i] = open(pipe->files_appends[i], O_RDWR | O_CREAT | O_APPEND,0642);
		if (pipe->appends[i] == -1)
		{
			pipe->A[0] = -1;
			printf("monosholo: %s:permission denied or file doesnt exitst\n", pipe->files_appends[i]);
			while (i++ > 0)
				close (pipe->appends[i]);
			break ;
		}
		i++;
	}
	pipe->A[0] = 1;
}

void	read_write(t_cmd *pipe)
{
	pipe->read_from = malloc(sizeof(int));
	pipe->write_to = malloc(sizeof(int));
	if (pipe->lastout[0] == 1)
		pipe->read_from[0] = pipe->fd[0];
	else if (pipe->lastout[0] == 2)
		pipe->read_from[0] = pipe->inputs[strsnums(pipe->filesin) - 1];
	else
		pipe->read_from[0] = 0;
	if (pipe->lastin[0] == 1)
		pipe->write_to[0] = pipe->appends[strsnums(pipe->files_appends) - 1];
	else if (pipe->lastin[0] == 2)
		pipe->write_to[0] = pipe->outputs[strsnums(pipe->filesout) - 1];
	else
		pipe->write_to[0] =1;
}


void	files_open(t_cmd *pipe)
{
	open_her_doc(pipe);
	open_output(pipe);
	open_input(pipe);
	open_append(pipe);
	read_write(pipe);
}