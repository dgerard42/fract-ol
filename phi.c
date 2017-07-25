/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 18:18:20 by dgerard           #+#    #+#             */
/*   Updated: 2017/07/24 17:01:38 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				phi_setup(t_env *env, t_phi *phi, t_drw *drw)
{
	if (env->reinit == false)
	{
		env->window = mlx_new_window(env->mlx, WIN_LEN, WIN_HI, "P   H   I");
		env->pent_interval = 0.22;
		env->color_inc = 200;
	}
	phi->s1 = sin((2 * M_PI) / 5);
	phi->s2 = sin((4 * M_PI) / 5);
	phi->c1 = cos((2 * M_PI) / 5);
	phi->c2 = cos(M_PI / 5);
	phi->inverse = false;
	env->pent = ft_floatarraynew(12);
	env->pent[0] = 0;
	env->pent[1] = 1 * 8;
	drw->color = (env->color_inc == 0) ? 0x00FF00 : 0xFF0000;
}

void				new_pent(t_env *env, t_phi *phi)
{
	int rad;

	rad = fabsf(env->pent[1]);
	env->pent[2] = (phi->inverse == false) ? phi->s1 * rad : -(phi->s1) * rad;
	env->pent[3] = (phi->inverse == false) ? phi->c1 * rad : -(phi->c1) * rad;
	env->pent[4] = (phi->inverse == false) ? phi->s2 * rad : -(phi->s2) * rad;
	env->pent[5] = (phi->inverse == false) ? -(phi->c2) * rad : phi->c2 * rad;
	env->pent[6] = (phi->inverse == false) ? -(phi->s2) * rad : phi->s2 * rad;
	env->pent[7] = (phi->inverse == false) ? -(phi->c2) * rad : phi->c2 * rad;
	env->pent[8] = (phi->inverse == false) ? -(phi->s1) * rad : phi->s1 * rad;
	env->pent[9] = (phi->inverse == false) ? phi->c1 * rad : -(phi->c1) * rad;
	env->pent[10] = env->pent[0];
	env->pent[11] = env->pent[1];
}

void				draw_pentagram(t_env *env, t_phi *phi, t_drw *drw)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = i + 4;
		while (j < (i + 8) && j < 10)
		{
			drw->x0 = (int)env->pent[i] + (WIN_LEN / 2);
			drw->y0 = (int)env->pent[i + 1] + (WIN_HI / 2);
			drw->x1 = (int)env->pent[j] + (WIN_LEN / 2);
			drw->y1 = (int)env->pent[j + 1] + (WIN_HI / 2);
			draw_line(env, drw);
			j += 2;
		}
		i += 2;
	}
}

void				draw_pentagon(t_env *env, t_phi *phi, t_drw *drw)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		drw->x0 = (int)env->pent[i] + (WIN_LEN / 2);
		drw->y0 = (int)env->pent[i + 1] + (WIN_HI / 2);
		drw->x1 = (int)env->pent[i + 2] + (WIN_LEN / 2);
		drw->y1 = (int)env->pent[i + 3] + (WIN_HI / 2);
		draw_line(env, drw);
		i += 2;
	}
	draw_pentagram(env, phi, drw);
}

void				phi_gen(t_env *env)
{
	t_phi	phi;
	t_drw	drw;
	float	delta_x;
	float	increase;
	int		i;

	i = 1;
	phi_setup(env, &phi, &drw);
	while (env->pent[1] < (WIN_HI + 200))
	{
		new_pent(env, &phi);
		draw_pentagon(env, &phi, &drw);
		i++;
		drw.color += env->color_inc;
		delta_x = fabsf(env->pent[6] - env->pent[4]);
		increase = sqrt(pow((PHI + env->pent_interval) * delta_x, 2)
			- pow((delta_x + env->pent_interval / 2), 2));
		env->pent[1] = fabsf(env->pent[5]) + increase;
		phi.inverse = false;
		if (i % 2 == 0)
		{
			env->pent[1] = -env->pent[1];
			phi.inverse = true;
		}
	}
}
