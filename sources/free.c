#include "../includes/push_swap.h"

int free_program(int *pile_a, int *pile_b)
{
  if (pile_a)
    ft_intdel(&pile_a);
  if (pile_b)
    ft_intdel(&pile_b);
  return (0);
}
