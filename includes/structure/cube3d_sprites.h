/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_sprites.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 19:55:20 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/14 20:17:23 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

#ifndef CUBE3D_SPRITES_H
# define CUBE3D_SPRITES_H

typedef struct		s_sprites
{
	t_ray				ray;
	t_vector2			pos;
	char				type;
	struct s_sprites	*next;
}					t_sprites;

t_sprites			create_sprites(t_ray ray, t_vector2 pos, char p_type);
t_sprites			*malloc_sprites(t_ray ray, t_vector2 pos, char p_type);
void				destroy_sprites(t_sprites sprites);
void				free_sprites(t_sprites *sprites);
void				clear_sprites(t_sprites **sprites);

#endif
