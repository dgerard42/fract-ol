/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 15:23:46 by dgerard           #+#    #+#             */
/*   Updated: 2017/07/06 15:23:49 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libs/minilibx/mlx.h"
# include "libs/libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>

# define WIN_HI				800
# define WIN_LEN			800

# define PHI				1.618033987498948482
# define KEY_ES				53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_X				7
# define KEY_Z				6
# define KEY_C				8
# define KEY_J				38
# define KEY_M				46
# define KEY_F				3

typedef	struct	s_env
{
	void	*mlx;
	void	*window;
	bool	reinit;
	int		scale;
}				t_env;

typedef	struct	s_phi
{
	float		*pent;
	float		s1;
	float		s2;
	float		c1;
	float		c2;
}				t_phi;

typedef	struct	s_drw
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			rise;
	int			run;
	int			slope;
	int			adjust;
	int			level;
	int			color;
}				t_drw;

void			phi(t_env *env);
int				key_controls(int keycode, t_env *env);
void			draw_line(t_env *env, t_drw *drw);

#endif
