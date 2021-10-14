/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:04:04 by bihattay          #+#    #+#             */
/*   Updated: 2021/10/06 10:04:05 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_pile *a, int id)
{
	int		buff;
	int		*tmp;
	int		size;

	tmp = a->nbr;
	size = a->size;
	if (a->size < 2)
		return ;
	buff = tmp[0];
	tmp[0] = tmp[1];
	tmp[1] = buff;
	if (id == 1)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}
