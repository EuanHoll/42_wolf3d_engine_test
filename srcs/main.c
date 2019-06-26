/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/24 16:01:12 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/24 16:01:12 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	setupwalls(t_mlx *mlx)
{
	int i;

	i = 0;
	srand(time(0));
	/* 
	while (i < OBJCOUNT)
	{
		mlx->i2d.wall[i].x1 = rand() % SCREEN_WIDTH;
		mlx->i2d.wall[i].x2 = rand() % SCREEN_WIDTH;
		mlx->i2d.wall[i].y1 = rand() % SCREEN_HEIGHT;
		mlx->i2d.wall[i].y2 = rand() % SCREEN_HEIGHT;
		i++;
	}*/
	mlx->i2d.wall[0].x1 = 100;
	mlx->i2d.wall[0].x2 = 200;
	mlx->i2d.wall[0].y1 = 100;
	mlx->i2d.wall[0].y2 = 100;

	mlx->i2d.wall[1].x1 = 100;
	mlx->i2d.wall[1].x2 = 200;
	mlx->i2d.wall[1].y1 = 200;
	mlx->i2d.wall[1].y2 = 200;

	mlx->i2d.wall[2].x1 = 100;
	mlx->i2d.wall[2].x2 = 100;
	mlx->i2d.wall[2].y1 = 100;
	mlx->i2d.wall[2].y2 = 200;

	mlx->i2d.wall[3].x1 = 200;
	mlx->i2d.wall[3].x2 = 200;
	mlx->i2d.wall[3].y1 = 100;
	mlx->i2d.wall[3].y2 = 200;
}

void	setup2d(t_mlx *mlx)
{
	int tmp;

	tmp = 0;
	mlx->angle = 0;
	mlx->i2d.win = mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "2D Rays");
	mlx->i2d.img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->i2d.img_add = mlx_get_data_addr(mlx->i2d.img, &tmp, &tmp, &tmp);
	setupwalls(mlx);
}

void	setup3d(t_mlx *mlx)
{
	int tmp;

	tmp = 0;
	mlx->i3d.win = mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "3D Ray");
	mlx->i3d.img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->i3d.img_add = mlx_get_data_addr(mlx->i3d.img, &tmp, &tmp, &tmp);
}

int		main(int argc, char **argv)
{
	t_mlx mlx;

	argv--;
	if (argc == 1)
	{
		mlx.mlx = mlx_init();
		setup3d(&mlx);
		setup2d(&mlx);
		hookcontrols(&mlx);
		mlx_loop_hook(mlx.mlx, loop, (void*)(&mlx));
		mlx_loop(mlx.mlx);
	}
	return (0);
}
