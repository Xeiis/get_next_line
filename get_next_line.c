/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:12:17 by dchristo          #+#    #+#             */
/*   Updated: 2015/12/22 22:38:42 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

int		in_while(char *tmp, char *tmp2, int *boucle, char **line, int i)
{
	tmp[i] = '\0';
	*boucle = *boucle + 1;
	ft_strcpy(tmp2, *line);
	free(*line);
	if ((*line = ft_strnew(BUFF_SIZE * *boucle)) == NULL)
		return (-1);
	ft_strcpy(*line, tmp2);
	free(tmp2);
	if ((tmp2 = ft_strnew(BUFF_SIZE * *boucle)) == NULL)
		return (-1);
	ft_strcat(*line, tmp);
	return (0);
}

int		retour(int len, char *buf, char *save, int i)
{
	int		j;

	j = 0;
	if (len == 0)
		return (0);
	else if (buf[i] == '\n')
	{
		while (buf[++i])
			save[j++] = buf[i];
		save[j] = '\0';
		return (1);
	}
	else if (len == -1)
		return (-1);
	else
		return (0);
}

int		init(char **tmp, char **line, char **buf, char **tmp2)
{
	if ((*tmp = ft_strnew(BUFF_SIZE)) == NULL)
		return (-1);
	if ((*tmp2 = ft_strnew(BUFF_SIZE)) == NULL)
		return (-1);
	if ((*line = ft_strnew(BUFF_SIZE)) == NULL)
		return (-1);
	if ((*buf = ft_strnew(BUFF_SIZE)) == NULL)
		return (-1);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	char				*buf;
	char				*tmp;
	char				*tmp2;
	static	char		*save;
	int					i;
	int					boucle;
	int					len;

	boucle = 0;
	if ((init(&tmp, line, &buf, &tmp2)) == -1)
		return (-1);
	if (!save)
		if ((save = ft_strnew(BUFF_SIZE)) == NULL)
			return (-1);
	ft_strcpy(*line, save);
	while ((len = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[len] = '\0';
		i = -1;
		while (buf[++i] && buf[i] != '\n')
			tmp[i] = buf[i];
		if ((in_while(tmp, tmp2, &boucle, line, i)) == -1)
			return (-1);
		if (buf[i] == '\n')
			break ;
	}
	return (retour(len, buf, save, i));
}
