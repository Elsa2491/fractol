/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:31:27 by eltouma           #+#    #+#             */
/*   Updated: 2023/12/30 11:38:28 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	ft_to_lower(argv[1]);
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
	{
		fractal.name = argv[1];
		ft_init(&fractal);
		ft_render_fractal(&fractal);
		mlx_loop(fractal.connexion);
	}
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		fractal.name = argv[1];
		fractal.julia_real = ft_atoi(argv[2]);
		fractal.julia_not_real = ft_atoi(argv[3]);
		printf("%f, %f\n", fractal.julia_real, fractal.julia_not_real);
		ft_init(&fractal);
		ft_render_fractal(&fractal);
		mlx_loop(fractal.connexion);
	}
	else
	{
		printf("%s", ERROR_MSG);
		exit(EXIT_FAILURE);
	}
}
