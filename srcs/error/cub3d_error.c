/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:41:37 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 19:29:29 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d_error(t_cub3d_error error, char *error_msg)
{
	printf("Error\n(%d) ", error);
	printf("%s\n", error_msg);
	exit(error);
}
