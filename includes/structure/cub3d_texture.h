/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_texture.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 14:42:43 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 16:33:47 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TEXTURE_H
# define CUB3D_TEXTURE_H

typedef struct		s_wall
{
	int				width;
	int				height;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	char			*tex;
	char			*path;
}					t_texture;

t_texture			create_texture(char *path);
t_texture			*malloc_texture(char *path);
void				destroy_texture(t_texture p_wall);
void				free_texture(t_texture *p_wall);

#endif
