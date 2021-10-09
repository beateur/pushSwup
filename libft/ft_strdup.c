#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		size;

	size = 0;
	if (!src)
		return (NULL);
	while (src[size])
		size++;
	dest = malloc((size + 2) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i++] = ' ';
	dest[i] = '\0';
	return (dest);
}
