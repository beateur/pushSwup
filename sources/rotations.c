#include "../includes/push_swap.h"

void rev_rotate(t_pile *a)
{
			int buff;
			int *tmp;
			int size;
			int i;

			tmp = a->nbr;
			size = a->size + 1;

			if (a->size < 2)
				return ;
			buff = tmp[size - 2];
			while (--size >= 2)
				tmp[size - 1] = tmp[size - 2];
			tmp[0] = buff;
      // pile_print(*a);
			write(1, "rra\n", 4);
}

void rotate(t_pile *a)
{
	int buff;
	int *tmp;
	int size;
	int i;

	i = -1;
	tmp = a->nbr;
	size = a->size;
	if (a->size < 2)
		return;
	buff = tmp[0];
	while (++i < size)
		tmp[i] = tmp[i + 1];
	tmp[size - 1] = buff;
	write(1, "rr\n", 3);
}
