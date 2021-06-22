/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_secret_door_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 11:32:37 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 17:15:36 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_secret_door_bonus(t_engine *engine, char *line)
{
	size_t	i;

	i = ft_strskip(line, ' ');
	if (line[i] == '\0')
		cub3d_error(ERROR_PARSING39,
			"The Secret Door texture path is missing");
	engine->secret_door = malloc_texture(engine->app,
			line + i, SECRET_DOOR_BONUS);
	engine->bonus |= SECRET_DOOR_TEX_BONUS;
	if (ft_isonlycharset(engine->allow_charset, "2") == false)
		set_allow_charset(engine, " 012NSEWabcdefghijk");
	else
		set_allow_charset(engine, " 01NSEWabcdefghijk");
}
