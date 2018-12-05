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

// void    floor_casting(t_all *all, int row, int lines) {
//     // // t_mat2  floor_position;
//     // float   dist;
//     // float   alpha;
//     // t_mat3  v_dist;
//     // t_mat3  v_pos;

//     // // (void) all;
//     // (void) row;
//     // (void) lines;

//     // alpha = (((float)FOV * (float) WINY) / (float) WINX) / 2.0f;
//     // dist = CAM_HEIGHT / ft_deg(tan(alpha));
//     //     // printf("alpha: %f dist: %f\n", alpha, dist);
//     // v_pos = ft_vecdef(all->p.x, all->p.y, 0.0);
//     // v_dist = ft_vecnormalize(v_pos);
//     // printf("POS: x: %f y: %f\n", all->p.x, all->p.y);
//     // printf("x: %f y: %f z: %f\n", v_dist.x, v_dist.y, v_dist.z);
//     // // alpha = 
//     // // floor_position = 

//     float	cur;
// 	float	weight;
// 	int		fx;
// 	int		fy;

//     cur = WINY / (2.0f * lines - WINY);
//     weight = cur / all->rc.ray.dist;
//     fx = (int)((weight * all->rc.ray.fx + (1.0f - weight) * all->p.x) *
//         all->textures.img_w.width) % all->textures.img_w.width;
//     fy = (int)((weight * all->rc.ray.fy + (1.0f - weight) * all->p.y) *
//         all->textures.img_w.height) % all->textures.img_w.height;
//     ft_fill_pixel(mlx->image, row, lines, ft_color_textures(all->textures.img_w,
//         fx, fy));

// //     fx = (int)((weight * all->rc.ray.fx + (1.0f - weight) * all->p.x) *
// //         mlx->ceiling->width) % mlx->ceiling->width;
// //     fy = (int)((weight * all->rc.ray.fy + (1.0f - weight) * all->p.y) *
// //         mlx->ceiling->height) % mlx->ceiling->height;
// //     image_set_pixel(mlx->image, x, WIN_HEIGHT - y, clerp(c(0x0),
// //         get_pixel(mlx->ceiling, fx, fy), 1.0f - cur / VIEW_DIST).value);
// }
