/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:00:40 by dgerard           #+#    #+#             */
/*   Updated: 2017/07/24 17:00:18 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				complex_nums(t_env *env, t_frac *frac, double x, double y)
{
	frac->color = 0x0FFFFFF;
	frac->zrnew = (env->fractal == 0) ?
		(x - (WIN_LEN / 2)) / (WIN_LEN / 4 + env->scale) + env->x_displace : 0;
	frac->zinew = (env->fractal == 0) ?
		(y - (WIN_HI / 2)) / (WIN_HI / 4 + env->scale) + env->y_displace : 0;
	frac->cr = (env->fractal == 1) ?
		(x - (WIN_LEN / 2)) / (WIN_LEN / 4 + env->scale) + env->x_displace :
			frac->cr;
	frac->ci = (env->fractal == 1) ?
		(y - (WIN_HI / 2)) / (WIN_HI / 4 + env->scale) + env->y_displace :
			frac->ci;
}

void				apply_function(t_env *env, t_frac *frac)
{
	frac->zrold = frac->zrnew;
	frac->ziold = frac->zinew;
	frac->zrnew = (frac->zrold * frac->zrold) -
		(frac->ziold * frac->ziold) + frac->cr;
	frac->zinew = (2 * frac->zrold * frac->ziold) + frac->ci;
	frac->color += env->color_inc;
}

void				fractal_draw(t_env *env, t_frac *frac)
{
	int		i;
	double	x;
	double	y;

	y = -1;
	while (y++ < (WIN_HI - 1))
	{
		x = 0;
		while (x < WIN_LEN)
		{
			i = 0;
			complex_nums(env, frac, x, y);
			while (i++ < env->iterations &&
				(frac->zrnew * frac->zrnew) + (frac->zinew * frac->zinew) < 4)
				apply_function(env, frac);
			if (i == (env->iterations + 1))
				frac->color = 0x000000;
			env->pixels[(int)x++ + ((int)y * WIN_LEN)] = frac->color;
		}
	}
}

void				fractal_gen(t_env *env)
{
	t_frac frac;

	if (env->reinit == false)
	{
		env->scale = 1;
		env->iterations = 50;
		env->x_displace = 0;
		env->y_displace = 0;
		env->color_inc = 62200;
		if (env->fractal == 0)
		{
			env->color_inc = 460300;
			env->julia_move = true;
			env->window = mlx_new_window(env->mlx, WIN_LEN, WIN_HI, JULIA);
		}
		if (env->fractal == 1)
			env->window = mlx_new_window(env->mlx, WIN_LEN, WIN_HI, MANDEL);
	}
	if (env->fractal == 0)
	{
		frac.cr = ((double)(env->mouse_x) - (WIN_LEN / 2)) / 800;
		frac.ci = ((double)(env->mouse_y) - (WIN_HI / 2)) / 800;
	}
	fractal_draw(env, &frac);
}
