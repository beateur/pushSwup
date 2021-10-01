/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:39:17 by bihattay          #+#    #+#             */
/*   Updated: 2021/09/29 03:39:19 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	free_program(int *pile_a, int *pile_b)
{
	if (pile_a)
		ft_intdel(&pile_a);
	if (pile_b)
		ft_intdel(&pile_b);
	return (0);
}
