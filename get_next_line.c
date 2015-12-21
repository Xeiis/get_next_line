/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:12:17 by dchristo          #+#    #+#             */
/*   Updated: 2015/12/21 20:34:16 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	char				*buf;
	char				**tmp;
	static	char		**save;
	static	int			*fd_save;
	int					i;
	int					boucle;
	int					len;

	boucle = 0;
	buf = ft_strnew(BUFF_SIZE);
	if ((tmp = malloc(2 * sizeof(char *))) == NULL)
		return (-1);
	tmp[0] = ft_strnew(BUFF_SIZE);
	*line = ft_strnew(BUFF_SIZE);
	tmp[1] = ft_strnew(BUFF_SIZE);
	while ((len = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[len] = '\0';
		i = -1;
		while (buf[++i] && buf[i] != '\n')
			tmp[0][i] = buf[i];
		tmp[0][i] = '\0';
		boucle++;
		if (boucle == 1)
			ft_strcpy(*line, tmp[0]);
		else
			ft_strcpy(tmp[1], *line);
		*line = ft_strnew(BUFF_SIZE * boucle);
		ft_strcpy(*line, tmp[1]);
		tmp[1] = ft_strnew(BUFF_SIZE * (boucle - 1));
		ft_strcat(*line, tmp[0]);
		if (buf[i] == '\n')
			break ;
	}
	if (buf[i] == '\n')
	{
		/*
		*save = ft_strnew(BUFF_SIZE - i);
		while (buf[i])
			**save++ = *buf;
		*/return (1);
	}
	else if (len == -1)
		return (-1);
	else
		return (0);
}
