/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:56:19 by bihattay          #+#    #+#             */
/*   Updated: 2021/10/09 17:56:21 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	malloc_error(void)
{
	write(2, "malloc fail\n", 12);
	exit (1);
}

int	errormsg(t_pile *p_a)
{
	free_program(p_a->nbr, NULL);
	write(2, "Error\n", 6);
	return (0);
}
