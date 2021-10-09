#include "libft.h"

int free_array(char **arr)
{
  int   i;

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

int ft_strdel(char **str)
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
