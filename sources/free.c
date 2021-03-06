/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:02:23 by bihattay          #+#    #+#             */
/*   Updated: 2021/10/06 10:02:31 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	free_program(int *pile_a, int *pile_b)
{
	if (!pile_a)
		return (0);
	else
		ft_intdel(&pile_a);
	if (!pile_b)
		return (0);
	else
		ft_intdel(&pile_b);
	return (0);
}
