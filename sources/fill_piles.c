/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_piles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <bihattay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:01:39 by bihattay          #+#    #+#             */
/*   Updated: 2021/10/07 13:05:31 by bihattay         ###   ########.fr       */
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
