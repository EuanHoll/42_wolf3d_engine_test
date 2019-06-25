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

int		loop(void *param)
{
	t_mlx *mlx;
	static t_mouse m = (t_mouse){0,0};

	mlx = (t_mlx*)param;
	if (mlx->mouse.x > 0 && mlx->mouse.y > 0 && (m.x != mlx->mouse.x || m.y != mlx->mouse.y))
	{
		ft_bzero(mlx->img_add, (SCREEN_WIDTH * SCREEN_HEIGHT) * 4);
		drawrays(mlx->mouse.x, mlx->mouse.y, mlx);
		drawcircle(mlx->mouse.x, mlx->mouse.y, mlx);
		drawwalls(mlx);
		m.x = mlx->mouse.x;
		m.y = mlx->mouse.y;
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	}
	return (0);
}

void	setupwalls(t_mlx *mlx)
{
	int i;

	i = 0;
	srand(time(0));
	while (i < OBJCOUNT)
	{
		mlx->wall[i].x1 = rand() % SCREEN_WIDTH;
		mlx->wall[i].x2 = rand() % SCREEN_WIDTH;
		mlx->wall[i].y1 = rand() % SCREEN_HEIGHT;
		mlx->wall[i].y2 = rand() % SCREEN_HEIGHT;
		i++;
	}
}

void	setuptest(t_mlx *mlx)
{
	int tmp;

	tmp = 0;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Ray Casting Test");
	mlx->img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->img_add = mlx_get_data_addr(mlx->img, &tmp, &tmp, &tmp);
	setupwalls(mlx);
	hookcontrols(mlx);
	mlx_loop_hook(mlx->mlx, loop, (void*)mlx);
	mlx_loop(mlx->mlx);
}

int		main(int argc, char **argv)
{
	t_mlx mlx;

	argv--;
	if (argc == 1)
		setuptest(&mlx);
	return (0);
}
