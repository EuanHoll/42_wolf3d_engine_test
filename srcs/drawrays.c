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

void		drawrays(int x, int y, t_mlx *mlx)
{
	int a;
	float i;
	float j;
	float p;

	a = 0;
	p = PI / 180;
	while (a < 360)
	{
		i = cos((float)a * p);
		j = sin((float)a * p);
		drawray(&(t_vec3){i, j, 0}, x, y, mlx);
		a++;
	}
}
