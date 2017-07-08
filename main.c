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
	ft_putstr("welcome user ( ͡° ͜ʖ ͡°)\n");
	ft_putstr("--------------command list-----------------\n");
	ft_putstr("ESC == exit program\nC == shift color palette\n");
	ft_putstr("---------------------------\nJ == open Julia set\n");
	ft_putstr("Use the mouse to manipulate the C value in the Julia set\n");
	ft_putstr("---------------------------\nM == open Madelbrot fractal\n");
	ft_putstr("W == move up\nA == move left\n");
	ft_putstr("S == move right\nD == move down\nZ == zoom in\nX == zoom out\n");
	ft_putstr("---------------------------\nF == open Φ Pentagram fractal\n");
}

int				main(void)
{
	t_env env;

	env.mlx = mlx_init();
	env.reinit = false;
	welcome_user();
	env.window = mlx_new_window(env.mlx, WIN_LEN, WIN_HI, "hail satan");
	phi(&env);
//	mlx_hook(env.window, 2, 0, key_controls, (void *)&env);
	mlx_loop(env.mlx);
}
