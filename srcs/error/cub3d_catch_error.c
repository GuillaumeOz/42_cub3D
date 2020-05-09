/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_catch_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:06:53 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/09 22:10:05 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_error	g_cube3d_catch_error[] =
{
	{ MAIN_1, "Error\nWrong number of arguments" },
	{ CHECK_SAVE_1, "Error\nSecond argument is wrong" },
	{ DO_SAVE_1, "Error\nError while saving the image"},
	{ MALLOC_PARAM_TAB_1, "Error\nCan't malloc a void** parameter tab"},
	{ CUB3D_PARSING_1, "Error\nThe File Descriptor is incorrect"},
	{ CUB3D_PARSING_2, "Error\nThere are no player on the map"},
	{ MALLOC_GAME_ENGINE_1, "Error\nCan't malloc a t_game_engine" },
	{ ENGINE_TEXTURE_SET_1, "Error\nCan't malloc a t_texture tab" },
	{ CREATE_TILE_1, "Error\nCan't malloc a t_texture in tile" },
	{ CREATE_TILE_2, "Error\nCan't malloc a t_tile" },
	{ CHECK_MAPNAME_1, "Error\nThe file name is invalid" },
	{ SET_COLOR_TYPE_1, "Error\nColor for ceiling or floor already done" },
	{ SET_COLOR_TYPE_2, "Error\nBad number of arguments for a color" },
	{ SET_COLOR_TYPE_3, "Error\nArguments invalid for a color" },
	{ PARSE_GAME_ENGINE_1, "Error\nSome arguments are invalid" },
	{ SET_TEXTURE_IMAGE_1, "Error\nDouble environement texture detected"},
	{ SET_TEXTURE_IMAGE_2, "Error\nThe Texture argument line is invalid"},
	{ SET_SPRITE_IMAGE_1, "Error\nSprite are already set"},
	{ SET_SPRITE_IMAGE_2, "Error\nThe Sprite argument line is invalid"},
	{ SET_DOOR_IMAGE_1, "Error\nDoor is already set"},
	{ SET_DOOR_IMAGE_2, "Error\nThe Door argument line is invalid"},
	{ SET_LEVEL_IMAGE_1, "Error\nSecret Door is already set"},
	{ SET_LEVEL_IMAGE_2, "Error\nThe Level argument line is invalid"},
	{ SET_MEDIKIT_IMAGE_1, "Error\nThe Medikit argument line is invalid"},
	{ SET_MEDIKIT_IMAGE_2, "Error\nMedikit are already set"},
	{ SET_MONSTER_IMAGE_1, "Error\nMonster is already set"},
	{ SET_MONSTER_IMAGE_2, "Error\nThe Monster argument line is invalid"},
	{ PARSE_RESOLUTION_1, "Error\nResolution are already set" },
	{ PARSE_RESOLUTION_2, "Error\nBad number of arguments for resolution" },
	{ PARSE_RESOLUTION_3, "Error\nArguments invalid for resolution" },
	{ PARSE_ENVIRONEMENT_COLOR_1, "Error\nCeiling descriptor line is incorrect" },
	{ PARSE_ENVIRONEMENT_COLOR_2, "Error\nFloor descriptor line is incorrect" },
	{ COLOR_CHECKER_1, "Error\nThe environement color is incorrect" },
	{ MALLOC_MAP_1, "Error\nCan't malloc a t_map" },
	{ PARSE_MAP_1, "Error\nA line in the map part is incorrect" },
	{ PARSE_MAP_2, "Error\nThe map part of the file is incorrect" },
	{ MALLOC_PLAYER_1, "Error\nCan't malloc a t_player *" },
	{ FLOOD_FILL_1, "Error\nForbidden char detected char on the map" },
	{ FLOOD_FILL_2, "Error\nThe map is invalid" },
	{ MALLOC_TILE_TAB_1, "Error\nCan't malloc a t_tile **" },
	{ MALLOC_TILE_TAB_2, "Error\nCan't malloc a t_tile *" },
	{ CREATE_MAP_2, "Error\nMultiple player on the map" },
	{ MALLOC_RAY_1, "Error\nRay struct can't be malloc" },
	{ MALLOC_SPRITES_1, "Error\nSprite struct can't be malloc" },
	{ MALLOC_TEXTURE_1, "Error\nTexture struct can't be malloc" },
	{ CREATE_TEXTURE_1, "Error\nMlx XPM to image failed in create texture" },
	{ SET_THREAD_OPTION_1, "Error\nThe multithread option is already set" },
	{ ERROR_NOT_FOUND, "Error\nThe Error has not be catched... Good luck" }
};

void	catch_error(int error_msg)
{
	int i;

	i = -1;
	while (g_cube3d_catch_error[++i].error_list != ERROR_NOT_FOUND)
	{
		if (error_msg == g_cube3d_catch_error[i].error_list)
		{
			ft_printf("%s\n", g_cube3d_catch_error[i].warning_msg);
			exit(EXIT_SUCCESS);
		}
	}
	if (g_cube3d_catch_error[i].error_list == ERROR_NOT_FOUND)
		ft_printf("\n%s\n", g_cube3d_catch_error[i].warning_msg);
	exit(EXIT_SUCCESS);
}
