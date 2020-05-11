/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_catch_error.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:09:39 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/09 20:17:20 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CATCH_ERROR_H
# define CUB3D_CATCH_ERROR_H

typedef struct	s_error
{
	int			error_list;
	char		*warning_msg;
}				t_error;

enum	e_cube3d_error
{
	ERROR_NOT_FOUND = -1,
	MAIN_1,
	CHECK_SAVE_1,
	DO_SAVE_1,
	MALLOC_PARAM_TAB_1,
	CUB3D_PARSING_1,
	CUB3D_PARSING_2,
	MALLOC_GAME_ENGINE_1,
	ENGINE_TEXTURE_SET_1,
	CREATE_TILE_1,
	CREATE_TILE_2,
	CHECK_MAPNAME_1,
	SET_COLOR_TYPE_1,
	SET_COLOR_TYPE_2,
	SET_COLOR_TYPE_3,
	PARSE_GAME_ENGINE_1,
	SET_TEXTURE_IMAGE_1,
	SET_TEXTURE_IMAGE_2,
	SET_SPRITE_IMAGE_1,
	SET_SPRITE_IMAGE_2,
	SET_DOOR_IMAGE_1,
	SET_DOOR_IMAGE_2,
	SET_LEVEL_IMAGE_1,
	SET_LEVEL_IMAGE_2,
	SET_MEDIKIT_IMAGE_1,
	SET_MEDIKIT_IMAGE_2,
	SET_MONSTER_IMAGE_1,
	SET_MONSTER_IMAGE_2,
	PARSE_RESOLUTION_1,
	PARSE_RESOLUTION_2,
	PARSE_RESOLUTION_3,
	PARSE_ENVIRONEMENT_COLOR_1,
	PARSE_ENVIRONEMENT_COLOR_2,
	COLOR_CHECKER_1,
	MALLOC_MAP_1,
	PARSE_MAP_1,
	PARSE_MAP_2,
	MALLOC_PLAYER_1,
	FLOOD_FILL_1,
	FLOOD_FILL_2,
	MALLOC_TILE_TAB_1,
	MALLOC_TILE_TAB_2,
	CREATE_MAP_2,
	MALLOC_RAY_1,
	MALLOC_SPRITES_1,
	MALLOC_TEXTURE_1,
	CREATE_TEXTURE_1,
	SET_THREAD_OPTION_1,
};

void			catch_error(int error_msg);

#endif
