/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 17:40:27 by toliver           #+#    #+#             */
/*   Updated: 2018/10/09 13:34:15 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int	window_closed(void *param)
{
	(void)param;
	exit(0);
}
