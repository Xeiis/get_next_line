/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 22:21:14 by dchristo          #+#    #+#             */
/*   Updated: 2016/01/12 22:21:20 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE2_H
# define GET_NEXT_LINE2_H

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

#endif
