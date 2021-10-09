/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublons_in_range.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamorth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:05:57 by alamorth          #+#    #+#             */
/*   Updated: 2021/10/06 10:05:59 by alamorth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_rangecontaindoublon(int *range, int size)
{
	int		i;
	int		j;
	int		current;

	i = -1;
	j = 0;
	if (!size)
		return (0);
	current = range[0];
	while (++i < size)
	{
		j = i;
		current = range[i];
		while (++j < size)
			if (range[j] == current)
				return (1);
	}
	return (0);
}
