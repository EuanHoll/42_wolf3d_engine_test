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

	x = sqrtf(powf((float)m->x - v0->x , 2) + powf((float)m->y - v0->y , 2));
	y = sqrtf(powf((float)m->x - v1->x , 2) + powf((float)m->y - v1->y , 2));
	return (x < y);
}
