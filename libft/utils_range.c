/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamorth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:07:11 by alamorth          #+#    #+#             */
/*   Updated: 2021/10/06 10:07:18 by alamorth         ###   ########.fr       */
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
