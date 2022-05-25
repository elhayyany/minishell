/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:09:49 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/05/25 19:58:56 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor/minishell.h"




// char *get_next_line(void)
// {
//     static char str[80000000] = {0};
//     char 		buf;

//     int i;
//     i = 0;
//     while(1)
//     {
// 		read(0, &buf, 1);
//         if(buf == '\n')
//             break;
//         str[i++] = buf;
//     }
//     str[i] = '\0';
//     if(str[0] == 0)
//         return (NULL);
//     return (ft_strdup(str));
// }

void	get_herdoc(t_cmd *pipe, int j, char *limit)
{
	char	*line;

	
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			printf("az\n");
			continue ;
		}
		if (!ft_strncmp(line, limit, ft_strlen(line)))
		{
			free(line);
			return ;
		}
		if (j == 1)
		{
			line = get_val(line, pipe, 0);
		}
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


void	open_outputs()
{
	
}

void	files_open(t_cmd *pipe)
{
	open_her_doc(pipe);
	open_output(pipe);
	// open_input(pipe);
	// read_write(pipe);
}