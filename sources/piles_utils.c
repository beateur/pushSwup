#include "../includes/push_swap.h"

static t_pile	pile_malloc(int size)
{
	t_pile pile;

	pile.nbr = (int*)malloc(sizeof(int) * size);
	pile.size = size;
	return (pile);
}

t_pile	pile_create(char **argv)
{
	int	i;
	t_pile pile;

  i = 0;
	while (argv[i])
		i++;
	pile = pile_malloc(i);
	pile_fill(&pile, argv);
	return (pile);
}
