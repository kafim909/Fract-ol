/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:30:43 by mtournay          #+#    #+#             */
/*   Updated: 2021/09/09 13:11:28 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	help_screen(t_data *vars)
{
	black_screen(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, 0, 0);
	help_commands(vars);
}

int	black_screen(t_data *v)
{
	v->mndl->y = 0;
	while (v->mndl->y < v->height)
	{
		v->mndl->x = 0;
		while (v->mndl->x < v->width)
		{
			my_mlx_pixel_put(v, v->mndl->x, v->mndl->y, 0x000000);
			v->mndl->x++;
		}
		v->mndl->y++;
	}
	return (1);
}

void	help_commands(t_data *v)
{
	if (v->julia_set)
	{
		mlx_string_put(v->mlx, v->mlx_win, v->height / 2 + 180,
			v->width / 16 + 100, 0xC7FFE0, "Color shift = t & y");
		mlx_string_put(v->mlx, v->mlx_win, v->height / 2 + 180,
			v->width / 16 + 150, 0xC7FFE0, "Julia shift = p & o");
		mlx_string_put(v->mlx, v->mlx_win, v->height / 2 + 180,
			v->width / 16 + 200, 0xC7FFE0, "Julia constant = n & m");
	}
	if (v->mndl_set)
		mlx_string_put(v->mlx, v->mlx_win, v->height / 2 + 180,
			v->width / 16, 0xC7FFE0, "Glowing colors = t & y");
	mlx_string_put(v->mlx, v->mlx_win, v->height / 2 + 180,
		v->width / 16 + 250, 0xC7FFE0, "Move = arrows");
	mlx_string_put(v->mlx, v->mlx_win, v->height / 2 + 180,
		v->width / 16 + 300, 0xC7FFE0, "Zoom = mouse scroll");
	mlx_string_put(v->mlx, v->mlx_win, v->height / 2 + 180,
		v->width / 16 + 350, 0xC7FFE0, "Max iteration = < & >");
	mlx_string_put(v->mlx, v->mlx_win, v->height / 2 + 180,
		v->width / 16 + 400, 0xC7FFE0, "Exit menu = j");
}
