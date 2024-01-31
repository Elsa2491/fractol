/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:30:13 by eltouma           #+#    #+#             */
/*   Updated: 2024/01/26 22:36:52 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_print_pixel(t_img *img, int x, int y, int color)
{
	char	*dest;

	dest = img->address
		+ (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dest = color);
}

void	ft_print_right_fractal_z(int x, int y, t_cmplx *z, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		z->real = (ft_to_scale(x, -2, 2, WIDTH) * fractal->zoom)
			+ fractal->shift_real;
		z->not_real = (ft_to_scale(y, 2, -2, HEIGHT) * fractal->zoom)
			+ fractal->shift_not_real;
	}
	else
	{
		z->real = 0.0;
		z->not_real = 0.0;
	}
}

void	ft_print_right_fractal_c(int x, int y, t_cmplx *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->real = fractal->julia_real;
		c->not_real = fractal->julia_not_real;
	}
	else
	{
		c->real = (ft_to_scale(x, -2, 2, WIDTH) * fractal->zoom)
			+ fractal->shift_real;
		c->not_real = (ft_to_scale(y, 2, -2, HEIGHT) * fractal->zoom)
			+ fractal->shift_not_real;
	}
}

void	ft_handle_pixel(int x, int y, t_fractal *fractal)
{
	int			i;
	t_cmplx		z;
	t_cmplx		c;
	int			color;

	i = 0;
	ft_print_right_fractal_z(x, y, &z, fractal);
	ft_print_right_fractal_c(x, y, &c, fractal);
	while (i < fractal->max_iteration && fractal->zoom <= 146.000000)
	{
		z = ft_sum(ft_square(z), c);
		if ((z.real * z.real) + (z.not_real * z.not_real)
			> fractal->hypothenuse)
		{
			color = ft_to_scale(i, 0xFFFFFF, 0x95d5b2, fractal->max_iteration);
			ft_print_pixel(&fractal->img, x, y, color);
			return ;
		}
		i += 1;
	}
	ft_print_pixel(&fractal->img, x, y, 0x000000);
}
