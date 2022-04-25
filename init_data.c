#include "minishell.h"

int init_data(t_data **data, char **av, int ac)
{
    *data = malloc(sizeof(t_data));
    if (!*data)
        return (0);
    (*data)->args = ac;
    (*data)->terminal = av;
    return (1);
}