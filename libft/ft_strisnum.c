/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmese <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 21:47:55 by dpalmese          #+#    #+#             */
/*   Updated: 2024/05/24 21:48:17 by dpalmese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strisnum(const char *s)
{
	char	*src;

	if (!s)
		return (0);
	src = (char *)s;
	while (*src)
	{
		if (!ft_isdigit(*src))
			return (0);
		src++;
	}
	return (1);
}
