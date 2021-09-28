#include "../includes/push_swap.h"

void	pile_fill(t_pile *pile, char **argv)
{
	int	*tmp;
	int	i;

	i = 0;
	tmp = pile->nbr;
	while (argv[i])
	{
		*tmp = ft_atoi(argv[i]);
		tmp++;
		i++;
	}
}
