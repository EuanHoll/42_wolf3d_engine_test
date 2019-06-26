/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawwalls.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 11:23:12 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/25 11:23:12 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		drawwalls(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < 4)
	{
		drawline(&(t_vec3){mlx->i2d.wall[i].x1, mlx->i2d.wall[i].y1, 0},
				&(t_vec3){mlx->i2d.wall[i].x2, mlx->i2d.wall[i].y2, 0},
				mlx->i2d.img_add, YELLOW);
		i++;
	}
}
