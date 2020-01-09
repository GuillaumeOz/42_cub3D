/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_catch_error.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:09:39 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/07 14:24:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_CATCH_ERROR_H
# define CUBE3D_CATCH_ERROR_H

typedef struct	s_error
{
	char *error_list;
	char *warning_msg;
}				t_error;

void catch_error(char *error_msg);

#endif