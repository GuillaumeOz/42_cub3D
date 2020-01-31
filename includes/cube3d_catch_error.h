/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_catch_error.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:09:39 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/30 17:28:02 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_CATCH_ERROR_H
# define CUBE3D_CATCH_ERROR_H

typedef struct	s_error
{
	int		error_list;
	char	*warning_msg;
}				t_error;

void catch_error(int error_msg);

#endif