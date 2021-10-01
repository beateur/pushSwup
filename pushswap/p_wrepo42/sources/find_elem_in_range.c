/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_piles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:39:07 by bihattay          #+#    #+#             */
/*   Updated: 2021/09/29 03:39:10 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int find_pivot(t_pile pile, unsigned int len)
{
  int ret;
  int i;

  ret = 0;
  i = -1;
  while ((unsigned int)++i < len)
    ret += pile.nbr[i];
  return (ret / i);
}

int	find_smaller(t_pile pile, int *min)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	*min = (pile.nbr)[0];
	while (++i < pile.size)
		if ((pile.nbr)[i] < *min)
		{
			*min = (pile.nbr)[i];
			ret = i;
		}
	return (ret);
}

int	find_bigger(t_pile pile, int *max)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	*max = (pile.nbr)[0];
	while (++i < pile.size)
		if ((pile.nbr)[i] > *max)
		{
			*max = (pile.nbr)[i];
			ret = i;
		}
	return (ret);
}
