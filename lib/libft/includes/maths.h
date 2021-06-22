/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:02:22 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/18 12:19:48 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

typedef struct s_float_vector2
{
	float	x;
	float	y;
}				t_float_vector2;

typedef struct s_double_vector2
{
	double	x;
	double	y;
}				t_double_vector2;

typedef struct s_int_vector2
{
	int	x;
	int	y;
}				t_int_vector2;

t_float_vector2		*malloc_float_vector2(float x, float y);
t_float_vector2		create_float_vector2(float x, float y);
void				destroy_float_vector2(t_float_vector2 to_destroy);
void				free_float_vector2(t_float_vector2 *to_free);

t_double_vector2	*malloc_double_vector2(double x, double y);
t_double_vector2	create_double_vector2(double x, double y);
void				destroy_double_vector2(t_double_vector2 to_destroy);
void				free_double_vector2(t_double_vector2 *to_free);

t_int_vector2		*malloc_int_vector2(int x, int y);
t_int_vector2		create_int_vector2(int x, int y);
void				destroy_int_vector2(t_int_vector2 to_destroy);
void				free_int_vector2(t_int_vector2 *to_free);

#endif