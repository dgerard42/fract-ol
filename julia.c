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

void				julia_setup(t_env *env, t_jul *jul)
{
	jul->cR = -0.7;
	jul->cI = 0.27015;
}

void				julia_draw(t_env *env, t_jul *jul)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (y <= WIN_HI)
	{
		while (x <= WIN_LEN)
		{
		//	jul->zRnew = 1.5 * ((x - WIN_LEN) / 2) / 0.5 * WIN_LEN;
		//	jul->zInew = ((y - WIN_HI) / 2) / 0.5 * WIN_HI;
			jul->zRnew = ((x / 4) - (WIN_LEN / 8));
			jul->zInew = ((y / 4) - (WIN_HI / 8));
			jul->color = 0x00FF00;
			while (i < 200)
			{
				jul->zRold = jul->zRnew;
				jul->zIold = jul->zInew;
				jul->zRnew = (jul->zRold * jul->zRold) - (jul->zIold * jul->zIold) + jul->cR;
				jul->zInew = (2 * jul->zRold * jul->zIold) + jul->cI;
				if((jul->zRnew * jul->zRnew) + (jul->zInew * jul->zInew) > 4)
					break;
				jul->color++;
				mlx_pixel_put(env->mlx, env->window, x, y, jul->color);
			}
			x++;
		}
		y++;
	}
//	mlx_pixel_put(env->mlx, env->window, 150, 150, 0x00FF00);
}

void				julia(t_env *env)
{
	t_jul jul;

	julia_setup(env, &jul);
	env->window = mlx_new_window(env->mlx, WIN_LEN, WIN_HI, "✿ julia ✿");
	julia_draw(env, &jul);
}
