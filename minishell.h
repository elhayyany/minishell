#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

typedef struct s_list{
    char    **terminal;
    int     args;
}   t_data;


void    error(char *str);
int     init_data(t_data *data, char **av, int ac);
#endif