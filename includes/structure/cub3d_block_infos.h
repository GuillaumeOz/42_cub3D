/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_block_infos.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 18:57:34 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 16:33:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BLOCK_INFOS_H
# define CUB3D_BLOCK_INFOS_H

typedef struct	s_block_data
{
	int			column;
	int			num;
	int			i;
	t_texture	act;
	t_ray		info;
	float		x;
	float		y;
	t_vector2	pos;
	t_color		color;
}				t_block_data;

#endif
