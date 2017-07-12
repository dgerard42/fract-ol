/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:00:40 by dgerard           #+#    #+#             */
/*   Updated: 2017/07/06 17:00:43 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

/*
void				fractal_setup(t_env *env, t_frac *frac)
{

}
*/
void				fractal_draw(t_env *env, t_frac *frac)
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
			frac->color = 0xFF0000;
			frac->zRnew = (env->fractal == 0) ? (x - (WIN_LEN / 2)) / (WIN_LEN / 2 * env->scale) : 0;
			frac->zInew = (env->fractal == 0) ? (y - (WIN_HI / 2)) / (WIN_HI / 2 * env->scale) : 0;
			frac->cR = (env->fractal == 1) ? (x - (WIN_LEN / 2)) / (WIN_LEN / 3 * env->scale) : frac->cR;
			frac->cI = (env->fractal == 1) ? (y - (WIN_HI / 2)) / (WIN_HI / 3 * env->scale) : frac->cI;
			while (i < env->iterations && (frac->zRnew * frac->zRnew) + (frac->zInew * frac->zInew) < 4)
			{
				frac->zRold = frac->zRnew;
				frac->zIold = frac->zInew;
				frac->zRnew = (frac->zRold * frac->zRold) - (frac->zIold * frac->zIold) + frac->cR;
				frac->zInew = (2 * frac->zRold * frac->zIold) + frac->cI;
				frac->color += 1000;
				i++;
			}
			if (i == 300)
				frac->color = 0x000000;
			mlx_pixel_put(env->mlx, env->window, x++, y, frac->color);
		}
	}
}

void				fractal_gen(t_env *env)
{
	t_frac frac;

	env->iterations = 300;
	if (env->fractal == 0)
	{
		if (env->reinit == true)
		{
			frac.cR = 0;
			frac.cI = 0;
			env->scale = 1;
		}
		env->window = mlx_new_window(env->mlx, WIN_LEN, WIN_HI, "~ J U L I A ~");
	}
	if (env->fractal == 1)
	{
		env->scale = 1;
		env->window = mlx_new_window(env->mlx, WIN_LEN, WIN_HI, "~ M A N D E L B R O T ~");
	}
	fractal_draw(env, &frac);
}
