/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:39:35 by bihattay          #+#    #+#             */
/*   Updated: 2021/09/29 03:42:28 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	adjacent_of_minus(char *str, int index)
{
	int		i;

	i = -1;
	if (index == 0)
		return (ft_isdigit(str[1]));
	while (str[++i])
		;
	if (index == i)
		return (0);
	return (str[index - 1] == ' ' && ft_isdigit(str[index + 1]));
}

char	**parsearg(char **argv, int argc)
{
	int	i;
	int	j;

	i = -1;
	if (argc == 1 || (!ft_isdigit(argv[1][0]) && argv[1][0] != '-'))
		return (NULL);
	if (argc == 2)
	{
		while (argv[1][++i])
			if (!ft_isdigit(argv[1][i]) && argv[1][i] != ' '
			&& !adjacent_of_minus(argv[1], i))
				return (NULL);
		return (ft_strsplit(argv[1], ' '));
	}
	i = 0;
	while (argv[++i])
	{
		j = -1;
		if (argv[i][0] == '-' && ft_strlen(argv[i]) == 1)
			return (NULL);
		while (argv[i][++j])
			if (!(j == 0 && argv[i][0] == '-') && !ft_isdigit(argv[i][j]))
				return (NULL);
	}
	return (argv + 1);
}
