/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_sprite_infos.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 15:17:54 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/16 15:18:17 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

#ifndef CUB3D_SPRITE_INFOS_H
# define CUB3D_SPRITE_INFOS_H

typedef struct	s_sprite_data
{
	t_image     act;
	t_sprites	sprite;
	float		x;
	float		y;
	int			column;
	float		percent;
	int			num;
	int			i;
	t_vector2	pos;
	t_color		color;
	t_color		dark;
}				t_sprite_data;

#endif