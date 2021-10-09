/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_piles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamorth <alamorth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:01:39 by alamorth          #+#    #+#             */
/*   Updated: 2021/10/07 13:05:31 by alamorth         ###   ########.fr       */
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
