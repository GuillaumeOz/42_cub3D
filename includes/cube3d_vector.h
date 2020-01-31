/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_vector.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:15:36 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/30 11:51:07 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_VECTOR_H
# define CUBE3D_VECTOR_H

typedef struct s_vector
{
	float	x;
	float	y;
}			t_vector;

t_vector	*malloc_vector(float x, float y);
t_vector	create_vector(float x, float y);
void		destroy_vector(t_vector to_destroy);
void		free_vector(t_vector *to_free);

#endif