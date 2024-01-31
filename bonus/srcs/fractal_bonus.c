/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:30:51 by eltouma           #+#    #+#             */
/*   Updated: 2024/01/28 04:39:18 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_init_data(t_fractal *fractal)
{
	fractal->hypothenuse = 4;
	fractal->max_iteration = 100;
	fractal->shift_real = 0.0;
	fractal->shift_not_real = 0.0;
	fractal->zoom = 1.0;
}

void	ft_destroy_window(t_fractal *fractal)
{
	mlx_destroy_window(fractal->connexion, fractal->window);
	free(fractal->connexion);
	fractal->connexion = NULL;
	ft_handle_malloc_error();
}

void	ft_destroy_image(t_fractal *fractal)
{
	mlx_destroy_image(fractal->connexion, fractal->img.img_ptr);
	mlx_destroy_window(fractal->connexion, fractal->window);
	free(fractal->connexion);
	fractal->connexion = NULL;
	ft_handle_malloc_error();
}

void	ft_init(t_fractal *fractal)
{
	ft_init_img(fractal);
	fractal->connexion = mlx_init();
	if (!fractal->connexion)
		ft_handle_malloc_error();
	fractal->window = mlx_new_window(fractal->connexion, WIDTH, HEIGHT,
			fractal->name);
	if (!fractal->window)
		ft_destroy_window(fractal);
	fractal->img.img_ptr = mlx_new_image(fractal->connexion, WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
		ft_destroy_image(fractal);
	fractal->img.address = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bits_per_pixel,
			&fractal->img.line_length,
			&fractal->img.endian);
	ft_init_data(fractal);
	ft_init_events(fractal);
}

void	ft_render_fractal(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_handle_pixel(x, y, fractal);
			x += 1;
		}
		y += 1;
	}
	mlx_put_image_to_window(fractal->connexion, fractal->window,
		fractal->img.img_ptr, 0, 0);
}
