/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:32:20 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/17 17:54:23 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERROR_H
# define CUB3D_ERROR_H

typedef enum e_cub3d_error
{
	ERROR_APPLICATION1 = 2,
	ERROR_ENGINE1,
	ERROR_ENGINE2,
	ERROR_ENGINE3,
	ERROR_ENGINE4,
	ERROR_TEXTURE1,
	ERROR_TEXTURE2,
	ERROR_SPRITE1,
	ERROR_SPRITE2,
	ERROR_SPRITE_LIST1,
	ERROR_IMAGE1,
	ERROR_TIME_IMAGE1,
	ERROR_COLOR1,
	ERROR_PLAYER1,
	ERROR_FLOOR_CALC1,
	ERROR_WALL_CALC1,
	ERROR_SPRITE_CALC1,
	ERROR_SPRITE_CALC2,
	ERROR_SPRITE_CALC3,
	ERROR_SPRITE_CALC4,
	ERROR_TIME1,
	ERROR_TIME2,
	ERROR_BMP1,
	ERROR_BMP2,
	ERROR_PARSING1,
	ERROR_PARSING2,
	ERROR_PARSING3,
	ERROR_PARSING4,
	ERROR_PARSING5,
	ERROR_PARSING6,
	ERROR_PARSING7,
	ERROR_PARSING8,
	ERROR_PARSING9,
	ERROR_PARSING10,
	ERROR_PARSING11,
	ERROR_PARSING12,
	ERROR_PARSING13,
	ERROR_PARSING14,
	ERROR_PARSING15,
	ERROR_PARSING16,
	ERROR_PARSING17,
	ERROR_PARSING18,
	ERROR_PARSING19,
	ERROR_PARSING20,
	ERROR_PARSING21,
	ERROR_PARSING22,
	ERROR_PARSING23,
	ERROR_PARSING24,
	ERROR_PARSING25,
	ERROR_PARSING26,
	ERROR_PARSING27,
	ERROR_PARSING28,
	ERROR_PARSING29,
	ERROR_PARSING30,
	ERROR_PARSING31,
	ERROR_PARSING32,
	ERROR_PARSING33,
	ERROR_PARSING34,
	ERROR_PARSING35,
	ERROR_PARSING36,
	ERROR_PARSING37,
	ERROR_PARSING38,
	ERROR_PARSING39,
	ERROR_PARSING40,
	ERROR_NOT_FOUND,
}				t_cub3d_error;

void	cub3d_error(t_cub3d_error error, char *error_msg);

#endif
