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

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"

# include "libft.h"
# include "cube3d_catch_error.h"
# include "cube3d_color.h"
# include "cube3d_vector.h"
# include "cube3d_config.h"
# include "cube3d_application.h"
# define debug write(1, "ICI\n", 5);

// protection resolution de la map
// player struct

	// debug
	// printf("title -> %s\n", data->title);
	// printf("reso x -> %f\n", data->resolution_size->x);
	// printf("reso y -> %f\n", data->resolution_size->y);
	// printf("player stance -> %c\n", data->player_stance);
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

// int g_langage = 0;

// char *error_msg[][3] = {
// 	{"francais", "anglais", "espagnol"}, // DEFINE ERROR MAIN_ERROR_1 0
// 	{"francais", "anglais", "espagnol"}, // DEFINE ERROR MAIN_ERROR_2 1
// 	{"francais", "anglais", "espagnol"},
// 	{"francais", "anglais", "espagnol"},
// 	{"francais", "anglais", "espagnol"},
// 	{"francais", "anglais", "espagnol"}
// };

// void print_error(int index)
// {
// 	char *msg = erro_msg[index][g_langage];
// }
#endif
