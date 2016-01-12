/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 20:48:54 by dchristo          #+#    #+#             */
/*   Updated: 2016/01/11 21:58:49 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int				write_in_line(t_list **list, char **line,
		t_list_save **lst_save, i)
{
	// ecrire dans line;
	// en remontant avec prev;
}

static int				read_fd(int fd, t_list **list,
		t_list_save **list_save, char **line)
{
	int i;
	t_list *lst;
	t_list_save **lst_save;

	lst = *list;
	lst_save = *list_save;
	while ((i = read(fd, lst->buf, BUFF_SIZE)) > 0)
	{
		lst->buf[i] = '\0';
		i = 0;
		while (lst->buf[i] != '\n' || lst->buf[i] != '\0')
			i++;
		if (lst->buf[--i] == '\n')
		{
			write_in_line(&lst, line, &lst_save, i); 
			break ;
		}
		if ((!lst->next = (t_list *)malloc(sizeof(t_list))))
			return (-1);
		lst->next->prev = lst;
		lst = lst->next;
	}
}

static t_list_save		find_fd_in_list(t_list_save **list_save, int fd)
{
	t_list				*lst_save;

	lst_save = *list_save;
	if (!lst_save)
		if ((!lst_save = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
	else
	{
		while (lst_save->fd != fd || lst_save == NULL)
			lst_save = lst_save->next;
		if (lst_save->fd != fd)
			if ((!lst_save->next = (t_list *)malloc(sizeof(t_list))))
				return (NULL);
		else
			return (lst_save);
		lst_save = lst_save->next;
	}
	lst_save->fd = fd;
	lst_save->next = NULL;
	return (list_save);
}

int						get_next_line(int const fd, char **line)
{
	t_list				*list;
	static t_list_save	*list_save;
	int					i;

	if ((!list = (t_list *)malloc(sizeof(t_list))))
		return (-1);
	find_fd_in_list(&list_save, fd);
	read_fd(fd, &list, &list_save, line);
	return ();
}
