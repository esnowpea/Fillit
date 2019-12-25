/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cover_knut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:11:57 by esnowpea          #+#    #+#             */
/*   Updated: 2019/11/05 16:12:02 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	cover_line(t_node *c)
{
	t_node	*r;

	c->up->down = c->down;
	c->down->up = c->up;
	r = c->right;
	while (r != c)
	{
		r->up->down = r->down;
		r->down->up = r->up;
		r = r->right;
	}
}

void	cover_ident_figure(t_node *c, t_node *h)
{
	t_node	*k;
	t_node	*r;
	t_node	*j;

	k = h;
	while (k->next_f != h)
		k = k->next_f;
	r = c->right;
	while (r != c)
	{
		j = r->down;
		while (j != r)
		{
			if (j->letter != '@' && j->col->figure == c->figure &&
				r == c->right && j->left == j->col)
			{
				cover_line(j->col);
				k->next_f = j->col;
				k = k->next_f;
			}
			j = j->down;
		}
		r = r->right;
	}
	k->next_f = h;
}

void	cover_cros_line(t_node *c)
{
	t_node	*r;
	t_node	*j;
	t_node	*l;

	l = c;
	while (l->next_f != c)
		l = l->next_f;
	r = c->right;
	while (r != c)
	{
		j = r->down;
		while (j != r)
		{
			if (j->letter != '@')
			{
				cover_line(j->col);
				l->next_f = j->col;
				l = l->next_f;
			}
			j = j->down;
		}
		r = r->right;
	}
	l->next_f = c;
}

void	cover_letter(t_node *c)
{
	t_node	*r;
	t_node	*l;

	l = c;
	while (l->next_f != c)
		l = l->next_f;
	r = c->down;
	while (r != c)
	{
		if (c->letter == r->letter)
		{
			cover_line(r);
			l->next_f = r;
			l = l->next_f;
		}
		r = r->down;
	}
	l->next_f = c;
}

void	cover_exc_line(t_node *c, t_node *h)
{
	cover_ident_figure(c, h);
	cover_cros_line(c);
	cover_letter(c);
	cover_line(c);
}
