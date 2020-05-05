/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_medikit.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 14:16:47 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 16:34:06 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MEDIKIT_H
# define CUB3D_MEDIKIT_H

typedef struct	s_medikit
{
	t_texture	tex;
	int			heal;
}				t_medikit;

t_medikit		create_medikit(char *p_tex, int p_heal);
void			destroy_medikit(t_medikit p_to_destroy);
#endif
