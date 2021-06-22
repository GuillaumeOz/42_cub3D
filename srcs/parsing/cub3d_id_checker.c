/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_id_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:14:14 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 19:16:26 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	texture_is_null(t_engine *engine, t_texture_id dir)
{
	if (engine->texture[dir] != NULL)
	{
		if (dir == NORTH)
			cub3d_error(ERROR_PARSING8, "Several NO texture id detected");
		if (dir == SOUTH)
			cub3d_error(ERROR_PARSING9, "Several SO texture id detected");
		if (dir == WEST)
			cub3d_error(ERROR_PARSING10, "Several WE texture id detected");
		if (dir == EAST)
			cub3d_error(ERROR_PARSING11, "Several EA texture id detected");
	}
}

bool	it_is_texture(t_engine *engine, char *id, t_texture_id *direction)
{
	if (ft_strcmp(id, "NO") == true)
	{
		texture_is_null(engine, NORTH);
		*direction = NORTH;
		return (true);
	}
	else if (ft_strcmp(id, "SO") == true)
	{
		texture_is_null(engine, SOUTH);
		*direction = SOUTH;
		return (true);
	}
	else if (ft_strcmp(id, "WE") == true)
	{
		texture_is_null(engine, WEST);
		*direction = WEST;
		return (true);
	}
	else if (ft_strcmp(id, "EA") == true)
	{
		texture_is_null(engine, EAST);
		*direction = EAST;
		return (true);
	}
	return (false);
}

bool	it_is_color(t_engine *engine, char *id)
{
	if (ft_strcmp(id, "F") == true)
	{
		if (engine->floor != NULL)
			cub3d_error(ERROR_PARSING13, "Several Floor color id detected");
		return (true);
	}
	else if (ft_strcmp(id, "C") == true)
	{
		if (engine->ceiling != NULL)
			cub3d_error(ERROR_PARSING14, "Several Ceiling color id detected");
		return (true);
	}
	return (false);
}
