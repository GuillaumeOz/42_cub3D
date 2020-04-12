/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 11:36:39 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/12 23:03:07 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// void	*im5;
// int		bpp5;
// int		sl5;
// int		endian5;
// char 	*data5;
// int		xpm5_x;
// int		xpm5_y;

// 	if (!(im5 = mlx_xpm_file_to_image(g_app->mlx_ptr,"/home/guillaumeoz/Desktop/workingdir/42_cube3D/textures/xpm/MARBFACE.xpm",&xpm5_x,&xpm5_y)))
// 	{
// 		printf(" !! KO !!\n");
// 		exit(1);
// 	}
// 	data5 = mlx_get_data_addr(im5,&bpp5,&sl5,&endian5);
// 	mlx_put_image_to_window(g_app->mlx_ptr, g_app->win_ptr,im5, 250, 250);
// 	mlx_put_image_to_window(g_app->mlx_ptr, g_app->win_ptr, engine->texture[1]->img_ptr, 100, 100);

// Bah tu dois reussir a faire un rapport de proportionnalite entre la colonne de
//  pixel a l'ecran, dans le mur, vis des pixels horizontaux dans la texture
 
// Genre dire : je dois dessiner un mur de 45 pixels, ma textures fait 32 pixels de large.
//  Du coup la colonne 1/45 de l'ecran correspond a la XXX de la texture, la 2/45 a YYY , etc
 
//  Une fois que tu as ca, tu as la colonne de pixel a dessiner
 
//  Mais tu as aussi besoin du pixel precis, a savoir dire je veux 
//  le pixel a tel ligne, en hauteur
 
//  Pour ca, meme chose : ma colonne a l'ecran fait A hauteur en pixel, ma colonne 
//  sur ma texture fait B, pouf, petite proportionnalite, et tu devines comme ca le pixels

void   draw_texture(t_game_engine *engine, t_vector2 pos, int index)
{
	int		**tex_pix;
	int		mod;
	size_t	i;

	i = 0;
	tex_pix = engine->texture[0]->tex_tab;
	mod = index == 0 ? 0 : index % (int)engine->texture[0]->size.x;
	while (i < engine->texture[0]->size.y)
	{
		put_tex_pix(g_app->image, pos, tex_pix[i][mod]);
		i++;
	}
	//check les values des decalages binaires
}
