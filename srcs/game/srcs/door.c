/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruellou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:11:47 by aruellou          #+#    #+#             */
/*   Updated: 2018/11/23 19:11:49 by aruellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	door_update(float timer[MAPY][MAPX])
{
	int i;
	int j;

	i = 0;
	while (i < MAPY)
	{
		j = 0;
		while (j < MAPX)
		{
			if (timer[i][j] >= 0.99)
				timer[i][j] = 1.0;
			else if (timer[i][j] != 0.0 && timer[i][j] != 1.0)
				timer[i][j] += DOOR_SPEED;
			j++;
		}
		i++;
	}
}

float	door_timer(float add, int x, int y, char c)
{
	static float timer[MAPY][MAPX];
	static int	 i = 0;

	if (i % 50000 == 0) {
		door_update(timer);
	}
	i++;
	if (c == T_DOOR_C || c == T_DOOR_M || c == T_DOOR_O)
	{
		if (c == T_DOOR_C)
			timer[y][x] = 0.0;
		else if (c == T_DOOR_O)
			timer[y][x] = 1.0;
		else if (add)
			timer[y][x] += add;
		return (timer[y][x]);
	}
	return (0.0);
}

void	door_open(t_all *all)
{
	all->a = all->p.a - ft_rad((((WINX / 2) - 1) - (WINX / 2) - 1) * RAY_ANGLE);
	ft_fp_hori(&all->rc.ray_h, &all->p, all->rc.map, all->a);
	ft_fp_vert(&all->rc.ray_v, &all->p, all->rc.map, all->a);
	if (all->rc.ray_h.dist != all->rc.ray_h.dist ||
		all->rc.ray_v.dist != all->rc.ray_v.dist)
		all->rc.ray = (all->rc.ray_h.dist != all->rc.ray_h.dist) ?
		all->rc.ray_v : all->rc.ray_h;
	else
		all->rc.ray = (all->rc.ray_h.dist <= all->rc.ray_v.dist) ?
		all->rc.ray_h : all->rc.ray_v;
	if (all->rc.map[to_map(all->rc.ray.y)][to_map(all->rc.ray.x)] == T_DOOR_C
	&& all->rc.ray.dist <= 100) {
		all->rc.map[to_map(all->rc.ray.y)][to_map(all->rc.ray.x)] = T_DOOR_M;
		door_timer(DOOR_SPEED, to_map(all->rc.ray.y), to_map(all->rc.ray.x),
			all->rc.map[to_map(all->rc.ray.y)][to_map(all->rc.ray.x)]);
	}
	all->lens -= ft_rad(RAY_ANGLE) * all->keys_tab[KEY_H];
	all->a -= ft_rad(RAY_ANGLE);
}
