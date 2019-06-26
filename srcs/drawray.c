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

void		drawray(t_vec3 *a, t_mouse *m, t_mlx *mlx, t_vec3 *hit)
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
		getcollision(mlx, a, mlx->i2d.wall[i], &pos);
		if (closer(&vec, &pos, &mlx->i2d.mouse) == 0)
			ft_memcpy(&vec, &pos, sizeof(pos));
		i++;
	}
	if (vec.x != -2147483648)
	{
		drawline(&(t_vec3){m->x, m->y, 0}, &vec, mlx->i2d.img_add, DARK_GREEN);
		ft_memcpy(hit, &vec, sizeof(vec));
	}
	else
	{
		drawline(&(t_vec3){m->x, m->y, 0}, &(t_vec3){m->x + (a->x * 1000), m->y + (a->y * 1000), 0}, mlx->i2d.img_add, DARK_GREEN);
		*hit = (t_vec3){m->x + (a->x * 1000), m->y + (a->y * 1000), 0};
	}
}
