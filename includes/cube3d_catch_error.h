/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_catch_error.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:09:39 by gozsertt          #+#    #+#             */
/*   Updated: 2020/03/03 16:41:35 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_CATCH_ERROR_H
# define CUBE3D_CATCH_ERROR_H

typedef struct	s_error
{
	int		error_list;
	char	*warning_msg;
}				t_error;

enum	e_cube3d_error
{
	ERROR_NOT_FOUND = -1,
	MAIN_1,
	CREATE_GAME_ENGINE_1,
	CREATE_GAME_ENGINE_2,
	CREATE_TILE_1,
	CREATE_TILE_2,
	CHECK_MAPNAME_1,
	SET_COLOR_TYPE_1,
	SET_COLOR_TYPE_2,
	SET_COLOR_TYPE_3,
	PARSE_GAME_ENGINE_1,
	PARSE_RESOLUTION_1,
	PARSE_RESOLUTION_2,
	PARSE_RESOLUTION_3,
	PARSE_ENVIRONEMENT_COLOR_1,
	PARSE_ENVIRONEMENT_COLOR_2,
	MALLOC_MAP_1,
	PARSE_MAP_1,
	PARSE_MAP_2,
	MALLOC_TILE_TAB_1,
	MALLOC_TILE_TAB_2,
	CREATE_MAP_1,
};

void catch_error(int error_msg);

#endif