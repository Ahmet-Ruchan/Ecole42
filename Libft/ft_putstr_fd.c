/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavci <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:17:16 by aavci             #+#    #+#             */
/*   Updated: 2022/06/23 15:17:19 by aavci            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

#include <fcntl.h>
int	main(void)
{
	int  a = open("abc.txt", O_WRONLY | O_CREAT);

	ft_putstr_fd("yavuztalhaislam", a);
}