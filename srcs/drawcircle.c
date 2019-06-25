/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawcircle.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/24 16:29:18 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/24 16:29:18 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		drawcircle(int x, int y, t_mlx *mlx)
{
	int r;
	int i;
	int j;

	r = 10;
	i = x - r;
	while (i < x + r && x > 0 && i < SCREEN_WIDTH)
	{
		j = y - r;
		while (j < y + r && y > 0 && j < SCREEN_HEIGHT)
		{
			if  (i > 0 && j > 0 && sqrt(pow(i - x, 2) + pow(j - y, 2)) < r)
				plot(i, j, WHITE, mlx->img_add);
			j++;
		}
		i++;
	}
}
