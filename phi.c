/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 18:18:20 by dgerard           #+#    #+#             */
/*   Updated: 2017/07/08 18:56:24 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void				phi_setup(t_env *env, t_phi *phi)
{
	if (env->reinit == false)
	{
		env->window = mlx_new_window(env->mlx, WIN_LEN, WIN_HI, "Φ");
		phi->pent = ft_floatarraynew(12);
		phi->inverse = false;
//		phi->displace = 1;
		env->scale = 8;
		phi->s1 = sin((2 * M_PI) / 5);
		phi->s2 = sin((4 * M_PI) / 5);
		phi->c1 = cos((2 * M_PI) / 5);
		phi->c2 = cos(M_PI / 5);
	}
	phi->pent[0] = 0;
	phi->pent[1] = 1 * env->scale;
}

void				new_pent(t_env *env, t_phi *phi)
{
	int rad;

	rad = fabsf(phi->pent[1]);
	phi->pent[2] = (phi->inverse == false) ? phi->s1 * rad : -(phi->s1) * rad;
	phi->pent[3] = (phi->inverse == false) ? phi->c1 * rad : -(phi->c1) * rad;
	phi->pent[4] = (phi->inverse == false) ? phi->s2 * rad : -(phi->s2) * rad;
	phi->pent[5] = (phi->inverse == false) ? -(phi->c2) * rad : phi->c2 * rad;
	phi->pent[6] = (phi->inverse == false) ? -(phi->s2) * rad : phi->s2 * rad;
	phi->pent[7] = (phi->inverse == false) ? -(phi->c2) * rad : phi->c2 * rad;
	phi->pent[8] = (phi->inverse == false) ? -(phi->s1) * rad : phi->s1 * rad;
	phi->pent[9] = (phi->inverse == false) ? phi->c1 * rad : -(phi->c1) * rad;
	phi->pent[10] = phi->pent[0];
	phi->pent[11] = phi->pent[1];
}

void				draw_pent(t_env *env, t_phi *phi, t_drw *drw)
{
	int		i;
	int		j;

	i = 0;
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

void				phi(t_env *env)
{
	t_phi	phi;
	t_drw	drw;
	float	delta_x;
	float	increase;
	int		i;

	i = 1;
	phi_setup(env, &phi);
	drw.color = 0x00FF00;
	while (phi.pent[1] < (WIN_HI + 200))
	{
		new_pent(env, &phi);
		draw_pent(env, &phi, &drw);
		i++;
		delta_x = fabsf(phi.pent[6] - phi.pent[4]);
//		printf("delta_x=%f\n", delta_x);
		increase = sqrt(pow(PHI * delta_x, 2) - pow((delta_x / 2), 2));
//		printf("increase=%f\n", increase);
		phi.pent[1] = fabsf(phi.pent[5]) + increase + phi.displace;
		drw.color = 0x00FF00;
		phi.inverse = false;
		if (i % 2 == 0)
		{
			phi.pent[1] = -phi.pent[1];
			drw.color = 0x0000FF;
			phi.inverse = true;
		}
//		printf("phi.pent[1]=%f\n", phi.pent[1]);
	}
}
