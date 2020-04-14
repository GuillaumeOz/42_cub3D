/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_actor.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:23:32 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/14 20:23:45 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_ACTOR_H
# define CUBE3D_ACTOR_H

# define player_speed 1.0f
# define enemy_speed 0.0f
# define neutral_speed 0.0f

typedef enum    e_team
{
    ally = 0,
    enemy = 1,
    neutral = 2,
}               t_team;

typedef struct  s_actor
{
    t_vector2   pos;
    int         team;
    float       angle;
    float       speed;
    float       size;
    float       pitch;
    float       fov;
    t_vector2   forward;
    t_vector2   right;
}               t_actor;

typedef t_actor t_player;
typedef t_actor t_enemy;
typedef t_actor t_neutral;

t_actor     create_actor(t_vector2 p_pos, t_team p_team, t_direction p_dir, float speed);
t_actor     *malloc_actor(t_vector2 p_pos, t_team p_team, t_direction p_dir, float speed);

t_enemy     create_enemy(t_vector2 p_pos);
t_enemy     *malloc_enemy(t_vector2 p_pos);

t_player    create_player(t_vector2 p_pos, t_direction p_dir);
t_player    *malloc_player(t_vector2 p_pos, t_direction p_dir);

t_neutral    create_neutral(t_vector2 p_pos);
t_neutral    *malloc_neutral(t_vector2 p_pos);

void         destroy_actor(t_actor to_destroy);
void         free_actor(t_actor *to_free);

#endif
