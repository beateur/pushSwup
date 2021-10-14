/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:04:27 by bihattay          #+#    #+#             */
/*   Updated: 2021/10/09 17:56:52 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_pile
{
	int		*nbr;
	int		size;
	int		identifier;
}				t_pile;

typedef struct s_quick_sort
{
	int		pivot;
	int		y;
	int		u;
	int		first;
	int		count;
	int		i;
}				t_quick_sort;

int				malloc_error(void);
int				errormsg(t_pile *p_a);
t_quick_sort	st_qck_sort(t_pile *pile_a, unsigned int len, unsigned int ret);
void			quicksort(t_pile *p, t_pile *t, unsigned int l, unsigned int r);
int				insertsort_basic(t_pile *p_a, t_pile *p_b, int *pos, int *min);
int				find_pivot(t_pile pile, int len, unsigned int ret);
int				find_smaller(t_pile pile, int *min);
int				find_bigger(t_pile pile, int *max);
char			**parsearg(char **argv);
int				free_program(int *pile_a, int *pile_b);
void			pile_fill(t_pile *pile, char **argv);
t_pile			pile_create(char **argv);
void			repush(t_pile *dest, t_pile *src);
void			sort_algo(t_pile *pile_a, t_pile *pile_b);
void			sort_two(t_pile *pile_a);
void			sort_three(t_pile *pile, int c);
void			rotate(t_pile *a, int id);
void			swap(t_pile *a, int id);
void			rev_rotate(t_pile *a, int id);
int				push(t_pile *a, t_pile *b, int c);
int				find_smaller(t_pile pile, int *min);
void			repush(t_pile *dest, t_pile *src);

#endif
