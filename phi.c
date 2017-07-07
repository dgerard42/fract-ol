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

void			setup(t_phi *phi)
{
	phi->pent = ft_floatarraynew(10);
	phi->pent[0] = 0;
	phi->pent[1] = 1;
	phi->s1 = sin((2 * M_PI) / 5);
	phi->s2 = sin((4 * M_PI) / 5);
	phi->c1 = cos((2 * M_PI) / 5);
	phi->c2 = cos(M_PI / 5);
}

void			new_pent(t_phi *phi)
{
	phi->pent[2] = s1 * abs(p1y);
	phi->pent[3] = c1 * abs(p1y);
	//here, when you multiply by abs(p1y) you will need to start drawing p1 flipped
	//into the negative every other time
	//the radius of the unit circle that you are drawing the pentagon within.
	phi->pent[4] = s2 * abs(p1y);
	phi->pent[5] = -c2 * abs(p1y);
	phi->pent[6] = -s2 * abs(p1y);
	phi->pent[7] = -c2 * abs(p1y);
	phi->pent[8] = -s1 * abs(p1y);
	phi->pent[9] = c1 * abs(p1y);
}

void			draw(t_env *env, t_phi *phi, t_drw *drw)
{
	t_drw	drw;
	int		i;

	i = 0;
	while (i < 10)
	{
		drw->x0 = phi->pent[i];
		drw->y0 = phi->pent[i + 1];
		drw->x1 = phi->pent[i + 2];
		drw->y1 = phi->pent[i + 3];
		draw_line(env, &drw);
		i += 4;
	}
	
}

void			phi(t_env *env)
{
	t_phi phi;

	setup(&phi);
	while (the points of the largest pentagon are within 400 pixels beyond the border of the window)
	{
		dr
		//i +=  distance btween p1 & p2 / PHI;
	}
}
