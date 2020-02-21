/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:26:53 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/21 17:44:39 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "libft.h"
# include "ggl.h"
# include "cube3d_catch_error.h"
# include "cube3d_tile.h"
# include "cube3d_actor.h"
# include "cube3d_game_engine.h"
# include "cube3d_map.h"
# include "cube3d_parsing.h"

t_application *g_app;

enum	e_cube3d_error
{
	ERROR_NOT_FOUND = -1,
	MAIN_1,
	CREATE_GAME_ENGINE_1,
	CREATE_GAME_ENGINE_2,
	CREATE_TILE_1,
	CREATE_TILE_2,
	SET_COLOR_TYPE_1,
	SET_COLOR_TYPE_2,
	SET_COLOR_TYPE_3,
	PARSE_GAME_ENGINE_1,
	PARSE_RESOLUTION_1,
	PARSE_RESOLUTION_2,
	MALLOC_MAP_1,
	PARSE_MAP_1,
	PARSE_MAP_2,
	MALLOC_TILE_TAB_1,
	MALLOC_TILE_TAB_2,
	CREATE_MAP_1,


	CHECK_MAPNAME_1,//here
	CUBE_FORMATTER_1,
	CUBE_FORMATTER_2,
	PARSE_TEXTURE_1,
	PARSE_OLD_RESOLUTION_1,
	PARSE_ENVIRONMENT_1,
	CUBE_MAP_FORMATTER_1,
	CUBE_MAP_FORMATTER_2,
	CUBE_MAP_FORMATTER_3,
	CUBE_MAP_REALLOC_1,
	CUBE_MAP_REALLOC_2,
	CUBE_MAP_PARSE_1,
	CUBE_MAP_PARSE_2,
	CUBE_MAP_PARSE_3,
	CUBE_MAP_PARSE_4,
	FILL_PLAYER_1,
	CHECK_BORDER_PLAYER_1,
	CHECK_BORDER_PLAYER_2
};

# define debug write(1, "ICI\n", 5)
# define PRINTS(x) printf("%s\n", x)
# define PRINTC(x) printf("%c\n", x)
# define PRINTD(x) printf("%d\n", x)
# define PRINTP(x) printf("%p\n", x)
# define PRINTF(x) printf("%f\n", x)
# define PRINTV(x) ft_printf("%v\n", x)
# define PRINTPOS printf("%s line %d\n", __func__, __LINE__)

# endif
