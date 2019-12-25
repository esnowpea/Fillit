/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dancing_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:37:33 by esnowpea          #+#    #+#             */
/*   Updated: 2019/11/05 16:00:44 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	uncover_line(t_node *c)
{
	t_node	*r;

	c->up->down = c;
	c->down->up = c;
	r = c->right;
	while (r != c)
	{
		r->up->down = r;
		r->down->up = r;
		r = r->right;
	}
}

void	uncover_exc_line(t_node *c)
{
	t_node	*r;
	t_node	*j;

	uncover_line(c);
	r = c->next_f;
	while (r != c)
	{
		uncover_line(r);
		j = r;
		r = r->next_f;
		j->next_f = j;
	}
	c->next_f = c;
}

int		search(size_t k, t_node *h, t_node **o, size_t len)
{
	t_node	*c;
	int		flag;

	flag = 0;
	if (h != h->down)
	{
		c = h->down;
		while (c != h && !flag && c->letter == (char)(k + 'A'))
		{
			o[k] = c;
			if (k == 0)
				cover_exc_line(c, h);
			else
				cover_exc_line(c, o[k - 1]);
			flag = search(k + 1, h, o, len);
			uncover_exc_line(c);
			c = c->down;
		}
		return (flag);
	}
	else if (k < len)
		return (0);
	else
		return (1);
}

int		dancing_links(t_figure *list, int k, int len)
{
	t_node		*h;
	t_node		**o;

	if (!(h = filling(list, k)))
		return (-1);
	if (!(o = (t_node **)malloc(sizeof(t_node *) * (len + 1))))
	{
		clear_knut(h);
		return (-1);
	}
	o[len] = NULL;
	if (search(0, h, o, len))
	{
		uncover_exc_line(h);
		printing_map(o, k);
		clear_knut(h);
		free(o);
		return (1);
	}
	uncover_exc_line(h);
	clear_knut(h);
	free(o);
	return (0);
}
