/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:19:27 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/22 14:29:54 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <limits.h>
# include <sys/time.h>
# include "libft.h"
# include "../lib/mlx/mlx.h"
# include "cub3d_mlx_define.h"
# include "cub3d_error.h"
# include "cub3d_t_color.h"
# include "cub3d_t_image.h"
# include "cub3d_t_application.h"
# include "cub3d_t_texture.h"
# include "cub3d_t_sprite.h"
# include "cub3d_t_time.h"
# include "cub3d_t_player.h"
# include "cub3d_t_engine.h"
# include "cub3d_t_floor_calc.h"
# include "cub3d_t_wall_calc.h"
# include "cub3d_t_sprite_calc.h"
# include "cub3d_drawing.h"
# include "cub3d_event_manager.h"
# include "cub3d_parsing.h"
# include "cub3d_bmp.h"

int	quit(void *param);
int	routine(void *param);

#endif