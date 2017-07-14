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

# define WIN_HI				1200
# define WIN_LEN			1200
# define PHI				1.618033987
## define PENT_RATIO		ft_itoa(((PHI + env->pent_interval) * 100000000) - 100000000);

# define KEY_ESC			53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_K              40
# define KEY_I              34
# define KEY_G              5
# define KEY_C				8
# define KEY_V				9
# define KEY_F				3

typedef	struct	s_env
{
	void	*mlx;
	void	*window;
	void	*image;
	int		*pixels;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	bool	reinit;
	int		fractal;
	int		color_inc;
	int		iterations;
	int		mouse_x;
	int		mouse_y;
	bool	julia_move;
	double	scale;
	double	x_displace;
	double	y_displace;
	float	*pent;
	float	pent_interval;
}				t_env;

typedef	struct	s_frac
{
	double	cR;
	double	cI;
	double	zRnew;
	double	zInew;
	double	zRold;
	double	zIold;
	int		color;
}				t_frac;

typedef	struct	s_phi
{
	float		s1;
	float		s2;
	float		c1;
	float		c2;
	bool		inverse;
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

void			fractal_gen(t_env *env);
void			phi_gen(t_env *env);
int				key_controls(int keycode, t_env *env);
int				mouse_controls(int keycode, int x, int y, t_env *env);
int				another_ft(int x, int y, t_env *env);
void			draw_line(t_env *env, t_drw *drw);
void			reinit(t_env *env);

#endif
