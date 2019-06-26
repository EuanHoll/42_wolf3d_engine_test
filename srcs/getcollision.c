/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   getcollision.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 14:33:45 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/25 14:33:45 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_vec3		*getcollision(t_mlx *mlx, t_vec3 *a, t_object wall, t_vec3 *pos)
{
	float x;
	float y;
	float d;
	t_vec3 vec;
	
	x = mlx->i2d.mouse.x + a->x;
	y = mlx->i2d.mouse.y + a->y;
	d = ((wall.x1 - wall.x2) * (mlx->i2d.mouse.y - y)) -
		((wall.y1 - wall.y2) * (mlx->i2d.mouse.x - x));
	if (d == 0)
		return (NULL);
	vec.x = (((wall.x1 - mlx->i2d.mouse.x) * (mlx->i2d.mouse.y - y)) -
			((wall.y1 - mlx->i2d.mouse.y) * (mlx->i2d.mouse.x - x))) / d;
	vec.y = -(((wall.x1 - wall.x2) * (wall.y1 - mlx->i2d.mouse.y)) -
			((wall.y1 - wall.y2) * (wall.x1 - mlx->i2d.mouse.x))) / d;
	if (vec.x > 0 && vec.x < 1 && vec.y > 0)
	{
		pos->x = mlx->i2d.mouse.x + (vec.y * a->x);
		pos->y = mlx->i2d.mouse.y + (vec.y * a->y);
		return (pos);
	}
	return (NULL);
}
