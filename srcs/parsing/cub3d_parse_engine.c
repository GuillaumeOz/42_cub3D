/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_engine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:44:07 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/21 15:45:12 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_engine_is_full(t_engine *engine)
{
	if (engine->texture[NORTH] == NULL
		|| engine->texture[SOUTH] == NULL
		|| engine->texture[EAST] == NULL
		|| engine->texture[WEST] == NULL
		|| engine->floor == NULL
		|| engine->ceiling == NULL)
		return (false);
	return (true);
}

static void	parse_main_parameters(t_engine *engine,
	char *line, char *id, int i)
{
	t_texture_id	direction;

	if (ft_strlen(line) == 0)
		;
	else if (it_is_texture(engine, id, &direction) == true)
		parse_texture(engine, line + 2 + i, direction);
	else if (it_is_color(engine, id) == true)
		parse_color(engine, line + 1 + i, id);
	else if (it_is_bonus(id) == true)
		parse_bonus(engine, line, id, i);
	else
		cub3d_error(ERROR_PARSING6, "The information part is incorrect");
	free(id);
	free(line);
}

void	parse_engine(t_engine *engine, int fd)
{
	size_t	i;
	char	*id;
	char	*line;
	int		ret;

	while (is_engine_is_full(engine) == false)
	{
		ret = get_next_line(fd, &line);
		i = ft_strskip(line, ' ');
		id = ft_strcut(&line, ' ');
		parse_main_parameters(engine, line, id, i);
		if (is_engine_is_full(engine) == false && ret == 0)
			cub3d_error(ERROR_PARSING26, "Basic informations are missing");
	}
}
