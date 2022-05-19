
#include "executor/minishell.h"
 
int main()
{
   char    *line;
   t_prior *script;
 
   line = 0;
   while (1)
   {
       line = readline(">$ ");
        if (!line)
        {
            write(1, "\n", 1);
            continue ;
        }
       if (pre_check_line(line))
       {          
           free(line);
           continue ;
       }
       script = m_shell_parser(line);
       free (line);
   }
}
