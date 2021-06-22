/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_sprite_basic_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:05:08 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/14 17:00:14 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_sprite_basic_bonus(t_engine *engine, char *line)
{
	size_t			i;

	i = ft_strskip(line, ' ');
	if (line[i] == '\0')
		cub3d_error(ERROR_PARSING18, "The sprite path is missing");
	engine->sprite_basic = malloc_sprite(engine->app, line + i, BASIC);
	engine->bonus |= SPRITE_BONUS;
	if (ft_isnotonlycharset(engine->allow_charset, "abcdefghijk") == false)
		set_allow_charset(engine, " 012NSEWabcdefghijk");
	else
		set_allow_charset(engine, " 012NSEW");
}
