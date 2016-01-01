#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*cpy;
	char	*out;
	int		len;

	out = str;
	len = ft_strlen(str);
	cpy = ft_strdup(str);
	if(cpy == NULL)
		return NULL;
	while (len > 0)
		*str++ = cpy[--len];
	free(cpy);
	return (out);
}
