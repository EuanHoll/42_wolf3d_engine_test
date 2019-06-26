/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wolf3d.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/24 16:02:11 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/24 16:02:11 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "values.h"
# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h> // REMOVE
# include <time.h> // REMOVE

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

typedef struct	s_object
{
	float x1;
	float y1;
	float x2;
	float y2;
}				t_object;

typedef struct	s_mouse
{
	int			x;
	int			y;
}				t_mouse;

typedef struct	s_2d
{
	void		*win;
	void		*img;
	void		*img_add;
	t_mouse		mouse;
	t_object	wall[OBJCOUNT];
}				t_2d;

typedef struct	s_3d
{
	void	*win;
	void	*img;
	void	*img_add;
}				t_3d;

typedef struct	s_mlx
{
	void		*mlx;
	float		angle;
	t_2d		i2d;
	t_3d		i3d;
}				t_mlx;

void			plot(int x, int y, int colour, void *img_add);
void			drawline(t_vec3 *pos1, t_vec3 *pos2,
							void *img_add, int colour);
int				hookcontrols(t_mlx *mlx);
void			drawcircle(int x, int y, t_mlx *mlx);
void			drawrays(int x, int y, t_mlx *mlx, t_vec3 *hits);
void			drawwalls(t_mlx *mlx);
t_vec3			*getcollision(t_mlx *mlx, t_vec3 *a, t_object wall, t_vec3 *pos);
int				closer(t_vec3 *v0, t_vec3 *v1, t_mouse *m);
void			drawray(t_vec3 *a, t_mouse *m, t_mlx *mlx, t_vec3 *hit);
int				loop(void *param);
void			draw3dview(t_mlx *mlx, t_vec3 *hits);
void			drawrect(t_vec3 *pos, t_vec3 *max, int colour, void *img_add);
float			dist(t_vec3 *v0, t_vec3 *v1);

#endif
