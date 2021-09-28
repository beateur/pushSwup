#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_pile
{
	int	*nbr;
	int	size;
}	t_pile;

char **parsearg(char **argv, int argc);
int free_program(int *pile_a, int *pile_b);
void	pile_fill(t_pile *pile, char **argv);
t_pile	pile_create(char **argv);
void			repush(t_pile *dest, t_pile *src);
void	sort_algo(t_pile *pile_a, t_pile *pile_b);
void sort_two(t_pile *pile_a);
void sort_three(t_pile *pile_a);
void rotate(t_pile *a);
void	swap(t_pile *a);
void rev_rotate(t_pile *a);
void	push(t_pile *a, t_pile *b, char c);
int	find_smaller(t_pile pile, int *min, int *secondmin);
void	push(t_pile *a, t_pile *b, char c);
void			repush(t_pile *dest, t_pile *src);

#endif
