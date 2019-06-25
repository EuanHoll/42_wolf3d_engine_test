/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawray.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 14:43:02 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/25 14:43:02 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		drawray(t_vec3 *a, int x, int y, t_mlx *mlx)
{
	int i;
	t_vec3 vec;
	t_vec3 pos;

	i = 0;
	vec.x = -2147483648;
	vec.y = -2147483648;
	vec.z = -2147483648;
	ft_memcpy(&pos, &vec, sizeof(vec));
	while (i < OBJCOUNT)
	{
		getcollision(mlx, a, mlx->wall[i], &pos);
		if (closer(&vec, &pos, &mlx->mouse) == 0)
			ft_memcpy(&vec, &pos, sizeof(pos));
		i++;
	}
	if (vec.x != -2147483648)
			drawline(&(t_vec3){x, y, 0}, &vec, mlx->img_add, DARK_GREEN);
	else
		drawline(&(t_vec3){x, y, 0}, &(t_vec3){x + (a->x * 1000), y + (a->y * 1000), 0}, mlx->img_add, DARK_GREEN);
}
