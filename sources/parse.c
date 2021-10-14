/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:47:01 by bihattay          #+#    #+#             */
/*   Updated: 2021/10/09 18:29:42 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	*split_andjoin(char **argv)
{
	char	*tmp;
	char	*dest;
	char	**ret;
	int		i;
	int		j;

	i = 0;
	tmp = NULL;
	while (argv[++i])
	{
		ret = ft_strsplit(argv[i], ' ');
		j = -1;
		dest = NULL;
		while (ret[++j])
		{
			dest = ft_strjoin(tmp, ret[j]);
			ft_strdel(&tmp);
			tmp = dest;
			if (tmp == NULL)
				return (NULL);
		}
		free_array(ret);
	}
	return (dest);
}

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

static int	check_whitespaces(char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			if (argv[i][j] != ' ')
				break ;
		if (j == (int)ft_strlen(argv[i]))
			return (0);
	}
	return (1);
}

char	**parsearg(char **argv)
{
	int		i;
	char	**args;
	char	*ret;

	i = -1;
	args = NULL;
	if (!check_whitespaces(argv))
		return (NULL);
	ret = split_andjoin(argv);
	if (!ret)
		return (NULL);
	while (ret[++i])
		if (!ft_isdigit(ret[i]) && ret[i] != ' '
			&& !(adjacent_of_minus(ret, i) && ret[i] == '-'))
			return (NULL);
	args = ft_strsplit(ret, ' ');
	ft_strdel(&ret);
	return (args);
}
