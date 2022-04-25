#include "minishell.h"

int main(int ac, char **av)
{
    t_data  *data;

    data = NULL;
    if (!init_data(&data, av, ac))
        error("Fail to allocate the data\n");
    for(int i = 0; i < ac; i++){
        printf(RED "%s\n" RESET, data->terminal[i]);
    }
}