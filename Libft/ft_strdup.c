/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavci <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:52:36 by aavci             #+#    #+#             */
/*   Updated: 2022/02/07 16:53:02 by aavci            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	p = malloc(sizeof(char) * len + 1);
	if (!p)
		return (0);
	i = 0;
	while (len > i)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
