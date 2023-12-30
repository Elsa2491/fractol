/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:30:40 by eltouma           #+#    #+#             */
/*   Updated: 2023/12/30 18:51:55 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_handle_close(t_fractal *fractal)
{
	mlx_destroy_image(fractal->connexion, fractal->img.img_ptr);
	mlx_destroy_window(fractal->connexion, fractal->window);
	mlx_destroy_display(fractal->connexion);
	free(fractal->connexion);
	exit(1);
}

int	ft_handle_key(int key_code, t_fractal *fractal)
{
	if (key_code == XK_Escape)
		ft_handle_close(fractal);
	else if (key_code == XK_Left)
		fractal->shift_real += (0.5 * fractal->zoom);
	else if (key_code == XK_Right)
		fractal->shift_real -= (0.5 * fractal->zoom);
	else if (key_code == XK_Up)
		fractal->shift_not_real -= (0.5 * fractal->zoom);
	else if (key_code == XK_Down)
		fractal->shift_not_real += (0.5 * fractal->zoom);
	else if (key_code == 107)
	{
		fractal->max_iteration += 2;
		printf("+= 2 = %f\n", fractal->max_iteration);
	}
	else if (key_code == 108)
	{
		fractal->max_iteration += 2;
		if (fractal->max_iteration < 20.000000)
			return (0) ;
		printf("-= 2 = %f\n", fractal->max_iteration);
	}

	ft_render_fractal(fractal);
	return (0);
}

int	ft_handle_mouse(int key_code, int x, int y, t_fractal *fractal)
{
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	if (key_code == 4)
	{
		printf("up\n");
		fractal->zoom += 0.05;
	}
	else if (key_code == 5)
	{
		printf("down\n");
		fractal->zoom -= 0.05;
	}
	ft_render_fractal(fractal);
	return (0);
}

void	ft_init_events(t_fractal *fractal)
{
	mlx_key_hook(fractal->window, ft_handle_key, fractal);
	mlx_hook(fractal->window, 17, (1L << 17), ft_handle_close, fractal);
	mlx_hook(fractal->window, 4, (1L << 2), ft_handle_mouse, fractal);
}
