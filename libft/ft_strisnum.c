#include "libft.h"

int	ft_strisnum(const char *s)
{
	char	*src;

	if (!s)
		return (0);
	src = (char *)s;
	while(*src)
	{
		if (!ft_isdigit(*src))
			return (0);
		src++;
	}
	return (1);
}
