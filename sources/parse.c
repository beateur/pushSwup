/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamorth <alamorth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:02:52 by alamorth          #+#    #+#             */
/*   Updated: 2021/10/07 12:56:51 by alamorth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char *split_andjoin(char **argv)
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
// reste un leak
char	**parsearg(char **argv)
{
	int	i;
	char **args;
	char *ret;

	i = 0;
	args = NULL;
	while (argv[++i])
		if (!ft_strlen(argv[i]))
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
