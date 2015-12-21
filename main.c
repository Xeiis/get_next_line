/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:46:12 by dchristo          #+#    #+#             */
/*   Updated: 2015/12/21 20:27:23 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	while (--argc)
	{
		if ((fd = open(argv[argc], O_RDONLY)) == -1)
			return (0);
		get_next_line(fd, &line);
		ft_putendl(line);
	}
}
