/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:44:42 by eltouma           #+#    #+#             */
/*   Updated: 2024/01/27 22:51:08 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_fractal(t_fractal *fractal)
{
	fractal->connexion = NULL;
	fractal->window = NULL;
	fractal->name = NULL;
	fractal->hypothenuse = 0;
	fractal->max_iteration = 0.0;
	fractal->shift_real = 0.0;
	fractal->shift_not_real = 0.0;
	fractal->zoom = 0.0;
	fractal->julia_real = 0.0;
	fractal->julia_not_real = 0.0;
}

void	ft_init_img(t_fractal *fractal)
{
	fractal->img.img_ptr = NULL;
	fractal->img.address = NULL;
	fractal->img.bits_per_pixel = 0;
	fractal->img.line_length = 0;
	fractal->img.endian = 0;
}

void	ft_init_complex(t_cmplx complex_nb)
{
	complex_nb.real = 0.0;
	complex_nb.not_real = 0.0;
}
