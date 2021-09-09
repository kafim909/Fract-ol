/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:29:21 by mtournay          #+#    #+#             */
/*   Updated: 2021/09/09 16:16:13 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	mandel_core_4(t_data *v, int i)
{
	if (i <= v->max_iterations / 4 && i)
		v->red += i;
	if (i <= v->max_iterations / 2 && i)
		v->green += i;
	if (i <= v->max_iterations && i)
		v->blue += i;
	v->color = create_trgb(v->transparency, v->red, v->green, v->blue);
	v->mndl->x++;
	if ((v->mndl->newRe * v->mndl->newRe + v->mndl->newIm * v->mndl->newIm) < 4)
		my_mlx_pixel_put(v, v->mndl->x, v->mndl->y, 0x000000);
	else
		my_mlx_pixel_put(v, v->mndl->x, v->mndl->y, v->color);
}

void	mandel_core_3(t_data *v, int color_shift, int i)
{
	if (i <= v->max_iterations / 5)
	{
		if (v->red_param)
			v->red += color_shift;
		if (v->blue_param)
			v->blue += color_shift;
		if (v->green_param)
			v->green += color_shift;
	}
}

void	mandel_core_2(t_data *v)
{
	v->mndl->oldRe = v->mndl->newRe;
	v->mndl->oldIm = v->mndl->newIm;
	v->mndl->newRe = v->mndl->oldRe * v->mndl->oldRe
		- v->mndl->oldIm * v->mndl->oldIm + v->mndl->pr;
	v->mndl->newIm = 2 * v->mndl->oldRe * v->mndl->oldIm + v->mndl->pi;
}

void	mandel_core_1(t_data *v)
{
	v->mndl->pr = 1.5 * (v->mndl->x - v->width / 2)
		/ (0.5 * v->zoom * v->width) + v->moveX;
	v->mndl->pi = (v->mndl->y - v->height / 2)
		/ (0.5 * v->zoom * v->height) + v->moveY;
	v->mndl->oldIm = 0;
	v->mndl->oldRe = v->mndl->oldIm;
	v->mndl->newIm = v->mndl->oldRe;
	v->mndl->newRe = v->mndl->newIm;
}

int	mandelbrot_set(t_data *v, int color_shift)
{
	int	i;

	v->mndl->y = 0;
	while (v->mndl->y < v->height)
	{
		v->mndl->x = 0;
		while (v->mndl->x < v->width)
		{
			init_color(v);
			mandel_core_1(v);
			i = -1;
			while (++i < v->max_iterations && (v->mndl->newRe * v->mndl->newRe
					+ v->mndl->newIm * v->mndl->newIm) < 4
				&& v->matrix[v->mndl->y][v->mndl->x])
			{
				mandel_core_2(v);
				mandel_core_3(v, color_shift, i);
			}
			mandel_core_4(v, i);
		}	
		v->mndl->y++;
	}	
	return (1);
}
