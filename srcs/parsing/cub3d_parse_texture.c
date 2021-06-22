/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:03:14 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 19:14:48 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_texture(t_engine *engine, char *line, t_texture_id direction)
{
	size_t	i;

	i = ft_strskip(line, ' ');
	if (line[i] == '\0')
		cub3d_error(ERROR_PARSING17, "A texture path is missing");
	engine->texture[direction] = malloc_texture(engine->app,
			line + i, direction);
}
