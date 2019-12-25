/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:32:15 by ablane            #+#    #+#             */
/*   Updated: 2019/10/29 12:11:03 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		*list_clean(t_figure **alst)
{
	t_figure	*tmp;

	if (!alst || !*alst)
		return (NULL);
	while (*alst)
	{
		tmp = (*alst)->next;
		free(*alst);
		*alst = tmp;
	}
	*alst = NULL;
	return (NULL);
}

void		dot_fill(t_point *dot, int i, int j)
{
	(*dot).x = j;
	(*dot).y = i;
}

void		sqr_to_dot(char sqr[4][4], t_point dot[4])
{
	int	i;
	int	j;
	int k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (sqr[i][j] != '.')
				dot_fill(&dot[k++], i, j);
			j++;
		}
		i++;
	}
	k = 3;
	while (k >= 0)
	{
		dot_fill(&dot[k], dot[k].y - dot[0].y, dot[k].x - dot[0].x);
		k--;
	}
}

t_figure	*list_new(t_point dot[4], char alph)
{
	t_figure *new;

	new = (t_figure *)malloc(sizeof(t_figure));
	if (!new)
		return (0);
	new->point[0] = dot[0];
	new->point[1] = dot[1];
	new->point[2] = dot[2];
	new->point[3] = dot[3];
	new->sym = alph;
	new->num = num_figure(dot);
	new->next = NULL;
	return (new);
}

t_figure	*list_back(t_figure *list, char sqr[4][4], char alph)
{
	t_figure	*new;
	t_point		dot[4];
	t_figure	*begin;

	sqr_to_dot(sqr, dot);
	new = list_new(dot, alph);
	if (!new)
	{
		list_clean(&list);
		return (0);
	}
	if (list == NULL)
		return (new);
	begin = list;
	while (list->next)
		list = list->next;
	list->next = new;
	return (begin);
}
