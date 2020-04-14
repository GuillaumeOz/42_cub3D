/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 11:36:39 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/14 20:38:28 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void			*multhread_calcul_height(void *ptr)
{
	t_multithread_struct	*object;
	float					act_pixel;
	t_ray					info;
	int						i;
	t_sprites				*lst_sprite;

	object = ((void **)ptr)[1];
	lst_sprite = NULL;
	i = object->nb_to_draw - 1;
	while (i >= 0)
	{
		act_pixel = ((float)object->hero->fov / object->map->size.x) *
														(object->num_pixel + i);
		info.angle = degree_to_radian((float)object->hero->fov / 2 - act_pixel);
		info.ray = create_vector2(object->hero->forward.x * cos(info.angle) -
		object->hero->forward.y * sin(info.angle),
		object->hero->forward.x * sin(info.angle) + object->hero->forward.y *
		cos(info.angle));
		info.column = (object->nb_to_draw - i) + ((1 - object->index - 1) *
		object->nb_to_draw);
		test_check(&info, *(object->hero), *(object->map), &lst_sprite);
		check_ray(info, *(object->hero), *(object->map), &lst_sprite);
		object->lst[object->num_pixel + i--] = info.pos;
	}
	return (NULL);
}

static t_vector2	*calcul_height(t_actor hero, t_map *map)
{
	t_vector2				*lst;
	float					nb_to_draw;
	t_multithread_struct	object[1];
	void					*ptr[1][2];
	int						i;

	i = 0;
	lst = (t_vector2*)malloc(sizeof(t_vector2) * map->size.x);
	if (lst == NULL)
		return (NULL);
	nb_to_draw = map->size.x / ((float)1);
	object[i] = create_multithread_struct(&hero, map, lst);
	set_multithread_struct_value(&(object[i]), (int)(i * nb_to_draw),
		nb_to_draw);
	set_multithread_struct_index(&(object[i]), i);
	ptr[i][1] = &(object[i]);
	multhread_calcul_height(ptr);
	return (lst);
}

void				draw_wall(t_actor hero, t_map *map)
{
	t_vector2 *lst;

	hero.forward = create_vector2(hero.forward.x - hero.pos.x,
		hero.forward.y - hero.pos.y);
	hero.forward = normalize_vector2(hero.forward);
	hero.right.x = hero.forward.x * cos(PI / 2) - hero.forward.y * sin(PI / 2);
	hero.right.y = hero.forward.x * sin(PI / 2) + hero.forward.y * cos(PI / 2);
	lst = calcul_height(hero, map);
	free(lst);
}

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

// void   draw_texture(t_game_engine *engine, t_vector2 pos, int index)
// {
// 	// int		**tex_pix;
// 	char	*pix;
// 	int		mod;
// 	size_t	i;

// 	i = 0;
// 	// tex_pix = engine->texture[0]->tex_tab;
// 	pix = engine->texture[0]->pixels;
// 	//mod = index == 0 ? 0 : index % (int)engine->texture[0]->size_line;
// 	mod = index;
// 	while (i < engine->texture[0]->size.y)
// 	{
// 		// put_tex_pix(g_app->image, pos, tex_pix[i][mod]);
// 		put_tex_pix(g_app->image, pos, create_color(pix[mod + RED_COMP], pix[mod + GREEN_COMP], pix[mod + BLUE_COMP], 255));
// 		mod += (size_t)engine->texture[0]->size_line;
// 		i++;
// 	}
// 	//check les values des decalages binaires
// }
