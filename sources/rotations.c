/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamorth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:03:42 by alamorth          #+#    #+#             */
/*   Updated: 2021/10/06 10:03:43 by alamorth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rev_rotate(t_pile *a, int id)
{
	int		buff;
	int		*tmp;
	int		size;

	tmp = a->nbr;
	size = a->size + 1;
	if (a->size < 2)
		return ;
	buff = tmp[size - 2];
	while (--size >= 2)
		tmp[size - 1] = tmp[size - 2];
	tmp[0] = buff;
	if (id == 1)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	rotate(t_pile *a, int id)
{
	int		buff;
	int		*tmp;
	int		i;

	i = -1;
	tmp = a->nbr;
	if (a->size < 2)
		return ;
	buff = tmp[0];
	while (++i < a->size)
		tmp[i] = tmp[i + 1];
	tmp[a->size - 1] = buff;
	if (id == 1)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}
