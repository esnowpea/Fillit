/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:49:20 by esnowpea          #+#    #+#             */
/*   Updated: 2019/11/05 16:04:14 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

typedef struct		s_read_file
{
	ssize_t			first;
	ssize_t			last;
	ssize_t			total_counter;
}					t_read_file;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_node
{
	t_point			name;
	size_t			line;
	char			letter;
	int				figure;
	struct s_node	*next_f;
	struct s_node	*right;
	struct s_node	*left;
	struct s_node	*up;
	struct s_node	*down;
	struct s_node	*col;
}					t_node;

typedef struct		s_figure
{
	t_point			point[4];
	char			sym;
	int				num;
	struct s_figure	*next;
}					t_figure;

t_node				*filling(t_figure *list, int k);
int					dancing_links(t_figure *list, int k, int len);
void				*list_clean(t_figure **alst);
t_figure			*read_file(int fd);
t_figure			*list_back(t_figure *list, char sqr[4][4], char alph);
int					check_figure(char sqr[4][4], char alph);
void				printing_map(t_node **o, int k);
int					num_figure(t_point dot[4]);
void				*clear_knut(t_node *h);
void				cover_exc_line(t_node *c, t_node *h);
t_node				*new_node(t_point p, char letter, size_t line, int figure);
void				*clear_line(t_node *new[5]);
void				counter(t_point *p, int k);

#endif
