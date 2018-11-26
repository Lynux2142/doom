/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:55:11 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/26 10:26:40 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void	ft_clear_minimap(t_img *ptr)
{
	int x;
	int y;

	y = -1;
	while (++y < INFOY)
	{
		x = -1;
		while (++x < INFOX)
			ft_fill_pixel(ptr, x, y, 0xFF000000);
	}
}

static void	ft_rect(t_img *ptr, int x, int y, int c)
{
	t_coord	p1;
	t_coord	p2;

	p1.y = y;
	p2.x = x + (BLOCK_SIZE / ZOOM);
	p2.y = y + (BLOCK_SIZE / ZOOM);
	while (++p1.y + 1 < p2.y)
	{
		p1.x = x;
		while (++p1.x + 1 < p2.x)
			ft_fill_pixel(ptr, p1.x, p1.y, c);
	}
}

void		ft_perso(t_img *ptr, t_player p)
{
	t_mat2			i;
	const t_mat3	pos = ft_vecdef(INFOX / 2, INFOY / 2, 0.0);
	t_mat3			view;

	view = ft_vecadd(ft_vecrotz(ft_vecdef(10.0, 0.0, 0.0), -p.a), pos);
	ft_algo(ptr, ft_pointdef((int)pos.x, (int)pos.y),
		ft_pointdef((int)view.x, (int)view.y), YELLOW);
	i.y = -P_SIZE;
	while (++i.y <= P_SIZE)
	{
		i.x = -P_SIZE;
		while (++i.x <= P_SIZE)
			ft_fill_pixel(ptr, i.x + (INFOX / 2), i.y + (INFOY / 2), RED);
	}
}

static void	fill_rect(t_img *ptr, char map[MAPY][MAPX], t_player p, t_point i)
{
	const int		dimx = BLOCK_SIZE - (p.x / ZOOM) + HIT_BOX;
	const int		dimy = BLOCK_SIZE - (p.y / ZOOM) + HIT_BOX;

	if (map[i.y][i.x] == T_A || map[i.y][i.x] == T_B || map[i.y][i.x] == T_C
		|| map[i.y][i.x] == T_D)
		ft_rect(ptr, to_win(i.x) + dimx, to_win(i.y) + dimy, WHITE);
	if (map[i.y][i.x] == T_A_S || map[i.y][i.x] == T_B_S
			|| map[i.y][i.x] == T_C_S || map[i.y][i.x] == T_D_S)
		ft_rect(ptr, to_win(i.x) + dimx, to_win(i.y) + dimy, WHITE);
	else if (map[i.y][i.x] == TP_S)
		ft_rect(ptr, to_win(i.x) + dimx, to_win(i.y) + dimy, LIGHT_GREEN);
	else if (map[i.y][i.x] == TP_E)
		ft_rect(ptr, to_win(i.x) + dimx, to_win(i.y) + dimy, GREEN);
	else if (map[i.y][i.x] == T_DOOR_C)
		ft_rect(ptr, to_win(i.x) + dimx, to_win(i.y) + dimy, BLUE);
	else if (map[i.y][i.x] == END)
		ft_rect(ptr, to_win(i.x) + dimx, to_win(i.y) + dimy, PURPLE);
}

void		ft_print_map(t_img *ptr, char map[MAPY][MAPX], t_player p)
{
	t_point	i;

	ft_clear_minimap(ptr);
	i.y = -1;
	while (++i.y < MAPY)
	{
		i.x = -1;
		while (++i.x < MAPY)
		{
			fill_rect(ptr, map, p, i);
			if (door_timer(0.0, i.y, i.x, map[i.y][i.x]) == 1.0)
				map[i.y][i.x] = T_DOOR_O;
		}
	}
}
