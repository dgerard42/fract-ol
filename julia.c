/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:00:22 by dgerard           #+#    #+#             */
/*   Updated: 2017/07/06 17:00:24 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void				julia_draw(t_env *env, t_jul *jul)
{
	int i;
	double x;
	double y;

	y = -1;
	while (y++ < WIN_HI)
	{
		x = 0;
		while (x <= WIN_LEN)
		{
			i = 0;
			jul->color = 0xFF0000;
			jul->zRnew = (x - (WIN_LEN / 2)) / (WIN_LEN / 3);
			jul->zInew = (y - (WIN_HI / 2)) / (WIN_HI / 3);
			while (i++ < 300 && (jul->zRnew * jul->zRnew) + (jul->zInew * jul->zInew) < 4)
			{
				jul->zRold = jul->zRnew;
				jul->zIold = jul->zInew;
				jul->zRnew = (jul->zRold * jul->zRold) - (jul->zIold * jul->zIold) + jul->cR;
				jul->zInew = (2 * jul->zRold * jul->zIold) + jul->cI;
				jul->color += 1000;
			}
			mlx_pixel_put(env->mlx, env->window, x++, y, jul->color);
		}
	}
}

void				julia(t_env *env)
{
	t_jul jul;

	jul.cR = -0.624;
	jul.cI = 0.435;
	env->window = mlx_new_window(env->mlx, WIN_LEN, WIN_HI, "~ J U L I A ~");
	julia_draw(env, &jul);
}
