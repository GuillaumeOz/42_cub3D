/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggl_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:48:52 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 14:24:11 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

void	ggl_error(char *error_msg)
{
	size_t	len;

	len = ggl_strlen(error_msg);
	write(1, error_msg, len);
	exit(0);
}
