/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:03:05 by bihattay          #+#    #+#             */
/*   Updated: 2021/10/06 10:03:07 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_pile	pile_malloc(int size)
{
	t_pile	pile;

	pile.nbr = (int *)malloc(sizeof(int) * size);
	if (pile.nbr == NULL)
		malloc_error();
	pile.size = size;
	return (pile);
}

t_pile	pile_create(char **argv)
{
	int		i;
	t_pile	pile;

	i = 0;
	while (argv[i])
		i++;
	pile = pile_malloc(i);
	pile_fill(&pile, argv);
	return (pile);
}

t_quick_sort	st_qck_sort(t_pile *pile_a, unsigned int len, unsigned int ret)
{
	t_quick_sort	structure;

	structure.y = pile_a->size - ret - 1;
	structure.pivot = find_pivot(*pile_a, pile_a->size - ret, ret);
	structure.u = 0;
	structure.first = 0;
	structure.count = 0;
	structure.i = pile_a->size - len;
	return (structure);
}
