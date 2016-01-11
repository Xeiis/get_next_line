/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:46:12 by dchristo          #+#    #+#             */
/*   Updated: 2016/01/11 20:36:33 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		res;

	while (--argc)
	{
		fd = open(argv[argc], O_RDONLY);
		while ((res = get_next_line(fd, &line)) > 0)
		{
			ft_putchar('[');
			ft_putnbr(res);
			ft_putchar(']');
			ft_putchar(':');
			ft_putendl(line);
		}
	}
}
