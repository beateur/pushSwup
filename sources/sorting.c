#include "../includes/push_swap.h"

void	sort_algo(t_pile *pile_a, t_pile *pile_b)
{
	int	pos;
	int	min;
  int secondmin;

	while (pile_a->size > 3)
	{
		pos = find_smaller(*pile_a, &min, &secondmin);
		if (min == (pile_a->nbr)[0])
			push(pile_a, pile_b, 'n');
		else if (pos < ((pile_a->size) / 2))
			rotate(pile_a);
		else
			rev_rotate(pile_a);
	}
	sort_three(pile_a);
	repush(pile_a, pile_b);
}

void sort_two(t_pile *pile_a)
{
	int		*tmp;

	tmp = pile_a->nbr;
	if (tmp[0] > tmp[1])
	{
		swap(pile_a);
	}
}

static int	case_three(int a, int b, int c)
{
	if (a < b && b < c)
		return (0);
	else if (a > b && a < c)
		return (1);
  else if (a > b && b > c)
    return (3);
	else if (a > b && b < c && a > c)
		return (3);
	else if (a < b && b > c && a > c)
		return (2);
	else
		return (1);
}

void sort_three(t_pile *pile_a)
{
	int		*tmp;
	int		res;
	int		op;

	op = 0;
	tmp = pile_a->nbr;
	while ((res = case_three(tmp[0], tmp[1], tmp[2])))
	{
		if (res == 1)
			swap(pile_a);
		else if (res == 3)
			rotate(pile_a);
		else if (res == 2)
			rev_rotate(pile_a);
	}
}
