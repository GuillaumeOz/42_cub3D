/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:46:29 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 15:38:56 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GGL_LIST_H
# define GGL_LIST_H

typedef struct	s_list
{
	void		***content;
	size_t		size;
	size_t		max_size;
	size_t		nb_line;
	size_t		push_size;
}				t_list;

typedef void	(*t_destroy_funct)(void *to_destroy);

t_list			create_list(size_t p_push_size);
t_list			*malloc_list(size_t p_push_size);
void			destroy_list(t_list to_destroy, t_destroy_funct funct);
void			free_list(t_list *to_free, t_destroy_funct funct);

t_vector2		list_calc_index_coord(t_list *list, size_t index);
void			list_push_back(t_list *list, void *to_add);
void			*list_at(t_list *list, size_t index);
void			**list_get(t_list *list, size_t index);
void			clear_list(t_list *to_clear, destroy_funct funct);

#endif
