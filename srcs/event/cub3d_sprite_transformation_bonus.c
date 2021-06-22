/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprite_transformation_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:28:20 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 20:09:14 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_transformation_remover(int key, t_player *player)
{
	if (key == U_KEY)
		player->control = (player->control ^ U_CTRL) ^ TRANSFORM_MARKER;
	if (key == J_KEY)
		player->control = (player->control ^ J_CTRL) ^ TRANSFORM_MARKER;
	if (key == I_KEY)
		player->control = (player->control ^ I_CTRL) ^ TRANSFORM_MARKER;
	if (key == K_KEY)
		player->control = (player->control ^ K_CTRL) ^ TRANSFORM_MARKER;
	if (key == O_KEY)
		player->control = (player->control ^ O_CTRL) ^ TRANSFORM_MARKER;
	if (key == L_KEY)
		player->control = (player->control ^ L_CTRL) ^ TRANSFORM_MARKER;
}

void	sprite_z_transformation(int key, t_player *player)
{
	if (key == U_KEY)
		player->control = (player->control | U_CTRL) | TRANSFORM_MARKER;
	if (key == J_KEY)
		player->control = (player->control | J_CTRL) | TRANSFORM_MARKER;
}

void	sprite_width_transformation(int key, t_player *player)
{
	if (key == I_KEY)
		player->control = (player->control | I_CTRL) | TRANSFORM_MARKER;
	if (key == K_KEY)
		player->control = (player->control | K_CTRL) | TRANSFORM_MARKER;
}

void	sprite_height_transformation(int key, t_player *player)
{
	if (key == O_KEY)
		player->control = (player->control | O_CTRL) | TRANSFORM_MARKER;
	if (key == L_KEY)
		player->control = (player->control | L_CTRL) | TRANSFORM_MARKER;
}

void	sprite_transformation_loader(int key, t_player *player)
{
	if (key == U_KEY || key == J_KEY)
		sprite_z_transformation(key, player);
	if (key == I_KEY || key == K_KEY)
		sprite_width_transformation(key, player);
	if (key == O_KEY || key == L_KEY)
		sprite_height_transformation(key, player);
}
