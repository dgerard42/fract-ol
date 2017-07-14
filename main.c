/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 13:22:13 by dgerard           #+#    #+#             */
/*   Updated: 2017/07/04 13:22:30 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void			welcome_user(void)
{
	ft_putstr("welcome user (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧\n");
	ft_putstr("--------------command list-----------------\n");
	ft_putstr("ESC == exit program\nC == shift color palette\n");
	ft_putstr("---------------------------\nJulia set\n");
	ft_putstr("Use the mouse to manipulate the C value in the Julia set\n");
	ft_putstr("---------------------------\nMadelbrot fractal\n");
	ft_putstr("W == move up\nA == move left\n");
	ft_putstr("S == move right\nD == move down\nZ == zoom in\nX == zoom out\n");
	ft_putstr("---------------------------\nΦ pentagram fractal\n");
}

void			reinit(t_env *env)
{
//	mlx_clear_window(env->mlx, env->window);
	mlx_destroy_image(env->mlx, env->image);
	if (env->fractal == 0 || env->fractal == 1)
		fractal_gen(env);
	if (env->fractal == 2)
	{
		ft_memdel((void **)&env->pent);
		phi_gen(env);
	}
	mlx_new_image(env->mlx, WIN_HI, WIN_LEN);
}

void			handle_parameters(t_env *env, int argc, char *parameter)
{
	if (argc != 2)
	{
		ft_putstr("Error. Wrong number of parameters.\n");
		ft_putstr("Usage:  [julia] = Julia set\n\t");
		ft_putstr("[mandel] = Mandelbrot fractal\n\t[phi] = Φ fractal\n");
		exit(0);
	}
	if (ft_strequ(parameter, "julia"))
		env->fractal = 0;
	else if (ft_strequ(parameter, "mandel"))
		env->fractal = 1;
	else if (ft_strequ(parameter, "phi"))
		env->fractal = 2;
	else
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
	t_env phi;

	handle_parameters(&env, argc, argv[1]);
	env.mlx = mlx_init();
	env.image = mlx_new_image(env.mlx, WIN_LEN, WIN_HI);
	env.pixels = (int *)mlx_get_data_addr(env.image, &env.bits_per_pixel, &env.size_line, &env.endian);
	env.reinit = false;
	if (env.fractal == 0 || env.fractal == 1)
		fractal_gen(&env);
	if (env.fractal == 2)
		phi_gen(&env);
	mlx_put_image_to_window(env.mlx, env.window, env.image, 0, 0);
	welcome_user();
	//handles keys being held down
	mlx_hook(env.window, 2, 0, key_controls, (void *)&env);
	//handles mouse CLICK events
	mlx_mouse_hook(env.window, &mouse_controls, (void *)&env);
	//handles mouse MOVE events
	if (env.julia_move == true)
		mlx_hook(env.window, 6, 0, another_ft, (void *)&env);
	mlx_loop(env.mlx);
	return(0);
}
