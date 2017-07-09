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
	ft_memdel((void **)&phi->pent);
	exit(0);
}

int				key_controls(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
		exit_fractol(env);
	if (keycode == KEY_Z)
		phi->displace += 1;
	env->reinit = true;
	reinit(env);
	return(0);
}
