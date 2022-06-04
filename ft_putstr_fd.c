/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:35:26 by kkaneko           #+#    #+#             */
/*   Updated: 2022/06/05 01:07:52 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include "libft.h"

static size_t	ft_min(size_t a, size_t b);

void	ft_putstr_fd(char *s, int fd)
{
	const size_t	strlen = ft_strlen(s);
	size_t			i;

	if (s == NULL)
		return ;
	i = 0;
	while (i < strlen)
	{
		write(fd, s + i, ft_min(strlen - i, INT_MAX));
		i += INT_MAX;
	}
}

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
/*
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int	main(int ac, char **av)
{
	int fd = open("putstr_test.txt", O_RDWR | O_CREAT, S_IREAD | S_IWRITE);
	ft_putstr_fd(av[1], fd);
	system("cat putstr_test.txt");
	close(fd);
	return (0);
}
*/
