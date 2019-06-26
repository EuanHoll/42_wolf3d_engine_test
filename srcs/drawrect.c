/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawrect.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 11:49:49 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/26 11:49:49 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		drawrect(t_vec3 *pos, t_vec3 *max, int colour, void *img_add)
{
	int x;
	int y;

	x = (int)(pos->x);
	while (x < (int)max->x)
	{
		y = (int)(pos->y);
		while (y < (int)max->y)
		{
			plot(x, y, colour, img_add);
			y++;
		}
		x++;
	}
}

