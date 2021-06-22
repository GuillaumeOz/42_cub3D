/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_double_id_checker_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 11:26:01 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 18:27:44 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	it_is_floor_texture_bonus(t_engine *engine, char *id)
{
	bool	ret;

	ret = ft_strcmp(id, "FT");
	if (ret == true)
		if (engine->floor_texture != NULL)
			cub3d_error(ERROR_PARSING34, "Several Floor Texture id detected");
	return (ret);
}

bool	it_is_ceiling_texture_bonus(t_engine *engine, char *id)
{
	bool	ret;

	ret = ft_strcmp(id, "CT");
	if (ret == true)
		if (engine->ceiling_texture != NULL)
			cub3d_error(ERROR_PARSING35, "Several Ceiling Texture id detected");
	return (ret);
}

bool	it_is_sprite_basic_bonus(t_engine *engine, char *id)
{
	bool	ret;

	ret = ft_strcmp(id, "S");
	if (ret == true)
		if (engine->sprite_basic != NULL)
			cub3d_error(ERROR_PARSING12, "Several Sprite id detected");
	return (ret);
}

bool	it_is_resolution_bonus(t_engine *engine, char *id)
{
	bool	ret;

	ret = ft_strcmp(id, "R");
	if (ret == true)
		if (engine->bonus & RESOLUTION_BONUS)
			cub3d_error(ERROR_PARSING7, "Several Resolution id detected");
	return (ret);
}

bool	it_is_secret_door_bonus(t_engine *engine, char *id)
{
	bool	ret;

	ret = ft_strcmp(id, "DO");
	if (ret == true)
		if (engine->bonus & SECRET_DOOR_TEX_BONUS)
			cub3d_error(ERROR_PARSING38, "Several Secret door id detected");
	return (ret);
}
