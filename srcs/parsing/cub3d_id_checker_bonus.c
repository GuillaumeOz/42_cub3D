/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_id_checker_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:14:45 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/21 15:49:57 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	it_is_bonus(char *id)
{
	if (ft_strcmp(id, "R") == true && BONUS == true)
		return (true);
	else if (ft_strcmp(id, "S") == true && BONUS == true)
		return (true);
	else if (ft_strcmp(id, "FT") == true && BONUS == true)
		return (true);
	else if (ft_strcmp(id, "CT") == true && BONUS == true)
		return (true);
	else if (ft_strcmp(id, "DO") == true && BONUS == true)
		return (true);
	return (false);
}
