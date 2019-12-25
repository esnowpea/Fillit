/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:11:09 by esnowpea          #+#    #+#             */
/*   Updated: 2019/11/06 15:56:18 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#define USAGE "usage: ./fillit target_file\n"

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		else
			i++;
	}
	return (i);
}

int		count_figure(t_figure *list)
{
	t_figure	*tmp;
	int			i;

	i = 0;
	tmp = list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		error(char *str, t_figure *list)
{
	size_t	i;

	list_clean(&list);
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (0);
}

int		main(int ac, char **av)
{
	t_figure	*list;
	int			fd;
	int			len;
	int			i;

	list = 0;
	if (ac != 2)
		return (error(USAGE, list));
	fd = open(av[1], O_RDONLY);
	list = read_file(fd);
	if (!list || (close(fd) == -1))
		return (error("error\n", list));
	len = count_figure(list);
	i = ft_sqrt(len * 4);
	while ((fd = dancing_links(list, i, len)) != 1)
	{
		if (fd == -1)
			return (error("error\n", list));
		i++;
	}
	list_clean(&list);
	return (0);
}
