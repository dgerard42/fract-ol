/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:00:40 by dgerard           #+#    #+#             */
/*   Updated: 2017/07/06 17:00:43 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void				fractal_draw(t_env *env, t_mand *mand)
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
			mand->color = 0xFF0000;
			mand->zRnew = 0;
			mand->zInew = 0;
			mand->cR = (x - (WIN_LEN / 2)) / (WIN_LEN / 4);
			mand->cI = (y - (WIN_HI / 2)) / (WIN_HI / 4);
			while (i < 300 && (mand->zRnew * mand->zRnew) + (mand->zInew * mand->zInew) < 4)
			{
				mand->zRold = mand->zRnew;
				mand->zIold = mand->zInew;
				mand->zRnew = (mand->zRold * mand->zRold) - (mand->zIold * mand->zIold) + mand->cR;
				mand->zInew = (2 * mand->zRold * mand->zIold) + mand->cI;
				mand->color += 1000;
				i++;
			}
			if (i == 300)
				mand->color = 0x000000;
			mlx_pixel_put(env->mlx, env->window, x++, y, mand->color);
		}
	}
}

void				fractal_gen(t_env *env)
{
	t_mand mand;

//	mand.zRold = 0;
//	mand.zIold = 0;
	if (env->fractal == 0)
		env->window = mlx_new_window(env->mlx, WIN_LEN, WIN_HI, "~ J U L I A ~");
	if (env->fractal == 1)
		env->window = mlx_new_window(env->mlx, WIN_LEN, WIN_HI, "~ M A N D E L B R O T ~");
	mandel_draw(env, &);
}
