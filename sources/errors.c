#include "../includes/push_swap.h"

int malloc_error(void)
{
	write(2, "malloc fail\n", 12);
	exit (1);
}

int	errormsg(t_pile *p_a)
{
	free_program(p_a->nbr, NULL);
	write(2, "Error\n", 6);
	return (0);
}
