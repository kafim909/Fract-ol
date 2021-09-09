/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:59:56 by mtournay          #+#    #+#             */
/*   Updated: 2021/09/09 16:05:42 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int	color_shift(t_data *vars)
{
	if (vars->color_shift < 100 && vars->color_min == 1)
	{
		vars->color_shift++;
		vars->color_min = 1;
		vars->color_max = 0;
	}
	if (vars->color_shift > 0 && vars->color_max == 1)
	{
		vars->color_shift--;
		vars->color_min = 0;
		vars->color_max = 1;
	}
	if (vars->color_shift == 100)
		vars->color_max = 1;
	if (vars->color_shift == 0)
		vars->color_min = 1;
	return (1);
}

int	instance(t_data *vars)
{
	if (vars->help_bol == 1)
		help_screen(vars);
	else
	{
		if (vars->mndl_set)
			mandelbrot_set(vars, vars->color_shift);
		if (vars->julia_set)
			julia_set(vars, vars->color_shift);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, 0, 0);
		mlx_string_put(vars->mlx, vars->mlx_win, vars->height / 20,
			vars->width / 20 - 20, 0xC7FFE0, "commands : h");
		mlx_string_put(vars->mlx, vars->mlx_win, vars->height / 20,
			vars->width / 2 + 50, 0xC7FFE0, "Iterations:");
		mlx_string_put(vars->mlx, vars->mlx_win, vars->height / 20 + 120,
			vars->width / 2 + 50, 0xC7FFE0, ft_itoa(vars->max_iterations));
		if (vars->color_bol == 1)
			color_shift(vars);
		if (vars->move_julia == 1)
			move_julia(vars);
	}
	mlx_hook(vars->mlx_win, 4, 0, zoom, vars);
	mlx_hook(vars->mlx_win, 2, 0, keyhook, vars);
	mlx_hook(vars->mlx_win, 17, 1L << 5, ft_close, vars);
	return (0);
}

int	fract_params(char **input, t_data *vars)
{
	if (!custom_comp(input[1], "julia", 5))
		 vars->julia_set = 1;
	else if (!custom_comp(input[1], "mandelbrot", 10))
		vars->mndl_set = 1;
	else
		return (0);
	return (1);
}

int	color_params(char **input, t_data *v)
{
	if (!custom_comp(input[2], "red", 3))
		v->red_param = 1;
	else if (!custom_comp(input[2], "blue", 4))
		v->blue_param = 1;
	else if (!custom_comp(input[2], "green", 5))
		v->green_param = 1;
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*vars;

	vars = malloc(sizeof(t_data));
	if (!vars)
		return (-1);
	vars->mndl = malloc(sizeof(t_set));
	if (!vars->mndl)
		return (-1);
	init_struct(vars);
	if (argc < 2 || !fract_params(argv, vars))
		return (printf("choose between julia and mandelbrot\n\n"));
	if (vars->mndl_set && argc < 3)
		return (printf("precise the base color : red, blue or green\n"));
	if (vars->mndl_set && !color_params(argv, vars))
		return (printf("please precise the base color : red, blue or green\n"));
	fracact_init(vars);
	mlx_loop_hook(vars->mlx, instance, vars);
	mlx_loop(vars->mlx);
}
