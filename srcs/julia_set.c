/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:27:22 by mtournay          #+#    #+#             */
/*   Updated: 2021/09/09 13:24:22 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int	move_julia_opti(t_data *vars)
{
	if (vars->mndl->cIm < -0.3 || vars->mndl->cIm > 0.3)
		vars->max_iterations = 150;
	if (vars->mndl->cIm < -0.35 || vars->mndl->cIm > 0.35)
		vars->max_iterations = 3000;
	if ((vars->mndl->cIm < -0.27 && vars->mndl->cIm > -0.3)
		|| (vars->mndl->cIm > 0.27 && vars->mndl->cIm < 0.3))
		vars->max_iterations = 75;
	if ((vars->mndl->cIm < -0.25 && vars->mndl->cIm > -0.27)
		|| (vars->mndl->cIm > 0.25 && vars->mndl->cIm < 0.27))
		vars->max_iterations = 50;
	if (vars->mndl->cIm > -0.25 && vars->mndl->cIm < 0.25)
		vars->max_iterations = 20;
	return (1);
}

int	move_julia(t_data *vars)
{
	if (vars->mndl->cIm < 1.0000 && vars->julia_min == 1)
	{
		vars->mndl->cIm += 0.005;
		vars->julia_min = 1;
		vars->julia_max = 0;
	}
	if (vars->mndl->cIm > -1.00000 && vars->julia_max == 1)
	{
		vars->mndl->cIm -= 0.005;
		vars->julia_min = 0;
		vars->julia_max = 1;
	}
	if (vars->mndl->cIm >= 1.0000)
		vars->julia_max = 1;
	if (vars->mndl->cIm <= -1.0000)
		vars->julia_min = 1;
	move_julia_opti(vars);
	return (1);
}

void	julia_core_x(t_data *v, int i, int color_shift)
{
	v->mndl->oldRe = v->mndl->newRe;
	v->mndl->oldIm = v->mndl->newIm;
	v->mndl->newRe = pow(v->mndl->oldRe, 2)
		- pow(v->mndl->oldIm, 2) + v->mndl->cRe;
	v->mndl->newIm = 2 * v->mndl->oldRe * v->mndl->oldIm + v->mndl->cIm;
	if (i <= v->max_iterations / 2 && i)
		v->red += i + color_shift;
	if (i <= v->max_iterations / 2 && i)
		v->green += i + color_shift / 2;
	if (i <= v->max_iterations && i)
		v->blue += i + color_shift;
}

void	julia_core_y(t_data*v, int i, int color_shift)
{
	v->mndl->x = 0;
	while (v->mndl->x < v->width)
	{
		init_color(v);
		v->mndl->newRe = 1.5 * (v->mndl->x - v->width / 2)
			/ (0.5 * v->zoom * v->width) + v->moveX;
		v->mndl->newIm = (v->mndl->y - v->height / 2)
			/ (0.5 * v->zoom * v->height) + v->moveY;
		i = 0;
		while (++i < v->max_iterations && (pow(v->mndl->newRe, 2)
				+ pow(v->mndl->newIm, 2)) < 4.0)
			julia_core_x(v, i, color_shift);
		v->color = create_trgb(v->transparency, v->red, v->green, v->blue);
		v->mndl->x++;
		if ((v->mndl->newRe * v->mndl->newRe
				+ v->mndl->newIm * v->mndl->newIm) < 4.0)
			my_mlx_pixel_put(v, v->mndl->x, v->mndl->y, 0x000000);
		else
			my_mlx_pixel_put(v, v->mndl->x, v->mndl->y, v->color);
	}
}

int	julia_set(t_data *v, int color_shift)
{
	int	i;

	i = 0;
	v->mndl->y = 0;
	while (v->mndl->y < v->height)
	{
		julia_core_y(v, i, color_shift);
		v->mndl->y++;
	}	
	return (1);
}
