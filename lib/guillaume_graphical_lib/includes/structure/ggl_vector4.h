/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_vector4.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:11:56 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/19 15:30:46 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GGL_VECTOR4_H
# define GGL_VECTOR4_H

typedef struct	s_vector4
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_vector4;

t_vector4	*malloc_vector4(float x, float y, float z, float w);
t_vector4	create_vector4(float x, float y, float z, float w);
void		destroy_vector4(t_vector4 to_destroy);
void		free_vector4(t_vector4 *to_free);

#endif