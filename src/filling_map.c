/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:28:56 by esnowpea          #+#    #+#             */
/*   Updated: 2019/11/05 15:53:07 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_node	*head_node(int k)
{
	t_node	*h;
	t_node	*c;
	t_point	name;
	int		i;

	name.x = -1;
	name.y = 0;
	if (!(h = new_node(name, '@', 0, 0)))
		return (0);
	c = h;
	i = 0;
	name.x = 0;
	while (i < k * k)
	{
		if (!(c = new_node(name, '@', 0, 0)))
			return (clear_knut(h));
		c->right = h;
		h->left->right = c;
		c->left = h->left;
		h->left = c;
		i++;
		counter(&name, k);
	}
	return (h);
}

void	in_list(t_node *h, t_node *new[5])
{
	t_node	*c;
	int		i;

	c = h->right;
	new[0]->down = h;
	h->up->down = new[0];
	new[0]->up = h->up;
	h->up = new[0];
	new[0]->col = h;
	i = 1;
	while (c != h)
	{
		if (i < 5 && c->name.x == new[i]->name.x && c->name.y == new[i]->name.y)
		{
			new[i]->down = c;
			c->up->down = new[i];
			new[i]->up = c->up;
			c->up = new[i];
			new[i]->col = new[0];
			i++;
		}
		c = c->right;
	}
}

t_node	*add_figure(t_node *h, t_figure *list, t_point p, int line)
{
	t_node	*new[5];
	int		i;
	t_point	pi;

	pi.x = -1;
	pi.y = 0;
	if (!(new[0] = new_node(pi, list->sym, line, list->num)))
		return (clear_line(new));
	i = 1;
	while (i < 5)
	{
		pi.x = list->point[i - 1].x + p.x;
		pi.y = list->point[i - 1].y + p.y;
		if (!(new[i] = new_node(pi, list->sym, line, list->num)))
			return (clear_line(new));
		new[i]->right = new[0];
		new[0]->left->right = new[i];
		new[i]->left = new[0]->left;
		new[0]->left = new[i];
		i++;
	}
	in_list(h, new);
	return (h);
}

t_node	*col_node(t_figure *list, t_node *h, int k)
{
	t_point	p;
	int		line;

	line = 1;
	while (list)
	{
		p.y = 0;
		p.x = 0;
		while ((p.x + p.y * k) < (k * k - 1))
		{
			if ((list->point[1].x + p.x) < k &&
				(list->point[1].x + p.x) >= 0 && (list->point[1].y + p.y) < k &&
				(list->point[2].x + p.x) < k && (list->point[2].x + p.x) >= 0 &&
				(list->point[2].y + p.y) < k && (list->point[3].x + p.x) < k &&
				(list->point[3].x + p.x) >= 0 && (list->point[3].y + p.y) < k)
				if (!(add_figure(h, list, p, line++)))
					return (clear_knut(h));
			counter(&p, k);
		}
		list = list->next;
	}
	return (h);
}

t_node	*filling(t_figure *list, int k)
{
	t_node	*h;

	if (!(h = head_node(k)))
		return (0);
	if (!col_node(list, h, k))
		return (0);
	return (h);
}
