/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:11:42 by dchristo          #+#    #+#             */
/*   Updated: 2016/01/11 21:50:01 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 50
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_list
{
	char			buf[BUFF_SIZE];
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct		s_list_save
{
	char			save[BUFF_SIZE];
	int				fd;
	struct s_list	*next;
}					t_list_save;
int		get_next_line(int const fd, char **line);

#endif
