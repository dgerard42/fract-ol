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

}

int				key_controls(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
		exit_fractol(env);
	if (keycode == KEY_Z)
		env->scale += 1;
	if (env->fractal == 0)
		julia_controls(env, keycode);
	if (env->fractal == 1)
		mandel_controls(env, keycode);
	if (env->fractal == 2)
		phi_controls(env, keycode);
	env->reinit = true;
	reinit(env);
	return(0);
}
