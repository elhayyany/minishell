/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:37:45 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/05/21 11:28:05 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "libft/libft.h"

typedef struct parsing
{
	int			i;
	char		*line;

}   t_cmd;
typedef struct priorities
{
	t_cmd   *cmd;
	char    **slices;
	int     numofchilds;
	char    **operator;
	char    *line;
	struct priorities   **next;
}   t_prior;

int         pre_check_line(char *line);
t_prior*	m_shell_parser(char *line, char *** operators);
void		check_malloc (void *ptr, void **ptro, int i);
int			calulate_cmds(char *line);
int		    strsnums(char	**slices);
void        free_tree(t_prior *script);
void	    tree_parser(t_prior *script);
int			next_qoute(char *line, char c);
#endif