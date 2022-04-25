#include "minishell.h"

void error(char *str)
{
    write(2, "ERROR: ", 7);
    while (str)
        write(2, str++, 1);
}