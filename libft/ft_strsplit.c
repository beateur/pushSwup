/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamorth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:06:42 by alamorth          #+#    #+#             */
/*   Updated: 2021/10/06 10:06:44 by alamorth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_str(char const *s, char c)
{
	int		i;
	int		flag;
	int		nb_str;

	i = -1;
	flag = 0;
	nb_str = 0;
	while (s[++i])
	{
		if (s[i] != c && flag == 0)
		{
			nb_str++;
			flag = 1;
		}
		if (s[i] == c && flag == 1)
			flag = 0;
	}
	return (nb_str);
}

static char	**nlanorm(char **str, int index)
{
	str[index] = 0;
	return (str);
}

static int	str_len(char const *s, char c)
{
	int		i;

	i = -1;
	while (s[++i] != c && s[i] != '\0')
		;
	return (i);
}

static void	mallocno(char **str)
{
	if (str == NULL)
	{
		write(2, "malloc fail\n", 12);
		exit(1);
	}
}

char	**ft_strsplit(char const *s, char c)
{
	char	**strs;
	int		i;
	int		str;
	int		len;

	strs = (char **)malloc(sizeof(char *) * (count_str(s, c) + 1));
	if (!s || strs == NULL)
		return ((char **) NULL);
	i = -1;
	str = 0;
	while (s[++i])
	{
		if (s[i] != c && str < count_str(s, c))
		{
			len = str_len(&s[i], c);
			strs[str] = (char *)malloc(sizeof(char) * len + 1);
			mallocno(strs);
			while (s[i] != c && s[i] != '\0')
				*(strs[str])++ = s[i++];
			*(strs[str]) = '\0';
			strs[str] = (&(*strs[str]) - len);
			str++;
		}
	}
	return (nlanorm(strs, str));
}
