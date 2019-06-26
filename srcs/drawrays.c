/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawrays.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/24 17:24:24 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/24 17:24:24 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		drawrays(int x, int y, t_mlx *mlx, t_vec3 *hits)
{
	float	a;
	float	i;
	float	j;
	int		k; 
	float	p;

	a = 0;
	k = 0;
	p = PI / 180;
	while (k < HITLENGTH)
	{
		i = cos((float)(a + mlx->angle) * p);
		j = sin((float)(a + mlx->angle) * p);
		drawray(&(t_vec3){i, j, 0}, &(t_mouse){x, y,}, mlx, &hits[k]);
		a += 0.5;
		k++;
	}
}
