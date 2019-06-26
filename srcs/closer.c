/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   closer.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 14:32:56 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/25 14:32:56 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			closer(t_vec3 *v0, t_vec3 *v1, t_mouse *m)
{
	float x;
	float y;

	x = dist(v0, &(t_vec3){m->x, m->y, 0});
	y = dist(v1, &(t_vec3){m->x, m->y, 0});
	return (x < y);
}
