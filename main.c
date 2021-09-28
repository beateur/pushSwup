#include "includes/push_swap.h"
#include <stdio.h>

static int	init_program(char **argv, t_pile *pile)
{
	*pile = pile_create(argv);
	return (1);
}

void	pile_print(t_pile pile)
{
	int	i;

	i = 0;
	while (i < pile.size)
	{
		ft_putnbr(pile.nbr[i]);
		ft_putchar('|');
		i++;
	}
}

int	find_smaller(t_pile pile, int *min, int *secondmin)
{
	int	i;
	int j;
	int lastmin;

	i ^= i;;
	*min = (pile.nbr)[0];
	lastmin ^= lastmin;
	while (++i < pile.size)
	{
		if ((pile.nbr)[i] < *min)
		{
			lastmin = *min;
			*min = (pile.nbr)[i];
		}
	}
	i ^= i;
	while ((pile.nbr)[i] != *min)
		i++;
	j = -1;
	if (i == 0)
		lastmin = (pile.nbr)[1];
	else
		lastmin = (pile.nbr)[i - 1];
	while (++j < pile.size)
		if ((pile.nbr)[j] != *min && (pile.nbr)[j] < lastmin)
			lastmin = (pile.nbr)[j];
	*secondmin = lastmin;
	return (i);
}

void	push_swap(t_pile pile_a)
{
	t_pile	pile_b;

	pile_b.nbr = (int*)malloc(sizeof(int) * pile_a.size - 2);
	pile_b.size = 0;

	if (pile_a.size > 2)
	{
		sort_algo(&pile_a, &pile_b);
		// pile_sort(&pile_a, &pile_b);
		pile_print(pile_a);
	}
	else if (pile_a.size == 2)
	{
		sort_two(&pile_a);
		pile_print(pile_a);
	}
	else
	{
		// printf("trop facile a trierg");
	}
}

char **parsearg(char **argv, int argc)
{
	int i;
	int j;
	char **argret;

	i ^= i;
	argret = NULL;
	if (!ft_isdigit(argv[1][0]))
		return (NULL);
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (!ft_isdigit(argv[1][i]) && argv[1][i] != ' ')
				return (NULL);
			i++;
		}
		argret = ft_strsplit(argv[1], ' ');
		return (argret);
	}
	i ^= 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				return (NULL);
	}
	argret = argv;
	return (++argret);
}

int	main(int argc, char **argv)
{
	t_pile	pile_a;
	int	ret;
	char **case_1;

	// parse argv
	/*
			cas d'erreur: espace au début ou non numéri
	*/
	// printf("argv 1 = %s\n", argv[1]);

	if (!(case_1 = (char **)malloc(sizeof(char *) * 1)))
	{
		write(1, "malloc fail", 11);
		return (1);
	}
	case_1 = NULL;
	if (!(case_1 = parsearg(argv, argc)))
	{
		write(1, "Error\n", 6);
		if (case_1 != NULL)
			free(case_1);
		return (0);
	}
	ret = init_program(case_1, &pile_a);
	push_swap(pile_a);
	return (0);
}
