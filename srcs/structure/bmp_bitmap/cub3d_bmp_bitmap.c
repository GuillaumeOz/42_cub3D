/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bmp_bitmap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:31:57 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 21:22:11 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bmp_bitmap	*malloc_bmp_bitmap(void)
{
	t_bmp_bitmap	*bmp_bitmap;

	bmp_bitmap = (t_bmp_bitmap *)malloc(sizeof(t_bmp_bitmap));
	if (bmp_bitmap == NULL)
		cub3d_error(ERROR_BMP2, "t_bmp_bitmap cannot be malloc");
	*bmp_bitmap = create_bmp_bitmap();
	return (bmp_bitmap);
}

t_bmp_bitmap	create_bmp_bitmap(void)
{
	t_bmp_bitmap	bmp_bitmap;

	ft_memset(&bmp_bitmap, 0, sizeof(bmp_bitmap));
	return (bmp_bitmap);
}

void	destroy_bmp_bitmap(t_bmp_bitmap to_destroy)
{
	ft_memset(&to_destroy, 0, sizeof(to_destroy));
}

void	free_bmp_bitmap(t_bmp_bitmap *to_free)
{
	destroy_bmp_bitmap(*to_free);
	free(to_free);
}
