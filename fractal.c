/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:00:40 by dgerard           #+#    #+#             */
/*   Updated: 2017/07/13 11:00:00 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void				fractal_draw(t_env *env, t_frac *frac)
{
	int i;
	double x;
	double y;

	y = -1;
	while (y++ < (WIN_HI - 1))
	{
		x = 0;
		while (x < WIN_LEN)
		{
			i = 0;
			frac->color = 0x0FFFFFF;
			frac->zRnew = (env->fractal == 0) ? (x - (WIN_LEN / 2)) / (WIN_LEN / 4 + env->scale) + env->x_displace : 0;
			frac->zInew = (env->fractal == 0) ? (y - (WIN_HI / 2)) / (WIN_HI / 4 + env->scale) + env->y_displace : 0;
			frac->cR = (env->fractal == 1) ? (x - (WIN_LEN / 2)) / (WIN_LEN / 4 + env->scale) + env->x_displace : frac->cR;
			frac->cI = (env->fractal == 1) ? (y - (WIN_HI / 2)) / (WIN_HI / 4 + env->scale) + env->y_displace : frac->cI;
			while (i < env->iterations && (frac->zRnew * frac->zRnew) + (frac->zInew * frac->zInew) < 4)
			{
				frac->zRold = frac->zRnew;
				frac->zIold = frac->zInew;
				frac->zRnew = (frac->zRold * frac->zRold) - (frac->zIold * frac->zIold) + frac->cR;
				frac->zInew = (2 * frac->zRold * frac->zIold) + frac->cI;
				frac->color += env->color_inc;
				i++;
			}
			if (i == env->iterations)
				frac->color = 0x000000;
	//		printf("%f\n", x);
	//		printf("%d\n",(int)x + ((int)y * WIN_LEN));
			env->pixels[(int)x + ((int)y * WIN_LEN)] = frac->color;
			x++;
	//		mlx_pixel_put(env->mlx, env->window, x++, y, frac->color);
	//		mlx_string_put(env->mlx, env->window, 20, WIN_HI - 20, 0xFFFFFF0, ft_itoa(frac->cR * 100000));
	//		mlx_string_put(env->mlx, env->window, 20, WIN_HI - 20, 0xFFFFFF0, "cool");
		}
	}
//	printf("here2\n");
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
	}
	if (env->fractal == 0)
	{
		frac.cR = ((double)(env->mouse_x) - (WIN_LEN / 2)) / 800;
		frac.cI = ((double)(env->mouse_y) - (WIN_HI / 2)) / 800;
//		printf("%d\n", env->mouse_x);
//		printf("%d\n", env->mouse_y);
//		printf("%f\n", frac.cR);
//		printf("%f\n", frac.cI);
		if (env->reinit == false)
		{
			frac.cR = .28;
			frac.cI = .008;
			env->color_inc = 460300;
			env->julia_move = true;
			env->window = mlx_new_window(env->mlx, WIN_LEN, WIN_HI, "J   U   L   I   A");
		}
	}
	if (env->fractal == 1 && env->reinit == false)
	{
		env->color_inc = 62200;
		env->window = mlx_new_window(env->mlx, WIN_LEN, WIN_HI, "M   A   N   D   E   L   B   R   O   T");
	}
	fractal_draw(env, &frac);
}
