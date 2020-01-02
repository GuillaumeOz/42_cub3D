/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_vector.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:15:36 by gozsertt          #+#    #+#             */
/*   Updated: 2019/12/31 14:23:59 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_VECTOR
# define CUBE3D_VECTOR

typedef struct s_vector
{
	int	x;
	int	y;
}			t_vector;

t_vector	*malloc_vector(int x, int y);
t_vector	create_vector(int x, int y);
void		destroy_vector(t_vector to_destroy);
void		free_vector(t_vector *to_free);

#endif