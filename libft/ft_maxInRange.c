/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:09:08 by fberger           #+#    #+#             */
/*   Updated: 2018/11/21 23:43:39 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_maxInRange(int *tab, int size)
{
  int i;
  int ret;

  i = -1;
  if (tab && *tab)
    ret = tab[0];
  else
    ret = 0;
  while (++i < size)
  {
    if (ret < abs(tab[i]))
      ret = abs(tab[i]);
  }
  return (ret);
}
