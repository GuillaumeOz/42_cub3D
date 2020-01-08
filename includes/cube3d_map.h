/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:42:42 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/07 13:35:03 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_MAP_H
# define CUBE3D_MAP_H

char	**malloc_map(int map_x, int map_y);
char	create_map(int map_x, int map_y);
void	destroy_map(char to_destroy);
void	free_map(char **to_free);

#endif