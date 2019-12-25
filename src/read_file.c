/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:30:26 by ablane            #+#    #+#             */
/*   Updated: 2019/11/05 15:33:17 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		buf_to_sqr(char sqr[4][4], char buf[21])
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_strncpy(sqr[i], &buf[i * 5], 4);
		i++;
	}
}

t_figure	*read_file(int fd)
{
	char		buf[20];
	char		sqr[4][4];
	t_figure	*list;
	t_read_file	result;
	char		alph;

	alph = 'A';
	list = NULL;
	result.last = 1;
	result.total_counter = 0;
	while ((result.first = read(fd, buf, 20)) > 0)
	{
		if ((result.total_counter++ > 26) || (result.first != 20))
			return (list_clean(&list));
		buf_to_sqr(sqr, buf);
		if (!(check_figure(sqr, alph)))
			return (list_clean(&list));
		if (!(list = list_back(list, sqr, alph++)))
			return (list_clean(&list));
		result.first = read(fd, buf, 1);
		if (result.last == 1 && result.first == 0)
			return (list);
		result.last = result.first;
	}
	return (list_clean(&list));
}
