/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:23:56 by mtournay          #+#    #+#             */
/*   Updated: 2021/09/09 13:16:14 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	init_struct_2(t_data *vars)
{
	vars->moveX = 0;
	vars->moveY = 0;
	vars->mndl->x = 0;
	vars->mndl->y = 0;
	vars->scale_min = 0;
	vars->color_shift = 1;
	vars->color_max = 0;
	vars->color_min = 1;
	vars->bol_img1 = 0;
	vars->transparency = 0;
	vars->help_bol = 0;
	vars->red_param = 0;
	vars->blue_param = 0;
	vars->green_param = 0;
	vars->height = 720.0;
	vars->width = 1280.0;
}

void	init_struct(t_data *vars)
{
	vars->mndl_set = 0;
	vars->julia_set = 0;
	vars->mndl->cRe = 0.5;
	vars->mndl->cIm = -0.2;
	vars->move_julia = 0;
	vars->julia_max = 0;
	vars->julia_min = 1;
	vars->max_iterations = 500;
	vars->zoom = 1;
	vars->color_bol = 0;
	init_struct_2(vars);
}

void	my_mlx_init(t_data *vars)
{
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, 1280, 720, "Hello world!");
	vars->img = mlx_new_image(vars->mlx, vars->width, vars->height);
	vars->addr = mlx_get_data_addr(vars->img,
			&vars->bits_per_pixel, &vars->line_length,
			&vars->endian);
}

void	fracact_init(t_data *vars)
{
	if (vars->mndl_set == 1)
		vars->moveX = -0.5;
	my_mlx_init(vars);
	if (vars->mndl_set)
		mandelbrot_set_matrix(vars);
	if (vars->julia_set)
		julia_set_matrix(vars);
}

void	init_color(t_data *v)
{
	v->color = 0;
	v->red = 0;
	v->green = 0;
	v->blue = 0;
}
