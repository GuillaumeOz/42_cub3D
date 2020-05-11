/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_vector2_list_creators.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 10:54:31 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 14:36:46 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GGL_VECTOR2_LIST_CREATORS_H
# define GGL_VECTOR2_LIST_CREATORS_H

typedef struct	s_vector2_list
{
	t_vector2	**data;
	size_t		size;
	size_t		max_size;
	size_t		push_size;
}				t_vector2_list;

t_vector2		**t_vector2tab_new(size_t nb);
t_vector2		*t_vector2array_new(size_t nb);
t_vector2_list	create_t_vector2_list(size_t p_push_size);
t_vector2_list	*malloc_t_vector2_list(size_t p_push_size);

#endif
