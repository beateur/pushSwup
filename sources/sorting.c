#include "../includes/push_swap.h"

void	sort_algo(t_pile *pile_a, t_pile *pile_b)
{
	int	pos;
	int	min;
  int secondmin;

	while (pile_a->size > 3)
	{
		pos = find_smaller(*pile_a, &min, &secondmin);
		// printf("position est: %d\n", pos);
		if (min == (pile_a->nbr)[0])
			push(pile_a, pile_b, 'n');
    // else if (min == (pile_a->nbr)[pile_a->size - 1])
    // 		rev_rotate(pile_a);
		// else if (min == (pile_a->nbr)[1] && pile_b->size == 0)
		// 	swap(pile_a);
    // else if (secondmin == (pile_a->nbr)[0])
    //   push(pile_a, pile_b, 'n');
		else if (pos < ((pile_a->size) / 2))
			rotate(pile_a);
		else
			rev_rotate(pile_a);
	}
	int i = 0;
	// while (i < pile_a->size - 1) {
	// 	printf("%d\n", pile_a->nbr[i]);
	// 	i++;
	// }
	sort_three(pile_a);
	repush(pile_a, pile_b);

//	printf("attention finish\n");
}

void sort_two(t_pile *pile_a)
{
	int		*tmp;
	int		res;

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
		// printf("a b et c sont: %d %d %d\n", tmp[0], tmp[1], tmp[2]);
		if (res == 1)
			swap(pile_a);
		else if (res == 3)
			rotate(pile_a);
		else if (res == 2)
			rev_rotate(pile_a);
	}
}
