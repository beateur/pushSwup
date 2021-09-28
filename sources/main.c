#include "../includes/push_swap.h"

int	find_smaller(t_pile pile, int *min, int *secondmin)
{
	int	i;
	int j;
	int lastmin;

	i = 0;
	*min = (pile.nbr)[0];
	lastmin = 0;
	while (++i < pile.size)
	{
		if ((pile.nbr)[i] < *min)
		{
			lastmin = *min;
			*min = (pile.nbr)[i];
		}
	}
	i = 0;
	while ((pile.nbr)[i] != *min)
		i++;
	j = -1;
	if (i == 0)
		lastmin = (pile.nbr)[1];
	else
		lastmin = (pile.nbr)[i - 1];
	while (++j < pile.size)
		if ((pile.nbr)[j] != *min && (pile.nbr)[j] < lastmin)
			lastmin = (pile.nbr)[j];
	*secondmin = lastmin;
	return (i);
}

void	push_swap(t_pile pile_a, t_pile pile_b)
{
	if (pile_a.size > 2)
		sort_algo(&pile_a, &pile_b);
	else if (pile_a.size == 2)
		sort_two(&pile_a);
}

int errormsg()
{
	write(2, "Error\n", 6);
	return (0);
}

int	main(int argc, char **argv)
{
	t_pile	pile_a;
	t_pile	pile_b;
	char **case_1;

	case_1 = NULL;
	if (!(case_1 = parsearg(argv, argc)))
		return (errormsg());
	pile_a = pile_create(case_1);
	if (ft_rangecontaindoublon(pile_a.nbr, pile_a.size))
		return (errormsg());
	if (ft_maxinrange(pile_a.nbr, pile_a.size) > 2147483647)
		return (errormsg());
	pile_b.nbr = (int*)malloc(sizeof(int) * pile_a.size - 2);
	pile_b.size = 0;
	push_swap(pile_a, pile_b);
	free_program(pile_a.nbr, pile_b.nbr);
	return (0);
}
