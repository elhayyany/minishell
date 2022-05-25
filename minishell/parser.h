/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:37:45 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/05/25 12:02:01 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft/libft.h"


typedef struct parsing
{
	char	*line;
	char	*cmd;
	char	**args;
	int		*inputs_num;
	int		*outputs_num;
	int		*append_num;
	int		**appends;
	int		**outputs;
	int		**inputs;
	char	**files_appends;
	char	**filesin;
	char	**filesout;
	int		*her_doc;
	char	**her_limit;
	char	**env_var;
	char	**env_valuue;
	int		lastout;
}   		t_cmd;

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
void		tree_parser(t_prior *script, char **env);
int			next_qoute(char *line, char c);
int			all_space(char *line);
int			strsnums(char  **slices);
void		tree_parser(t_prior *script, char **env);
void		set_env(t_cmd *pipe, char **env);
void		redirections(t_cmd *pipe);
void		push_back(char	***stack, char *word);
t_cmd		*cmd_parse(char *line, char **env);
void		ft_srtuct_bzero(t_cmd *pipe);
char		*remove_quotes_str(char *str, t_cmd *pipe);
void		free_db_str(char **str);
char		*get_val(char *str, t_cmd *pipe);
void		process_quotes(t_cmd *pipe);
int			untill_char(char *str, char c);
#endif