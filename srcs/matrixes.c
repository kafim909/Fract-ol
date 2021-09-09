/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:27:31 by mtournay          #+#    #+#             */
/*   Updated: 2021/09/09 16:32:35 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int	mandelbrot_set_matrix(t_data *v)
{
	int	i;

	v->mndl->y = 0;
	while (v->mndl->y < v->height)
	{
		v->mndl->x = 0;
		while (v->mndl->x < v->width)
		{
			mandel_core_1(v);
			i = -1;
			while (++i < v->max_iterations && (v->mndl->newRe
					* v->mndl->newRe + v->mndl->newIm * v->mndl->newIm) < 4)
				mandel_core_2(v);
			v->mndl->x++;
			if ((v->mndl->newRe * v->mndl->newRe
					+ v->mndl->newIm * v->mndl->newIm) < 4)
				v->matrix[v->mndl->y][v->mndl->x] = 0;
			else
				v->matrix[v->mndl->y][v->mndl->x] = 1;
		}	
		v->mndl->y++;
	}	
	return (1);
}

void	julia_matrix_core(t_data *v, int i)
{
	v->mndl->newRe = 1.5 * (v->mndl->x - v->width / 2)
		/ (0.5 * v->zoom * v->width) + v->moveX;
	v->mndl->newIm = (v->mndl->y - v->height / 2)
		/ (0.5 * v->zoom * v->height) + v->moveY;
	i = -1;
	while (++i < v->max_iterations && (pow(v->mndl->newRe, 2)
			+ pow(v->mndl->newIm, 2)) < 4)
		julia_core_x(v, i, 0);
	v->mndl->x++;
	if ((v->mndl->newRe * v->mndl->newRe
			+ v->mndl->newIm * v->mndl->newIm) < 4)
		v->matrix[v->mndl->y][v->mndl->x] = 0;
	else
		v->matrix[v->mndl->y][v->mndl->x] = 1;
}

int	julia_set_matrix(t_data *v)
{
	int	i;

	i = 0;
	v->mndl->y = 0;
	while (v->mndl->y < v->height)
	{
		v->mndl->x = 0;
		while (v->mndl->x < v->width)
			julia_matrix_core(v, i);
		v->mndl->y++;
	}	
	return (1);
}
