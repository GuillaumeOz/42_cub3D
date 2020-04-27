/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:26:53 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/27 17:36:50 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdint.h>
# include <pthread.h>

//Linux header

# include	<string.h>
# include   <unistd.h>
# include   <fcntl.h>
# include   <sys/mman.h>
# include	<X11/Xlib.h>
# include	<X11/Xutil.h>
# include	<sys/ipc.h>
# include	<sys/shm.h>
# include	<X11/extensions/XShm.h>

//Linux header

# define FOV 70.0f
# define PI 3.14159265
# define PI2 6.28318530
# define SIZE 6.0f

# include "libft.h"
# include "ggl.h"
# include "cube3d_catch_error.h"
# include "cube3d_texture.h"
# include "cube3d_medikit.h"
# include "cube3d_monster.h"
# include "cube3d_player.h"
# include "cube3d_game_engine.h"
# include "cube3d_tile.h"
# include "cube3d_map.h"
# include "cube3d_parsing.h"
# include "cube3d_cast_ray.h"
# include "cube3d_key_handler.h"
# include "cube3d_save.h"
# include "cube3d_update.h"
# include "cube3d_multi_thread.h"
# include "cube3d_ray.h"
# include "cube3d_sprites.h"
# include "cube3d_draw.h"
# include "cube3d_calcul_h_infos.h"
# include "cube3d_block_infos.h"

t_application *g_app;

# define debug write(1, "ICI\n", 5);
# define PRINTS(x) printf("%s\n", x);
# define PRINTC(x) printf("%c\n", x);
# define PRINTD(x) printf("%d\n", x);
# define PRINTP(x) printf("%p\n", x);
# define PRINTF(x) printf("%f\n", x);
# define PRINTU(x) printf("%zu\n", x);
# define PRINTV(x,y) printf("(%f;%f)\n", x, y);
# define PRINTPOS printf("%s line %d\n", __func__, __LINE__)

# endif
