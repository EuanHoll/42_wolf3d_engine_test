/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 11:10:23 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/26 11:10:23 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	i2dloop(t_mlx *mlx, t_mouse *m, t_vec3 *hits)
{
	ft_bzero(mlx->i2d.img_add, (SCREEN_WIDTH * SCREEN_HEIGHT) * 4);
	drawrays(mlx->i2d.mouse.x, mlx->i2d.mouse.y, mlx, hits);
	drawcircle(mlx->i2d.mouse.x, mlx->i2d.mouse.y, mlx);
	drawwalls(mlx);
	m->x = mlx->i2d.mouse.x;
	m->y = mlx->i2d.mouse.y;
	mlx_put_image_to_window(mlx->mlx, mlx->i2d.win, mlx->i2d.img, 0, 0);
}

void	i3dloop(t_mlx *mlx, t_vec3 *hits)
{
	ft_bzero(mlx->i3d.img_add, (SCREEN_WIDTH * SCREEN_HEIGHT) * 4);
	draw3dview(mlx, hits);
	mlx_put_image_to_window(mlx->mlx, mlx->i3d.win, mlx->i3d.img, 0, 0);
}

int		loop(void *param)
{
	t_mlx *mlx;
	static t_mouse m = (t_mouse){0,0};
	static float a = 0;
	t_vec3 hits[HITLENGTH];

	mlx = (t_mlx*)param;
	if ((mlx->i2d.mouse.x > 0 && mlx->i2d.mouse.y > 0 && 
		(m.x != mlx->i2d.mouse.x || m.y != mlx->i2d.mouse.y))
		|| mlx->angle != a)
	{
		i2dloop(mlx, &m, hits);
		i3dloop(mlx, hits);
		a = mlx->angle;
	}
	return (0);
}
