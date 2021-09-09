/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:20:08 by mtournay          #+#    #+#             */
/*   Updated: 2021/09/09 13:14:06 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int	keyhook_2(int keycode, t_data *v)
{
	if (keycode == 47)
		v->max_iterations += 50;
	if (keycode == 43)
		v->max_iterations -= 50;
	if (keycode == 17)
		v->color_bol = 1;
	if (keycode == 16)
		v->color_bol = 0;
	if (keycode == 35)
		v->move_julia = 1;
	if (keycode == 31)
		v->move_julia = 0;
	if (keycode == 46)
		v->mndl->cRe += 0.05;
	if (keycode == 45)
		v->mndl->cRe -= 0.05;
	if (v->mndl_set)
		mandelbrot_set_matrix(v);
	return (0);
}

int	keyhook(int keycode, t_data *v)
{
	if (keycode == 53)
	{
		free(v->mndl);
		free(v);
		exit(1);
	}
	if (keycode == 4)
		v->help_bol = 1;
	if (keycode == 38)
		v->help_bol = 0;
	if (keycode == 123)
		v->moveX -= 0.2 / v->zoom;
	if (keycode == 124)
		v->moveX += 0.2 / v->zoom;
	if (keycode == 125)
		v->moveY += 0.2 / v->zoom;
	if (keycode == 126)
		v->moveY -= 0.2 / v->zoom;
	keyhook_2(keycode, v);
	return (0);
}

int	ft_close(t_data *vars)
{
	free(vars->mndl);
	free(vars);
	exit(1);
	return (0);
}

int	zoom(int button, int x, int y, t_data *v)
{
	(void)x;
	(void)y;
	if (button == 5)
		v->zoom *= 1.1;
	if (button == 4)
		v->zoom *= 0.9;
	if (v->mndl_set)
		mandelbrot_set_matrix(v);
	return (1);
}
