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
# include "cube3d_vector4.h"
# include "cube3d_player.h"
# include "cube3d_config.h"
# include "cube3d_application.h"
# include "cube3d_lgl_define.h"

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

#endif
