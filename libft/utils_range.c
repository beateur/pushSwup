/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:07:11 by bihattay          #+#    #+#             */
/*   Updated: 2021/10/06 10:07:18 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	range_is_sorted(int *range, int size)
{
	int		i;

	i = 0;
	while (++i < size)
		if (range[i - 1] > range[i])
			return (0);
	return (1);
}
