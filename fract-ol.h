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

# define KEY_ESC			53
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
}				t_env;

#endif
