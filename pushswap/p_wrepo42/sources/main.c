/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:39:26 by bihattay          #+#    #+#             */
/*   Updated: 2021/09/29 03:39:29 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_pile pile_a, t_pile pile_b)
{
	if (pile_a.size > 2)
		sort_algo(&pile_a, &pile_b);
	else if (pile_a.size == 2)
		sort_two(&pile_a);
}

int	errormsg(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	main(int argc, char **argv)
{
	t_pile	pile_a;
	t_pile	pile_b;
	char	**case_1;

	case_1 = parsearg(argv, argc);
	if (case_1 == NULL)
		return (errormsg());
	pile_a = pile_create(case_1);
	pile_a.identifier = 1;
	if (ft_rangecontaindoublon(pile_a.nbr, pile_a.size))
		return (errormsg());
	if (ft_maxinrange(pile_a.nbr, pile_a.size) > 2147483647)
		return (errormsg());
	pile_b.nbr = (int *)malloc(sizeof(int) * pile_a.size - 2);
	pile_b.size = 0;
	pile_b.identifier = 2;
	push_swap(pile_a, pile_b);
	// int i = -1;
	// while (++i < pile_a.size)
	// 	printf("%d | ", (pile_a.nbr)[i]);
	// write(1, "\n", 2);
	free_program(pile_a.nbr, pile_b.nbr);
	return (0);
}
