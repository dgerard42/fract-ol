/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 12:21:31 by dgerard           #+#    #+#             */
/*   Updated: 2017/07/24 17:00:01 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				no_run(t_env *env, t_drw *drw)
{
	if (drw->y1 < drw->y0)
		ft_bitswap((unsigned char *)&(drw->y0), (unsigned char *)&(drw->y1), 4);
	while (drw->y0 < drw->y1)
		mlx_pixel_put(env->mlx, env->window, drw->x0, drw->y0++, 0x00FF00);
}

void				engine(t_env *env, t_drw *drw, int riru, int *drop)
{
	int a0;
	int a1;
	int b0;
	int	ruri;
	int	bucket;

	bucket = 0;
	ruri = (riru == 0) ? 1 : 0;
	a0 = (riru == 0) ? (drw->x0) : (drw->y0);
	a1 = (riru == 0) ? (drw->x1) : (drw->y1);
	b0 = (riru == 0) ? (drw->y0) : (drw->x0);
	while (a0 != a1)
	{
		if (riru == 0)
			mlx_pixel_put(env->mlx, env->window, a0++, b0, drw->color);
		if (riru == 1)
			mlx_pixel_put(env->mlx, env->window, b0, a0++, drw->color);
		bucket += drop[riru];
		if (bucket >= drw->level)
		{
			b0 += drw->adjust;
			drw->level += drop[ruri];
		}
	}
}

void				swap_points(t_drw *drw)
{
	ft_bitswap((unsigned char *)&(drw->x0), ((unsigned char *)&drw->x1), 4);
	ft_bitswap((unsigned char *)&(drw->y0), ((unsigned char *)&drw->y1), 4);
}

void				setup(t_drw *drw)
{
	drw->rise = (drw->y1) - (drw->y0);
	drw->run = (drw->x1) - (drw->x0);
	drw->adjust = (drw->rise * drw->run >= 0) ? 1 : -1;
}

void				draw_line(t_env *env, t_drw *drw)
{
	int		drop[2];

	setup(drw);
	drop[0] = abs(drw->rise * 2);
	drop[1] = abs(drw->run * 2);
	if (drw->run == 0)
		no_run(env, drw);
	else
	{
		if (abs(drw->rise) <= abs(drw->run))
		{
			drw->level = abs(drw->run);
			if (drw->x1 < drw->x0)
				swap_points(drw);
			engine(env, drw, 0, drop);
		}
		if (abs(drw->rise) > abs(drw->run))
		{
			drw->level = abs(drw->rise);
			if (drw->y1 < drw->y0)
				swap_points(drw);
			engine(env, drw, 1, drop);
		}
	}
}
