#include "../includes/push_swap.h"

void	push(t_pile *a, t_pile *b, char c)
{
	int *tmp_a;
	int *tmp_b;
	int buff;
	int count;

	tmp_a = a->nbr;
	tmp_b = b->nbr;

	b->size++;
	count = b->size;
	while (--count > 0)
		tmp_b[count] = tmp_b[count - 1];
	tmp_b[0] = tmp_a[0];
	count = -1;
	while (++count < a->size - 1)
		tmp_a[count] = tmp_a[count + 1];
	tmp_a[a->size - 1] = 0;
	a->size--;
	if (c == 'c')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void			repush(t_pile *dest, t_pile *src)
{
	while (src->size > 0)
	{
		push(src, dest, 'c');
	}

}
