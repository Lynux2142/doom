/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:58:42 by lguiller          #+#    #+#             */
/*   Updated: 2018/12/10 17:49:34 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static char	chose_object3(t_button buttons[NB_BUTTONS], int x, int y)
{
	if (win_to_map(x) == win_to_map(buttons[B_BARREL].pos.x)
		&& win_to_map(y) == win_to_map(buttons[B_BARREL].pos.y))
		return (BARREL);
	else if (win_to_map(x) >= win_to_map(buttons[B_END].pos.x) &&
		win_to_map(x) <= win_to_map(buttons[B_END].pos.x) + 2 &&
		win_to_map(y) == win_to_map(buttons[B_END].pos.y))
		return (END);
	else if (win_to_map(x) >= win_to_map(buttons[B_MOB].pos.x) &&
		win_to_map(x) <= win_to_map(buttons[B_MOB].pos.x) + 2 &&
		win_to_map(y) == win_to_map(buttons[B_MOB].pos.y))
		return (MOB);
	return (-1);
}

static char	chose_object2(t_button buttons[NB_BUTTONS], int x, int y)
{
	if (win_to_map(x) >= win_to_map(buttons[B_ERASER].pos.x) &&
		win_to_map(x) <= win_to_map(buttons[B_ERASER].pos.x) + 3 &&
		win_to_map(y) == win_to_map(buttons[B_ERASER].pos.y))
		return (FLOOR);
	else if (win_to_map(x) >= win_to_map(buttons[TP_START].pos.x) &&
		win_to_map(x) <= win_to_map(buttons[TP_START].pos.x) + 2 &&
		win_to_map(y) == win_to_map(buttons[TP_START].pos.y))
		return (TP_S);
	else if (win_to_map(x) >= win_to_map(buttons[TP_END].pos.x) &&
		win_to_map(x) <= win_to_map(buttons[TP_END].pos.x) + 2 &&
		win_to_map(y) == win_to_map(buttons[TP_END].pos.y))
		return (TP_E);
	else if (win_to_map(x) >= win_to_map(buttons[B_START].pos.x) &&
		win_to_map(x) <= win_to_map(buttons[B_START].pos.x) + 3 &&
		win_to_map(y) == win_to_map(buttons[B_START].pos.y))
		return (START);
	else if (win_to_map(x) >= win_to_map(buttons[B_DOOR].pos.x) &&
		win_to_map(x) <= win_to_map(buttons[B_DOOR].pos.x) + 3 &&
		win_to_map(y) == win_to_map(buttons[B_DOOR].pos.y))
		return (T_DOOR);
	else
		return (chose_object3(buttons, x, y));
}

char		chose_object(t_button buttons[NB_BUTTONS],
				int x, int y, int colision)
{
	if (win_to_map(x) == win_to_map(buttons[WOOD].pos.x) &&
		win_to_map(y) == win_to_map(buttons[WOOD].pos.y))
		return ((colision) ? T_A : T_AS);
	else if (win_to_map(x) == win_to_map(buttons[METAL].pos.x) &&
		win_to_map(y) == win_to_map(buttons[METAL].pos.y))
		return ((colision) ? T_B : T_BS);
	else if (win_to_map(x) == win_to_map(buttons[STONE].pos.x) &&
		win_to_map(y) == win_to_map(buttons[STONE].pos.y))
		return ((colision) ? T_C : T_CS);
	else if (win_to_map(x) == win_to_map(buttons[ICE].pos.x) &&
		win_to_map(y) == win_to_map(buttons[ICE].pos.y))
		return ((colision) ? T_D : T_DS);
	else if (win_to_map(x) == win_to_map(buttons[B_UPSTAMI].pos.x)
		&& win_to_map(y) == win_to_map(buttons[B_UPSTAMI].pos.y))
		return (UPSTAMI);
	else if (win_to_map(x) == win_to_map(buttons[B_JETPACK].pos.x)
		&& win_to_map(y) == win_to_map(buttons[B_JETPACK].pos.y))
		return (JETPACK);
	else if (win_to_map(x) == win_to_map(buttons[B_GIRL].pos.x)
		&& win_to_map(y) == win_to_map(buttons[B_GIRL].pos.y))
		return (GIRL);
	else
		return (chose_object2(buttons, x, y));
}

Mix_Music	*get_sounds(t_env *env, char x)
{
	if (x == T_A || x == T_AS)
		return (env->sounds.wood);
	if (x == T_B || x == T_BS)
		return (env->sounds.metal);
	if (x == T_C || x == T_CS)
		return (env->sounds.stone);
	if (x == T_D || x == T_DS)
		return (env->sounds.ice);
	if (x == TP_S)
		return (env->sounds.tp_start);
	if (x == TP_E)
		return (env->sounds.tp_exit);
	if (x == T_DOOR)
		return (env->sounds.door);
	if (x == FLOOR)
		return (env->sounds.erase);
	if (x == START)
		return (env->sounds.start);
	if (x == END)
		return (env->sounds.end);
	return (NULL);
}

int			is_image(char c)
{
	if (c == TP_S || c == T_A || c == T_AS
		|| c == T_B || c == T_BS || c == T_C
		|| c == T_CS || c == T_D || c == T_DS
		|| c == BARREL || c == JETPACK || c == GIRL
		|| c == UPSTAMI || c == T_DOOR || c == MOB)
		return (1);
	return (0);
}
