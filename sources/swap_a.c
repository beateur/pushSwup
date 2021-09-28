#include "../includes/push_swap.h"

void	swap(t_pile *a)
{
	int		buff;
	int		*tmp;
	int		size;

	tmp = a->nbr;
	size = a->size;
	if (a->size < 2)
		return ;
	buff = tmp[0];
	tmp[0] = tmp[1];
	tmp[1] = buff;
	write(1, "sa\n", 3);
}
