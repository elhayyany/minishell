


#include "parser.h"

int next_qoute(char *line, char c)
{
	int i;

	i = 1;
	while (line[i])
	{
		if (line[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int check_parentheses(char *line)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
			i += next_qoute(&line[i], line[i]);
		else if (line[i] == '(')
		{
			if (i == 0)
				j++;
			else
			{
				k = i - 1;
				while (k >= 0)
				{
					if (line[k] == ' ')
					{
						k--;
						continue ;
					}
					if (line[k] != '|' && line[k] != '&')
						return (1);
					else
						break ;
					k--;
				}
				j++;
			}
		}     
		else if (line[i] == ')')
			j--;
		if (j < 0 )
			return (1);
		i++;
	}
	return (0);
}
int	check_andor(char *line)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (line[i])
	{
		if (line[i] == '|' || line[i] == '&')
		{
			if (i == 0)
				return (1);
			else
			{
				k = i - 1;
				while (k >= 0)
				{
					if (line[k] == ' ')
					{
						k--;
						continue ;
					}
					if (line[k] == '|' || line[k] == '&' || line[i] == '(')
						return (1);
					else
						break ;
				}
				if (k == 0 && line[k] == ' ')
					return (1);
			}
			if (line[i + 1] == '|' || line[i] == '&')
				i++;
		}
		i++;
	}
	return(0);
}
int pre_check_line(char *line)
{
	if (check_parentheses(line) || check_andor(line))
	{
		write(2, ">$ syntax error near unexpected token\n", 38);
		return (1);
	}
	printf("prelineexit\n");
	return (0);
}