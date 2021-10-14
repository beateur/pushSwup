/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_cases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:00:59 by bihattay          #+#    #+#             */
/*   Updated: 2021/10/06 10:01:24 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	else if (b == c)
		return (0);
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
