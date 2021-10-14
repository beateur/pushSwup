/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <bihattay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:02:41 by bihattay          #+#    #+#             */
/*   Updated: 2021/10/09 18:36:17 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_pile pile_a, t_pile pile_b)
{
	if (!pile_b.nbr)
	{
		free_program(pile_a.nbr, NULL);
		malloc_error();
		exit(1);
	}
	if (pile_a.size > 2)
		sort_algo(&pile_a, &pile_b);
	else if (pile_a.size == 2)
		sort_two(&pile_a);
}

int	check_overflow(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_pile	pile_a;
	t_pile	pile_b;
	char	**case_1;

	pile_a.nbr = NULL;
	if (argc < 2)
		return (0);
	if (check_overflow(argv))
		return (errormsg(&pile_a));
	case_1 = parsearg(argv);
	if (case_1 == NULL)
		return (errormsg(&pile_a));
	pile_a = pile_create(case_1);
	pile_a.identifier = 1;
	if (ft_rangecontaindoublon(pile_a.nbr, pile_a.size))
		return (errormsg(&pile_a));
	pile_b.nbr = (int *)malloc(sizeof(int) * pile_a.size - 2);
	pile_b.size = 0;
	pile_b.identifier = 2;
	push_swap(pile_a, pile_b);
	free_program(pile_a.nbr, pile_b.nbr);
	return (0);
}
