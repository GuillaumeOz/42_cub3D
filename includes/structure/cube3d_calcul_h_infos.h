/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_calcul_h_infos.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 18:49:58 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/23 18:55:24 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_CALCUL_H_INFOS_H
# define CUBE3D_CALCUL_H_INFOS_H

# define NB_THREAD 4

typedef struct				s_calcul_h_data
{
	int						num_pixel;
	int						i;
	t_vector2				*lst;
	float					nb_to_draw;
	t_multithread_struct	object[NB_THREAD];
	void					*ptr[NB_THREAD][2];
	pthread_t				thread_list[NB_THREAD];
}							t_calcul_h_data;

#endif