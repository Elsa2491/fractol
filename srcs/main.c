/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:31:27 by eltouma           #+#    #+#             */
/*   Updated: 2024/03/18 00:51:35 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_welcome_message(t_fractal *fractal)
{
	ft_print_header();
	ft_printf(" Welcome to ");
	ft_printf("\033[%dm\e[1m%s\e\033[0m\n\n", 34, fractal->name);
}

static void	ft_handle_mandelbrot(char **argv, t_fractal fractal)
{
	fractal.name = argv[1];
	ft_init(&fractal);
	ft_welcome_message(&fractal);
	ft_render_fractal(&fractal);
	mlx_loop(fractal.connexion);
}

static void	ft_handle_julia(char **argv, t_fractal fractal)
{
	fractal.name = argv[1];
	ft_init(&fractal);
	ft_welcome_message(&fractal);
	fractal.julia_real = ft_atoi(argv[2]);
	fractal.julia_not_real = ft_atoi(argv[3]);
	ft_render_fractal(&fractal);
	mlx_loop(fractal.connexion);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 1)
		ft_print_help();
	ft_memset(&fractal, 0, sizeof(t_fractal));
	ft_to_lower(argv[1]);
	if (argc == 3)
		ft_print_julia_missing_param();
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		ft_handle_mandelbrot(argv, fractal);
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		ft_check_param(argv);
		ft_handle_julia(argv, fractal);
	}
	else
		ft_print_help();
}
