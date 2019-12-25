/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:28:17 by ablane            #+#    #+#             */
/*   Updated: 2019/10/29 14:57:04 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_true_tetr(char sqr[4][4], char c)
{
	int	i;
	int	j;
	int tetr;

	i = 0;
	tetr = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (sqr[i][j] == c)
			{
				if ((j + 1) < 4 && sqr[i][j + 1] == c)
					tetr++;
				if ((i + 1) < 4 && sqr[i + 1][j] == c)
					tetr++;
			}
			j++;
		}
		i++;
	}
	if (tetr == 3 || tetr == 4)
		return (1);
	return (0);
}

int			check_figure(char sqr[4][4], char alph)
{
	int i;
	int j;
	int point;

	i = 0;
	point = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (sqr[i][j] == '#')
			{
				sqr[i][j] = alph;
				point++;
			}
			if (sqr[i][j] != '.' && sqr[i][j] != alph)
				return (0);
			j++;
		}
		i++;
	}
	if (point != 4 || !ft_true_tetr(sqr, alph))
		return (0);
	return (1);
}

int			num_figure_two(t_point dot[4])
{
	if (dot[2].x == 0 && dot[2].y == 1 && dot[3].x == 0 && dot[3].y == 2)
		return (10);
	if (dot[2].x == 1 && dot[2].y == 1 && dot[3].x == 0 && dot[3].y == 2)
		return (18);
	if (dot[2].x == 0 && dot[2].y == 1 && dot[3].x == 1 && dot[3].y == 1 &&
		dot[1].x == 1 && dot[1].y == 0)
		return (1);
	if (dot[1].x == 0 && dot[1].y == 1 && dot[3].x == 2 && dot[3].y == 1)
		return (9);
	if (dot[1].x == 0 && dot[1].y == 1 && dot[2].x == 1 && dot[2].y == 1 &&
		dot[3].x == 1 && dot[3].y == 2)
		return (13);
	if (dot[1].x == 1 && dot[1].y == 0 && dot[2].x == 1 && dot[2].y == 1 &&
		dot[3].x == 1 && dot[3].y == 2)
		return (6);
	if (dot[1].x == 1 && dot[1].y == 0 && dot[2].x == 1 && dot[2].y == 1 &&
		dot[3].x == 2 && dot[3].y == 1)
		return (14);
	return (0);
}

int			num_figure(t_point dot[4])
{
	if (dot[1].x == -2 && dot[1].y == 1)
		return (7);
	if (dot[2].x == -1 && dot[2].y == 2)
		return (8);
	if (dot[3].x == -1 && dot[3].y == 2)
		return (15);
	if (dot[3].x == 0 && dot[3].y == 3)
		return (3);
	if (dot[3].x == 3 && dot[3].y == 0)
		return (2);
	if (dot[2].x == 0 && dot[2].y == 2 && dot[3].x == 1 && dot[3].y == 2)
		return (4);
	if (dot[2].x == -1 && dot[2].y == 1 && dot[1].x == 1 && dot[1].y == 0)
		return (12);
	if (dot[1].x == -1 && dot[1].y == 1 && dot[3].x == 1 && dot[3].y == 1)
		return (17);
	if (dot[1].x == -1 && dot[1].y == 1 && dot[3].x == 0 && dot[3].y == 2)
		return (19);
	if (dot[2].x == 2 && dot[2].y == 0 && dot[3].x == 0 && dot[3].y == 1)
		return (5);
	if (dot[2].x == 2 && dot[2].y == 0 && dot[3].x == 2 && dot[3].y == 1)
		return (11);
	if (dot[2].x == 2 && dot[2].y == 0 && dot[3].x == 1 && dot[3].y == 1)
		return (16);
	return (num_figure_two(dot));
}
