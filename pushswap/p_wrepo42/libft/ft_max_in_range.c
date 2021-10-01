/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_in_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:37:51 by bihattay          #+#    #+#             */
/*   Updated: 2021/09/29 03:37:53 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_maxinrange(int *tab, int size)
{
	int		i;
	int		ret;
	int		compare;

	i = -1;
	compare = 0;
	if (tab && *tab)
		ret = tab[0];
	else
		ret = 0;
	while (++i < size)
	{
		if (tab[i] < 0)
			compare = -tab[i];
		else
			compare = tab[i];
		if (ret < compare)
			ret = compare;
	}
	return (ret);
}
