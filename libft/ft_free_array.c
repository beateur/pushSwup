/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:54:26 by bihattay          #+#    #+#             */
/*   Updated: 2021/10/09 17:54:38 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	free_array(char **arr)
{
	int	i;

	i = -1;
	if (arr)
	{
		while (arr[++i])
			if (!ft_strdel(&(arr[i])))
				return (0);
		free(arr);
		arr = NULL;
		return (1);
	}
	return (0);
}

int	ft_strdel(char **str)
{
	if (str)
	{
		if (*str)
		{
			free(*str);
			*str = NULL;
		}
		return (1);
	}
	return (0);
}
