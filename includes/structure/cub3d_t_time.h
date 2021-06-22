/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_t_time.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:04:09 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/17 18:10:58 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_T_TIME_H
# define CUB3D_T_TIME_H

typedef struct s_time
{
	double	oldTime;
	double	time;
}				t_time;

t_time			*malloc_time(void);
t_time			create_time(void);
void			destroy_time(t_time time);
void			free_time(t_time *time);

void			set_old_time(t_time *time);
void			set_current_time(t_time *time);

double			get_old_time(t_time *time);
double			get_time(t_time *time);

#endif
