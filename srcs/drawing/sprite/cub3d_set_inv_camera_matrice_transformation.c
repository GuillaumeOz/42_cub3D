/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_set_inv_camera_matrice_transformation        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:49:53 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 17:32:36 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_inv_camera_matrice_transformation(t_sprite_calc *sprite_calc,
			t_player *player)
{
	double	identity_matrix_x;
	double	identity_matrix_y;
	double	inv_factor;

	inv_factor = 1.0 / (player->dir.y * player->plane.x - player->dir.x
			* player->plane.y);
	identity_matrix_x = (player->dir.y * sprite_calc->sprite_pos.x
			- player->dir.x * sprite_calc->sprite_pos.y);
	identity_matrix_y = (sprite_calc->sprite_pos.x * (-player->plane.y)
			+ sprite_calc->sprite_pos.y * player->plane.x);
	sprite_calc->inv_transform.x = inv_factor * (-identity_matrix_x);
	sprite_calc->inv_transform.y = inv_factor * identity_matrix_y;
}
