/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_map_data.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 10:40:05 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/02 14:43:37 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_MAP_DATA_H
# define CUBE3D_MAP_DATA_H

typedef struct	s_map
{
	t_vector	*resolution_size;
	
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;

	char	*sprite_texture;

	t_color		*floor;
	t_color		*ceiling;

	char		**map;
}				t_map;

t_map	*malloc_map_data(void);
t_map	create_map_data(void);
void	destroy_map_data(t_map to_destroy);
void	free_map_data(t_map *to_free);

#endif