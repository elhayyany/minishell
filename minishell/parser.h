/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:37:45 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/05/22 16:19:42 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft/libft.h"

typedef struct parsing
{
	int		s_there_herd;
	int		where_herc;
	char	*line;
	char	*cmd;
	char	**args;
	int		inputs_num;
	int		outputs_num;
	int		append_num;
	int		**appends;
	int		**outputs;
	int		**inputs;
	char	**files_appends;
	char	**filesin;
	char	**filesout;
	int		here_doc;
	char	**her_limite
	// char	**cmd_and_args;
}   		t_cm;
typedef struct priorities
{
	t_cmd				*cmd;
	char				**slices;
	int					numofchilds;
	char				**operator;
	char				*line;
	struct priorities	**next;
}	t_prior;

int			pre_check_line(char *line);
t_prior*	m_shell_parser(char *line, char *** operators);
void		check_malloc (void *ptr, void **ptro, int i);
int			calulate_cmds(char *line);
int			strsnums(char	**slices);
void		free_tree(t_prior *script);
void		tree_parser(t_prior *script);
int			next_qoute(char *line, char c);
int			all_space(char *line);
#endif