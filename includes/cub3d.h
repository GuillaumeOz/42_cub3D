/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:26:53 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/10 15:28:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdint.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

/*
** Linux header
*/

# include <sys/mman.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <X11/extensions/XShm.h>

# define FOV 70.0f
# define PI 3.14159265
# define PI2 6.28318530
# define SIZE 6.0f

# include "libft.h"
# include "ggl.h"
# include "cub3d_catch_error.h"
# include "cub3d_texture.h"
# include "cub3d_medikit.h"
# include "cub3d_monster.h"
# include "cub3d_player.h"
# include "cub3d_game_engine.h"
# include "cub3d_tile.h"
# include "cub3d_map.h"
# include "cub3d_parsing.h"
# include "cub3d_cast_ray.h"
# include "cub3d_key_handler.h"
# include "cub3d_save.h"
# include "cub3d_update.h"
# include "cub3d_multi_thread.h"
# include "cub3d_ray.h"
# include "cub3d_sprites.h"
# include "cub3d_draw.h"
# include "cub3d_calcul_h_infos.h"
# include "cub3d_block_infos.h"

t_application *g_app;

#endif
