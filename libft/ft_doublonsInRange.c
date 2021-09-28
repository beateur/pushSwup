/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 04:04:16 by fberger           #+#    #+#             */
/*   Updated: 2018/11/17 05:36:48 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_rangeContainDoublon(int *range, int size)
{
  int i;
  int j;
  int current;

  i = 0;
  j = 0;
  if (!size)
    return (0);
  current = range[0];
  while (++i < size)
  {
    j = i - 1;
    while (++j < size)
      if (range[j] == current)
        return (1);
  }
  return (0);
}
