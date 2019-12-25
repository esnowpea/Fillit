/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:12:16 by esnowpea          #+#    #+#             */
/*   Updated: 2019/11/05 16:12:18 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_node	*new_node(t_point p, char letter, size_t line, int figure)
{
	t_node	*node;

	if (!(node = (t_node*)malloc(sizeof(t_node))))
		return (0);
	node->up = node;
	node->down = node;
	node->left = node;
	node->right = node;
	node->col = node;
	node->next_f = node;
	node->line = line;
	node->letter = letter;
	node->name = p;
	node->figure = figure;
	return (node);
}

void	*clear_line(t_node *new[5])
{
	int	i;

	i = 0;
	while (i < 5 && new[i])
	{
		free(new[i]);
		new[i] = 0;
		i++;
	}
	return (0);
}

t_node	*del_next(t_node *r, t_node *next)
{
	t_node	*tmp;

	tmp = next;
	free(r);
	return (tmp);
}

void	*clear_knut(t_node *h)
{
	t_node	*c;
	t_node	*r;

	c = h->up;
	while (c != h)
	{
		r = c->right;
		while (r != c)
			r = del_next(r, r->right);
		c = del_next(c, c->up);
	}
	r = h->right;
	while (r != h)
		r = del_next(r, r->right);
	free(h);
	return (0);
}

void	counter(t_point *p, int k)
{
	(*p).x++;
	if ((*p).x == k)
	{
		(*p).x = 0;
		(*p).y++;
	}
}
