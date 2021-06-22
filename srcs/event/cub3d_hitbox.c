/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_hitbox.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 21:18:30 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/21 21:35:25 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	hitbox(double x, double y, t_list *map_list)
{
	char	*map;

	map = list_at(map_list, y);
	if (BONUS == false)
	{
		if (x < 0.0f || y < 0.0f || y > ((double)map_list->size)
			|| x > ((double)ft_strlen(list_at(map_list, y))))
			return (true);
	}
	else if (map[(int)x] == '1' || map[(int)x] == '2'
		|| ft_ischar("abcdefghijk", map[(int)x]) == true)
		return (true);
	return (false);
}
