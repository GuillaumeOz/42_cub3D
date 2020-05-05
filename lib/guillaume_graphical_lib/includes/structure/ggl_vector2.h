/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_vector2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:15:36 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 14:36:40 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GGL_VECTOR2_H
# define GGL_VECTOR2_H

typedef struct	s_vector2
{
	float		x;
	float		y;
}				t_vector2;

t_vector2		*malloc_vector2(float x, float y);
t_vector2		create_vector2(float x, float y);
void			destroy_vector2(t_vector2 to_destroy);
void			free_vector2(t_vector2 *to_free);

t_vector2		add_vector2_to_vector2(t_vector2 a, t_vector2 b);
t_vector2		substract_vector2_to_vector2(t_vector2 a, t_vector2 b);
t_vector2		mult_vector2_by_vector2(t_vector2 a, t_vector2 b);
t_vector2		divide_vector2_by_vector2(t_vector2 a, t_vector2 b);
float			vector2_distance(t_vector2 p_a, t_vector2 p_b);

#endif
