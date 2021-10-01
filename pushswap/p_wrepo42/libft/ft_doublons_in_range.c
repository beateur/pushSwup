/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublons_in_range.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:37:05 by bihattay          #+#    #+#             */
/*   Updated: 2021/09/29 03:43:00 by bihattay         ###   ########.fr       */
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
