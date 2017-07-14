/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 16:49:09 by dgerard           #+#    #+#             */
/*   Updated: 2017/07/06 16:49:11 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void				exit_fractol(t_env *env)
{
//	mlx_destroy_image(env->mlx, env->image);
	mlx_destroy_window(env->mlx, env->window);
	if (env->fractal == 2)
		ft_memdel((void **)&env->pent);
	exit(0);
}

void			fractal_controls(t_env *env, int keycode)
{
	if (keycode == KEY_I)
		env->iterations += 10;
	if (keycode == KEY_K)
		env->iterations -= 10;
	if (keycode == KEY_W)
		env->y_displace += (0.05 / (env->scale / 1000));
	if (keycode == KEY_A)
		env->x_displace -= (0.05 / (env->scale / 1000));
	if (keycode == KEY_S)
		env->y_displace -= (0.05 / (env->scale / 1000));
	if (keycode == KEY_D)
		env->x_displace += (0.05 / (env->scale / 1000));
	if (keycode == KEY_F)
		env->julia_move = (env->julia_move == true) ? false : true;
}

int				another_ft(int x, int y, t_env *env)
{
	env->mouse_x = x;
	env->mouse_y = y;
	//	printf("x = %d ", x);
	//	printf("y = %d\n", y);
	env->reinit = true;
	reinit(env);
	return(0);
}

int				mouse_controls(int keycode, int x, int y, t_env *env)
{
	(void)x;
	(void)y;

//	printf("keycode = %d ", keycode);
//	printf("x = %d ", x);
//	printf("y = %d\n", y);
//	printf("%d\n", keycode);
	if (keycode == 4)
		env->scale += env->scale + 10;
	if (keycode == 5)
		env->scale -= (env->scale + 10);
	if (keycode == 4 || keycode == 5)
	{
		env->reinit = true;
		reinit(env);
	}
	return(0);
}

int				key_controls(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
		exit_fractol(env);
	if (env->fractal == 0 || env->fractal == 1)
		fractal_controls(env, keycode);
	if (env->fractal == 2)
	{
		if (keycode == KEY_K)
			env->pent_interval += (env->pent_interval > -0.5) ? 0.003 : 0.0003;
	//	printf("%f\n", env->pent_interval);
	//	printf("%f\n", -(PHI - 1.01));
		if (keycode == KEY_I && env->pent_interval >= -(PHI - 1.0131))
			env->pent_interval -= (env->pent_interval > -0.5) ? 0.003 : 0.0003;
		if (keycode == KEY_G)
			env->color_inc = 0;
	}
	if (keycode == KEY_C)
		env->color_inc += (env->color_inc > 100000) ? 20000 : 2000;
//	printf("%d\n", env->color_inc);
	if (keycode == KEY_V)
		env->color_inc -= 2000;
	env->reinit = true;
	reinit(env);
	return(0);
}
