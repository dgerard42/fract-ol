/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 18:18:20 by dgerard           #+#    #+#             */
/*   Updated: 2017/07/06 18:18:27 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void			phi_setup(t_env *env, t_phi *phi)
{
	phi->pent = ft_floatarraynew(12);
	env->scale = 42;
	phi->pent[0] = 0 * env->scale;
	phi->pent[1] = 1 * env->scale;
	phi->s1 = sin((2 * M_PI) / 5);
	phi->s2 = sin((4 * M_PI) / 5);
	phi->c1 = cos((2 * M_PI) / 5);
	phi->c2 = cos(M_PI / 5);
}

void			new_pent(t_env *env, t_phi *phi)
{
	phi->pent[2] = phi->s1 * fabsf(phi->pent[1]);
	phi->pent[3] = phi->c1 * fabsf(phi->pent[1]);
	//here, when you multiply by fabsf(phi->pent[1]) you will need to start drawing p1 flipped
	//into the negative every other time
	//the radius of the unit circle that you are drawing the pentagon within.
	phi->pent[4] = phi->s2 * fabsf(phi->pent[1]);
	phi->pent[5] = -(phi->c2) * fabsf(phi->pent[1]);
	phi->pent[6] = -(phi->s2) * fabsf(phi->pent[1]);
	phi->pent[7] = -(phi->c2) * fabsf(phi->pent[1]);
	phi->pent[8] = -(phi->s1) * fabsf(phi->pent[1]);
	phi->pent[9] = phi->c1 * fabsf(phi->pent[1]);
	phi->pent[10] = phi->pent[0];
	phi->pent[11] = phi->pent[1];
}

void			draw_pent(t_env *env, t_phi *phi, t_drw *drw)
{
	int		i;
	int		j;

	i = 0;
	drw->color = 0x00FF00;
	while (i < 10)
	{
		drw->x0 = (int)phi->pent[i] + (WIN_LEN / 2);
		drw->y0 = (int)phi->pent[i + 1] + (WIN_HI / 2);
		drw->x1 = (int)phi->pent[i + 2] + (WIN_LEN / 2);
		drw->y1 = (int)phi->pent[i + 3] + (WIN_HI / 2);
		draw_line(env, drw);
		i += 2;
	}
	i = 0;
	while (i < 6)
	{
		j = i + 4;
		while (j < (i + 8) && j < 10)
		{
			drw->x0 = (int)phi->pent[i] + (WIN_LEN / 2);
			drw->y0 = (int)phi->pent[i + 1] + (WIN_HI / 2);
			drw->x1 = (int)phi->pent[j] + (WIN_LEN / 2);
			drw->y1 = (int)phi->pent[j + 1] + (WIN_HI / 2);
//			printf("i = %d, j = %d\n", i, j);
//			printf("x0=%d, y0=%d, x1=%d, y1=%d\n", drw->x0, drw->y0, drw->x1, drw->y1);
			draw_line(env, drw);
			j += 2;
		}
		i += 2;
	}
}

void			phi(t_env *env)
{
	t_phi	phi;
	t_drw	drw;

	phi_setup(env, &phi);
	new_pent(env, &phi);
	draw_pent(env, &phi, &drw);
}
