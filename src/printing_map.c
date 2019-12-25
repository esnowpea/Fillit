/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:24:26 by esnowpea          #+#    #+#             */
/*   Updated: 2019/10/31 19:24:00 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_map(char **mas)
{
	int		i;

	i = 0;
	while (mas[i])
	{
		free(mas[i]);
		mas[i] = 0;
		i++;
	}
	free(mas);
}

void	zapoln(t_node **o, char **mas)
{
	int		i;
	t_node	*r;

	i = 0;
	while (o[i])
	{
		r = o[i]->right;
		while (r != o[i])
		{
			mas[r->name.y][r->name.x] = r->letter;
			r = r->right;
		}
		i++;
	}
	i = 0;
	while (mas[i])
	{
		ft_putstr(mas[i]);
		ft_putchar('\n');
		i++;
	}
}

void	printing_map(t_node **o, int k)
{
	char	**mas;
	int		i;

	if (!(mas = (char**)malloc(sizeof(char*) * (k + 1))))
	{
		write(1, "error\n", 6);
		return ;
	}
	i = 0;
	while (i < k)
	{
		if (!(mas[i] = ft_memset(ft_strnew(k), '.', k)))
		{
			free_map(mas);
			write(1, "error\n", 6);
			return ;
		}
		i++;
	}
	mas[k] = NULL;
	zapoln(o, mas);
	free_map(mas);
}
