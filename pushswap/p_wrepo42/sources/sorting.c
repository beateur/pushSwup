/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:40:18 by bihattay          #+#    #+#             */
/*   Updated: 2021/09/29 03:40:20 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_piles(t_pile *pile, t_pile *pile2)
{
	int i = -1;

	printf("presentation des piles\n");
	while (++i < pile->size)
		printf("%4d | %d\n", (pile->nbr)[i], (pile2->nbr)[i]);
}

void	sort_algo(t_pile *pile_a, t_pile *pile_b)
{
	int		pos;
	int		min;
	int		max;
	int		i;
	int		len_displayed;
	int		size;
	int ret = 0;

	pos = 0;
	min = 0;
	max = 0;
	i = -1;
	len_displayed = 0;
	size = pile_a->size;
	// int tt = 0;
	if (range_is_sorted(pile_a->nbr, pile_a->size))
		return ;
	if (pile_a->size > 25)
	{
		// quicksort(pile_a, pile_b, len_displayed);
		// // print_piles(pile_a, pile_b);
		//
		// len_displayed = insertsort_basic(pile_b, pile_a, &pos, &max);
		// // print_piles(pile_a, pile_b);
		//
		// sort_three(pile_b, 2);
		// repush(pile_a, pile_b);
		// // print_piles(pile_a, pile_b);
		//
		// // printf("\n\n\n%d\n\n\n", len_displayed);
		// while (++i < len_displayed)
		// 	rotate(pile_a, pile_a->identifier);
		// i = -1;
		// // print_piles(pile_a, pile_b);
		//
		// quicksort(pile_a, pile_b, len_displayed);
		// // print_piles(pile_a, pile_b);
		//
		// len_displayed = insertsort_basic(pile_b, pile_a, &pos, &min);
		// // print_piles(pile_a, pile_b);
		//
		// sort_three(pile_b, 2);
		// repush(pile_a, pile_b);
		// // print_piles(pile_a, pile_b);

		// while (++i < size - len_displayed)
		// {
		// 	rev_rotate(pile_a, pile_a->identifier);
		// 	push(pile_a, pile_b, pile_b->identifier);
		// }
		//
		// i = -1;
		// // quicksort(pile_a, pile_b, len_displayed);
		// // print_piles(pile_a, pile_b);
		// insertsort_basic(pile_b, pile_a, &pos, &min);
		// sort_three(pile_b, 2);
		// repush(pile_a, pile_b);
		// i = -1;
		// print_piles(pile_a, pile_b);
		while (!range_is_sorted(pile_a->nbr, pile_a->size)
			&& size - ret > 3)
		{
			i = -1;
			quicksort(pile_a, pile_b, len_displayed);
			// print_piles(pile_a, pile_b);

			len_displayed = insertsort_basic(pile_b, pile_a, &pos, &max);
			ret += len_displayed;
			// print_piles(pile_a, pile_b);

			sort_three(pile_b, 2);
			repush(pile_a, pile_b);
			// print_piles(pile_a, pile_b);

			while (++i < len_displayed)
				rotate(pile_a, pile_a->identifier);
			// print_piles(pile_a, pile_b);
		}
		while (!range_is_sorted(pile_a->nbr, pile_a->size))
			rotate(pile_a, pile_a->identifier);
		// print_piles(pile_a, pile_b);

		// push(pile_a, pile_b, pile_b->identifier);
		// push(pile_a, pile_b, pile_b->identifier);
		// push(pile_a, pile_b, pile_b->identifier);
		// sort_three(pile_b, 1);
		// repush(pile_a, pile_b);

	}
	else
		insertsort_basic(pile_a, pile_b, &pos, &min);
		sort_three(pile_a, 1);
		// printf("%d\n", pile_a->identifier);
		repush(pile_a, pile_b);
		// print_piles(pile_a, pile_b);
}

void quicksort(t_pile *pile_a, t_pile *pile_b, unsigned int len)
{
	int		pivot;
	int		i;

	i = pile_a->size - len;
	pivot = find_pivot(*pile_a, i);
	while (--i >= 0)
	{
		// printf("oauis ça passe");
		if (len == 0)
		{
			if ((pile_a->nbr)[0] < pivot)
				push(pile_a, pile_b, pile_b->identifier);
			else
				rotate(pile_a, pile_a->identifier);
		}
		else
		{
			if ((pile_a->nbr)[0] > pivot)
				push(pile_a, pile_b, pile_b->identifier);
			else
				rotate(pile_a, pile_a->identifier);
		}
	}
}

int insertsort_basic(t_pile *p_a, t_pile *p_b, int *pos, int *target)
{
	int ret;

	ret = 0;
	while (p_a->size > 3)
	{
		if (p_a->identifier == 1)
			*pos = find_smaller(*p_a, target);
		else
			*pos = find_bigger(*p_a, target);
		if (*target == (p_a->nbr)[0])
			ret += push(p_a, p_b, p_b->identifier);
		else if (*pos < ((p_a->size) / 2))
			rotate(p_a, p_a->identifier);
		else
			rev_rotate(p_a, p_a->identifier);
	}
	return (ret + 3);
}

void	sort_two(t_pile *pile_a)
{
	int		*tmp;

	tmp = pile_a->nbr;
	if (tmp[0] > tmp[1])
		swap(pile_a, pile_a->identifier);
}

static int	case_three_basic(int a, int b, int c)
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

static int	case_three_quicksort(int a, int b, int c)
{
	if (a > b && b > c)
		return (0);
	else if (b > a && a > c)
		return (1);
	else if (c < b && b > a && a < c)
		return (3);
	else if (b < a && c > a)
		return (2);
	else
		return (1);
}

void	sort_three(t_pile *pile, int c)
{
	int		*tmp;
	int		res;
	int		op;

	op = 0;
	tmp = pile->nbr;
	res = 1;
	while (res)
	{
		// printf("res %d for %d %d %d\n", res, tmp[0], tmp[1], tmp[2]);
		if (c == 1)
			res = case_three_basic(tmp[0], tmp[1], tmp[2]);
		else
			res = case_three_quicksort(tmp[0], tmp[1], tmp[2]);
		if (res == 1)
			swap(pile, pile->identifier);
		else if (res == 3)
			rotate(pile, pile->identifier);
		else if (res == 2)
			rev_rotate(pile, pile->identifier);
	}
}
