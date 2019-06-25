/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hookcontrols.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/24 16:20:19 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/24 16:20:19 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			exit1(void *param)
{
	(void)param;
	exit(0);
}

int			mousemove(int x, int y, void *param)
{
	t_mouse *mouse;

	mouse = (t_mouse*)param;
	mouse->x = x;
	mouse->y = y;
	return (0);
}

static int	keycontroller(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	if (key == KEY_ESC)
		exit1(NULL);
	return (0);
}

int			hookcontrols(t_mlx *mlx)
{
	mlx_hook(mlx->win, MOUSE_MOVE_EVENT, NULL_MASK, mousemove, (void*)(&mlx->mouse));
	mlx_hook(mlx->win, CLOSE_EVENT, 1L << CLOSE_EVENT, exit1, NULL);
	mlx_hook(mlx->win, KEY_PRESS_EVENT, NULL_MASK, keycontroller, (void*)mlx);
	return (0);
}

