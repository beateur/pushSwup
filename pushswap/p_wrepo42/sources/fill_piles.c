/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_piles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:39:07 by bihattay          #+#    #+#             */
/*   Updated: 2021/09/29 03:39:10 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pile_fill(t_pile *pile, char **argv)
{
	int	*tmp;
	int	i;

	i = 0;
	tmp = pile->nbr;
	while (argv[i])
	{
		*tmp = ft_atoi(argv[i]);
		tmp++;
		i++;
	}
}
