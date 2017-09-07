/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 13:22:13 by dgerard           #+#    #+#             */
/*   Updated: 2017/08/28 12:26:36 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			welcome_user(void)
{
	ft_putstr("welcome user (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧\n");
	ft_putstr("--------------universal commands-----------------\n");
	ft_putstr("ESC == exit program\nC == + color increase per iteration\n");
	ft_putstr("V == - color increase per iteration\n");
	ft_putstr("I == + iterations\nK == - iterations\n");
	ft_putstr("---------------------------\n~ J U L I A  S E T ~\n");
	ft_putstr("use the mouse to manipulate the c value in the julia set\n");
	ft_putstr("F == fix the current c value / restore movement\n");
	ft_putstr("W == up\nA == left\nS == down\nD == right\n");
	ft_putstr("MOUSE WHEEL == zoom\n");
	ft_putstr("---------------------------\n~ M A N D E L B R O T ~\n");
	ft_putstr("W == up\nA == left\nS == down\nD == right\n");
	ft_putstr("MOUSE WHEEL == zoom\n");
	ft_putstr("---------------------------\n~ Φ PENTAGRAM FRACTAL ~\n");
	ft_putstr("I == + volume of pentagrams\nK == - volume of pentagrams\n");
	ft_putstr("G == turn on green only lines\n");
}

void			reinit(t_env *env)
{
	if (env->reinit == true)
	{
		if (env->fractal == 0 || env->fractal == 1)
			mlx_destroy_image(env->mlx, env->image);
		if (env->fractal == 2)
		{
			mlx_clear_window(env->mlx, env->window);
			ft_memdel((void **)&env->pent);
		}
	}
	if (env->fractal == 0 || env->fractal == 1)
	{
		env->image = mlx_new_image(env->mlx, WIN_HI, WIN_LEN);
		env->pixels = (int *)mlx_get_data_addr(env->image, &env->bits_per_pixel,
			&env->size_line, &env->endian);
		fractal_gen(env);
		mlx_put_image_to_window(env->mlx, env->window, env->image, 0, 0);
	}
	if (env->fractal == 2)
		phi_gen(env);
}

void			handle_parameters(t_env *env, int argc, char **parameters)
{
	env->fractal = 42;
	if (parameters[1])
	{
		if (ft_strequ(parameters[1], "julia"))
			env->fractal = 0;
		else if (ft_strequ(parameters[1], "mandel"))
			env->fractal = 1;
		else if (ft_strequ(parameters[1], "phi"))
			env->fractal = 2;
	}
	if (argc != 2 || env->fractal == 42)
	{
		ft_putstr("Error. Invalid input.\n");
		ft_putstr("Usage:  [julia] = Julia set\n\t");
		ft_putstr("[mandel] = Mandelbrot fractal\n\t[phi] = Φ fractal\n");
		exit(0);
	}
}

int				main(int argc, char **argv)
{
	t_env env;

	handle_parameters(&env, argc, argv);
	env.mlx = mlx_init();
	env.reinit = false;
	reinit(&env);
	welcome_user();
	mlx_hook(env.window, 2, 0, key_controls, (void *)&env);
	mlx_mouse_hook(env.window, &mouse_controls, (void *)&env);
	mlx_hook(env.window, 6, 0, another_ft, (void *)&env);
	mlx_loop(env.mlx);
	return (0);
}
