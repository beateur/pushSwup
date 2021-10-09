#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dest;
	int	i;
	int	j;
	unsigned int	s1l;
	unsigned int	s2l;

	i = -1;
	j = -1;
	if (!s1)
		return (ft_strdup((s2)));
	if (!s2)
		return (ft_strdup((char *)(s1)));
	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	dest = malloc(sizeof(char) * (s1l + s2l + 2));
	if (!dest || (!s1 && !s2))
		return (NULL);
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[++j])
		dest[i++] = s2[j];
	dest[i++] = ' ';
	dest[i] = '\0';
	return (dest);
}
