/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:36:44 by mtournay          #+#    #+#             */
/*   Updated: 2021/09/09 17:07:31 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_set
{
	int		x;
	int		y;
	int		iteration;
	double	zR;
	double	zI;
	double	Rsquared;
	double	Isquared;
	double	pr;
	double	pi;
	double	newRe;
	double	newIm;
	double	oldRe;
	double	oldIm;
	double	cRe;
	double	cIm;
}				t_set;

typedef struct s_data
{
	int			color;
	int			red;
	int			blue;
	int			green;
	int			transparency;
	double		height;
	double		width;
	double		zoom;
	double		moveX;
	double		moveY;
	int			max_iterations;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*mlx_win;
	void		*img2;
	void		*addr2;
	int			bol_img1;
	int			color_shift;
	int			color_max;
	int			color_min;
	char		matrix[720][1280];
	int			scale_min;
	int			color_bol;
	int			*mouse_xpos;
	int			*mouse_ypos;
	int			move_julia;
	int			julia_max;
	int			julia_min;
	int			julia_set;
	int			mndl_set;
	int			help_bol;
	int			red_param;
	int			blue_param;
	int			green_param;
	t_set		*mndl;
}				t_data;

void	init_struct(t_data *vars);
void	init_struct_2(t_data *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	init_color(t_data *v);
void	help_commands(t_data *v);
void	my_mlx_init(t_data *vars);
void	fracact_init(t_data *vars);
void	help_screen(t_data *vars);
void	julia_core_x(t_data *v, int i, int color_shift);
void	julia_core_y(t_data*v, int i, int color_shift);
void	mandel_core_1(t_data *v);
void	mandel_core_2(t_data *v);
void	mandel_core_3(t_data *v, int color_shift, int i);
void	mandel_core_4(t_data *v, int i);
void	julia_matrix_core(t_data *v, int i);
int		create_trgb(int t, int r, int g, int b);
int		ft_close(t_data *vars);
int		mandelbrot_set_matrix(t_data *v);
int		julia_set_matrix(t_data *v);
int		julia_set(t_data *v, int color_shift);
int		mandelbrot_set(t_data *v, int color_shift);
int		zoom(int button, int x, int y, t_data *v);
int		black_screen(t_data *v);
int		keyhook(int keycode, t_data *v);
int		keyhook_2(int keycode, t_data *v);
int		color_shift(t_data *vars);
int		move_julia(t_data *vars);
int		move_julia_opti(t_data *vars);
int		instance(t_data *vars);
int		fract_params(char **input, t_data *vars);
int		color_params(char **input, t_data *v);
int		custom_comp(const char *s1, const char *s2, size_t n);
#endif