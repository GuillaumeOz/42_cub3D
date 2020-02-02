/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 11:26:45 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/27 16:16:02 by gozsertt         ###   ########.fr       */
/*                                           i                                 */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdio.h> // del this at the end ?
# include <stdlib.h>
# include <math.h>
# include "mlx.h"

# include "libft.h"
# include "cube3d_catch_error.h"
# include "cube3d_color.h"
# include "cube3d_vector.h"
# include "cube3d_player.h"
# include "cube3d_config.h"
# include "cube3d_application.h"

enum	e_cube3d_error
{
	ERROR_NOT_FOUND = -1,
	MAIN_1,
	CHECK_MAPNAME_1,
	CUBE_FORMATTER_1,
	CUBE_FORMATTER_2,
	PARSE_TEXTURE_1,
	PARSE_RESOLUTION_1,
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
	FILL_PLAYER_1
};

# define debug write(1, "ICI\n", 5)
# define PRINTS(x) printf("%s\n", x)
# define PRINTC(x) printf("%c\n", x)
# define PRINTD(x) printf("%d\n", x)

// protection resolution de la map
// player struct

	// debug
	// printf("title -> %s\n", data->title);
	// printf("reso x -> %f\n", data->resolution_size->x);
	// printf("reso y -> %f\n", data->resolution_size->y);
	// printf("player stance -> %c\n", data->player_stance); ADD PLAYER PART
	// printf("north -> %s\n", data->north_texture);
	// printf("south -> %s\n", data->south_texture);
	// printf("west -> %s\n", data->west_texture);
	// printf("east -> %s\n", data->east_texture);
	// printf("sprite -> %s\n", data->sprite_texture);
	// printf("floor R -> %hhu\n", data->floor->r);
	// printf("floor G -> %hhu\n", data->floor->g);
	// printf("floor B -> %hhu\n", data->floor->b);
	// printf("ceiling R -> %hhu\n", data->ceiling->r);
	// printf("ceiling G -> %hhu\n", data->ceiling->g);
	// printf("ceiling B -> %hhu\n", data->ceiling->b);
	// indextest = 0;
	// while (data->map[indextest] != NULL)
	// 	printf("data -> %s", data->map[indextest]);	
	// exit(FAILURE);

#endif
