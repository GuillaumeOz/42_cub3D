/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_ceiling_floor_texture_bonus.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:30:31 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 18:18:51 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_floor_texture_bonus(t_engine *engine, char *line)
{
	size_t	i;

	i = ft_strskip(line, ' ');
	if (line[i] == '\0')
		cub3d_error(ERROR_PARSING36, "The Floor texture path is missing");
	engine->floor_texture = malloc_texture(engine->app,
			line + i, FLOOR_BONUS);
	engine->bonus |= FLOOR_TEX_BONUS;
}

void	parse_ceiling_texture_bonus(t_engine *engine, char *line)
{
	size_t	i;

	i = ft_strskip(line, ' ');
	if (line[i] == '\0')
		cub3d_error(ERROR_PARSING37, "The Ceiling texture path is missing");
	engine->ceiling_texture = malloc_texture(engine->app,
			line + i, FLOOR_BONUS);
	engine->bonus |= CEILING_TEX_BONUS;
}
