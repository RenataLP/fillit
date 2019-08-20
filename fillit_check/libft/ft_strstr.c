/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:26:27 by pnita             #+#    #+#             */
/*   Updated: 2019/04/11 20:26:29 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	char	*h;
	char	*n;

	if (!*needle)
		return ((char*)haystack);
	h = (char*)haystack;
	n = (char*)needle;
	i = 0;
	while (h[i] != '\0')
	{
		if (h[i] == *n && ft_is_equal(h + i, n))
			return (h + i);
		i++;
	}
	return (0);
}
