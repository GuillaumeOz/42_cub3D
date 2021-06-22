/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_t_color.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:29:48 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/17 18:09:37 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_T_COLOR_H
# define CUB3D_T_COLOR_H

typedef uint8_t		t_uint8;
typedef uint16_t	t_uint16;
typedef uint32_t	t_uint32;

typedef struct s_color
{
	t_uint8				r;
	t_uint8				g;
	t_uint8				b;
	t_uint8				a;
}						t_color;

t_color					*malloc_color(t_uint8 p_r, t_uint8 p_g,
							t_uint8 p_b, t_uint8 p_a);
t_color					create_color(t_uint8 p_r, t_uint8 p_g,
							t_uint8 p_b, t_uint8 p_a);
void					destroy_color(t_color to_destroy);
void					free_color(t_color *to_free);

t_color					int_to_color(int to_convert);

#endif