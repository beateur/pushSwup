#include "../includes/push_swap.h"

char **parsearg(char **argv, int argc)
{
	int i;
	int j;

	i = -1;
	if (argc == 1 || !ft_isdigit(argv[1][0]))
		return (NULL);
	if (argc == 2)
	{
		while (argv[1][++i])
			if (!ft_isdigit(argv[1][i]) && argv[1][i] != ' ')
				return (NULL);
		return (ft_strsplit(argv[1], ' '));
	}
	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				return (NULL);
	}
	return (argv + 1);
}
