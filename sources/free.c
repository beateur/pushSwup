/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamorth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:02:23 by alamorth          #+#    #+#             */
/*   Updated: 2021/10/06 10:02:31 by alamorth         ###   ########.fr       */
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
