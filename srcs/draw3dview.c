/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw3dview.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 11:32:53 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/26 11:32:53 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		fill(t_vec3 *pos, t_vec3 *hit, float angle, t_mlx *mlx)
{
	long	colour;
	int		r;
	float	hb;

	angle--;
	hb = dist(hit, &(t_vec3){mlx->i2d.mouse.x, mlx->i2d.mouse.y, 0}) / VIEWDIS;
	r = (int)255 - ((float)255 * hb);
	hb = hb * (SCREEN_HEIGHT / 2);
	colour = (r << 16L) & 0x00ff0000;
	colour += (r << 8L) & 0x0000ff00;
	colour += r & 0x000000ff;
	drawrect(&((t_vec3){(int)pos->x, hb, 0}), &((t_vec3){(int)(pos->x + pos->y)
			, SCREEN_HEIGHT - hb, 0}), colour, mlx->i3d.img_add);
}

void		draw3dview(t_mlx *mlx, t_vec3 *hits)
{
	float splity;
	int i;

	splity = ((float)SCREEN_WIDTH / HITLENGTH);
	i = 0;
	while (i < HITLENGTH)
	{
		fill(&(t_vec3){((float)i * splity), splity, 0}, &hits[i], ((float)i / (HITLENGTH / FOV)) + mlx->angle, mlx);
		i++;
	}
}
