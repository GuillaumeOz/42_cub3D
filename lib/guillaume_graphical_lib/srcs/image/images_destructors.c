/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_destructors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 16:35:02 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/23 16:35:42 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

void			destroy_image_from_file(t_image image)
{
	(void)image;
}

void			free_image_from_file(t_image *image)
{
	destroy_image_from_file(*image);
	free(image);
}
