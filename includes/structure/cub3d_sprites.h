/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprites.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 19:55:20 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/08 16:48:53 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_SPRITES_H
# define CUB3D_SPRITES_H

typedef struct			s_sprites
{
	t_ray				ray;
	t_vector2			pos;
	t_tile_type			type;
	struct s_sprites	*next;
}						t_sprites;

typedef struct			s_sprite_data
{
	t_texture			act;
	t_sprites			sprite;
	float				x;
	float				y;
	int					column;
	float				percent;
	int					num;
	int					i;
	t_vector2			pos;
	t_color				color;
	t_color				dark;
}						t_sprite_data;

t_sprites				create_sprites(t_ray ray, t_vector2 pos,
							t_tile_type p_type);
t_sprites				*malloc_sprites(t_ray ray, t_vector2 pos,
							t_tile_type p_type);
void					destroy_sprites(t_sprites sprites);
void					free_sprites(t_sprites *sprites);
void					clear_sprites(t_sprites **sprites);

#endif
