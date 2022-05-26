/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:50:09 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/05/26 10:48:58 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "executor/minishell.h"

// int main(int ac, char **sv, char **env)
// {
// 	char     *line;
// 	t_prior  *script;
// 	char		**operators;

// 	line = 0;
// 	while (1)
// 	{
// 		line = readline(">$ ");
// 		if (!line  || line[0] == '\0')
// 		{
// 			if (line && line[0] == '\0')
// 			{
// 				free(line);
// 				continue ;
// 			}
// 			write(1, "\n", 1);
// 			continue ;
// 		}
// 		if (!all_space(line))
// 		{
// 			free(line);
// 			continue ;
// 		}
// 		// if (pre_check_line(line))
// 		// {
// 		//    free(line);
// 		//    continue ;
// 		// }
// 		script = m_shell_parser(line, &operators);
// 		tree_parser(script, char **env);
// 		free_tree(script);
// 		free(script);
// 		free (line);
//    }
// }



int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_cmd *cmd = NULL;
	// cmd = malloc (sizeof(t_cmd));
	//ft_srtuct_bzero(cmd);
	// char *line = calloc(1, 250);
	//set_env(cmd, env);
	// cmd->cmd = 0;
	// cmd->args = 0;
	char *line = readline("monosholoo-1.0$ ");
	int i = 0;
	while (line[i])
		i++;
	// int i = 0;
	// while (av[1][i])
	// {
	// 	line[i] = av[1][i];
	// 	i++;
	// }
	cmd = cmd_parse(line, env);
	printf("%s\n", cmd->filesout[0]);
	// printf("%s\n", cmd->her_limit[0]);
	//redirections(cmd);
	//printf("az\n");
	//process_quotes(cmd);

}