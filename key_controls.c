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
	mlx_destroy_window(env->mlx, env->window);
	if (env->fractal == 2)
		ft_memdel((void **)&env->pent);
	exit(0);
}


void			mandel_controls(t_env *env, int keycode)
{

}

void			julia_control(t_env *env, int keycode)
{

}
void			phi_controls(t_env *env, int keycode)
{
	if (keycode == KEY_K)
		env->pent_interval += 0.003;
	printf("%f\n", env->pent_interval);
	printf("%f\n", -(PHI - 1.01));
	if (keycode == KEY_I && env->pent_interval >= -(PHI - 1.016))
		env->pent_interval -= 0.003;
	if (keycode == KEY_G)
		env->color_inc = 0;

}

int				mouse_controls(int keycode, t_env *env)
{

}

int				key_controls(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
		exit_fractol(env);
//	if (keycode == KEY_Z)
//		env->scale += 1;
//	if (env->fractal == 0)
//		julia_controls(env, keycode);
//	if (env->fractal == 1)
//		mandel_controls(env, keycode);
	if (env->fractal == 2)
		phi_controls(env, keycode);
	if (keycode == KEY_C)
		env->color_inc += 2000;
	if (keycode == KEY_V)
		env->color_inc -= 2000;
	env->reinit = true;
	reinit(env);
	return(0);
}
