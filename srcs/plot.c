/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plot.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 16:36:24 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/06 11:50:32 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	inbounds(int x, int y)
{
	if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
		return (0);
	return (1);
}

void		plot(int x, int y, int colour, void *img_add)
{
	int *i_img;

	i_img = (int*)img_add;
	if (inbounds(x, y))
		ft_memcpy(&i_img[(y * SCREEN_WIDTH) + x], &colour, 4);
}
