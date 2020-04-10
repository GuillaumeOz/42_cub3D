/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:26:53 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/07 12:53:10 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdint.h>

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

# include "libft.h"
# include "ggl.h"
# include "cube3d_catch_error.h"
# include "cube3d_tile.h"
# include "cube3d_actor.h"
# include "cube3d_game_engine.h"
# include "cube3d_map.h"
# include "cube3d_parsing.h"
# include "cube3d_cast_ray.h"
# include "cube3d_draw_map.h"
# include "cube3d_key_handler.h"
# include "cube3d_save.h"

# define FOV 70.0f

t_application *g_app;

# define debug write(1, "ICI\n", 5)
# define PRINTS(x) printf("%s\n", x);
# define PRINTC(x) printf("%c\n", x);
# define PRINTD(x) printf("%d\n", x);
# define PRINTP(x) printf("%p\n", x);
# define PRINTF(x) printf("%f\n", x);
# define PRINTU(x) printf("%zu\n", x);
# define PRINTV(x,y) printf("(%f;%f)\n", x, y);
# define PRINTPOS printf("%s line %d\n", __func__, __LINE__)

# endif
