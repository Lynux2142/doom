/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_casting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruellou <aruellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:40:46 by aruellou          #+#    #+#             */
/*   Updated: 2018/12/03 10:40:48 by aruellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void    floor_casting(t_all *all, int x, int i)
{
    float	cur;
	float	weight;
	int		fx;
	int 	fy;
	float	h;

	// h = ((((float)all->start_wall / (float)WINY) * 712.8f) / WINY);
    // cur = (WINY / ((1.33f + (all->wall_gap * 0.33)) * i - (WINY * h))) / cos(all->lens);
    // weight = cur / (all->rc.ray.dist / BS_INT);

    // fx = (int)((weight * (all->rc.ray.x / BS_INT)
	// 		+ (1.0f - weight) * (all->p.x / BS_INT)) * BS_INT) % BS_INT;
    // fy = (int)((weight * (all->rc.ray.y / BS_INT)
	// 		+ (1.0f - weight) * (all->p.y / BS_INT)) * BS_INT) % BS_INT;

	h = ((((float)all->start_wall / (float)WINY) * 712.8f) / WINY) + 0.1;
    cur = (WINY / ((1.66f) * i - (WINY * h))) / cos(all->lens);
    weight = cur / (all->rc.ray.dist / BS_INT);

    fx = (int)((weight * (all->rc.ray.x / BS_INT)
			+ (1.0f - weight) * (all->p.x / BS_INT)) * BS_INT) % BS_INT;
    fy = (int)((weight * (all->rc.ray.y / BS_INT)
			+ (1.0f - weight) * (all->p.y / BS_INT)) * BS_INT) % BS_INT;

    if (i == 320) {
        printf("all->wall_gap: %f\n", all->wall_gap);
        printf("all->start_wall: %d\n", all->start_wall);
    }

    ft_fill_pixel(&all->fp, x, i,
		ft_color_textures(&all->textures.img_d, fx - 32, fy));
}


void    ceil_casting(t_all *all, int x, int i)
{
    float	cur;
	float	weight;
	int		fx;
	int 	fy;
	float	h;

	h = (((float)all->start_wall / (float)WINY) * 712.8f) / WINY;
    cur = (WINY / (1.33f * i - (WINY * h))) / cos(all->lens);
    weight = cur / (-all->rc.ray.dist / BS_INT);

    fx = (int)((weight * ((all->rc.ray.x / BS_INT))
			+ (1.0f - weight) * (all->p.x / BS_INT)) * BS_INT) % BS_INT;
    fy = (int)((weight * ((all->rc.ray.y / BS_INT))
			+ (1.0f - weight) * (all->p.y / BS_INT)) * BS_INT) % BS_INT;

    ft_fill_pixel(&all->fp, x, i,
		ft_color_textures(&all->textures.ceil, fx - 32, fy));
}