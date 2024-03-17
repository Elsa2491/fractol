/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_function_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:30:40 by eltouma           #+#    #+#             */
/*   Updated: 2024/02/02 17:16:19 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_handle_close(t_fractal *fractal)
{
	ft_printf("\n Thanks for watching\n\n");
	ft_print_header();
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
		ft_press_left(fractal);
	else if (key_code == XK_Right)
		ft_press_right(fractal);
	else if (key_code == XK_Up)
		ft_press_up(fractal);
	else if (key_code == XK_Down)
		ft_press_down(fractal);
	else if (key_code == 107)
		ft_print_incrementation_msg(fractal);
	else if (key_code == 108)
		ft_print_decrementation_msg(fractal);
	ft_render_fractal(fractal);
	return (0);
}

int	ft_handle_mouse(int key_code, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (key_code == 4)
	{
		ft_printf(" You scroll \033[%dm\e[1mup\033[0m: you zoom out\n", 36);
		fractal->zoom += 0.03;
	}
	else if (key_code == 5)
	{
		if (fractal->zoom > 0)
		{
			ft_printf(" You scroll \033[%dm\e[1mdown\033[0m:", 35);
			ft_printf(" you zoom in.\n");
			fractal->zoom -= 0.03;
		}
		else
			ft_print_msg_to_stop_zoom(fractal);
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
