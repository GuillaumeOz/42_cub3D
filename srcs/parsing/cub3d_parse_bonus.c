/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:31:25 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 17:48:16 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_bonus(t_engine *engine, char *line, char *id, int i)
{
	if (it_is_resolution_bonus(engine, id) == true)
		parse_resolution_bonus(engine, line + 1 + i);
	else if (it_is_sprite_basic_bonus(engine, id) == true)
		parse_sprite_basic_bonus(engine, line + 1 + i);
	else if (it_is_floor_texture_bonus(engine, id) == true)
		parse_floor_texture_bonus(engine, line + 2 + i);
	else if (it_is_ceiling_texture_bonus(engine, id) == true)
		parse_ceiling_texture_bonus(engine, line + 2 + i);
	else if (it_is_secret_door_bonus(engine, id) == true)
		parse_secret_door_bonus(engine, line + 2 + i);
}
