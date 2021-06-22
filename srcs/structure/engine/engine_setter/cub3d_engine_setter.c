/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_engine_setter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:19:39 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 15:03:43 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_allow_charset(t_engine *engine, char *new_charset)
{
	if (engine->allow_charset == NULL)
	{
		engine->allow_charset = ft_strdup(new_charset);
		if (engine->allow_charset == NULL)
			cub3d_error(ERROR_ENGINE4, "char* cannot be malloc");
	}
	else
	{
		free(engine->allow_charset);
		engine->allow_charset = ft_strdup(new_charset);
		if (engine->allow_charset == NULL)
			cub3d_error(ERROR_ENGINE4, "char* cannot be malloc");
	}
}

void	set_engine_wall_limit(t_engine *engine)
{
	if (engine->wall_limit == NULL)
	{
		engine->wall_limit = (double *)malloc(sizeof(double)
				* engine->resolution.x);
		if (engine->wall_limit == NULL)
			cub3d_error(ERROR_ENGINE3, "double* cannot be malloc");
	}
	else
	{
		free(engine->wall_limit);
		engine->wall_limit = (double *)malloc(sizeof(double)
				* engine->resolution.x);
		if (engine->wall_limit == NULL)
			cub3d_error(ERROR_ENGINE3, "double* cannot be malloc");
	}
}

void	set_engine_texture(t_engine *engine)
{
	engine->texture = (t_texture **)malloc(sizeof(t_texture *) * 4);
	if (engine->texture == NULL)
		cub3d_error(ERROR_ENGINE2, "t_texture** can't be malloc");
}
