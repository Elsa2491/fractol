/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:31:35 by eltouma           #+#    #+#             */
/*   Updated: 2023/12/30 11:36:08 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_to_scale(double n, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * n / old_max + new_min);
}

t_cmplx	ft_sum(t_cmplx z, t_cmplx c)
{
	t_cmplx	result;

	result.real = z.real + c.real;
	result.not_real = z.not_real + c.not_real;
	return (result);
}

t_cmplx	ft_square(t_cmplx z)
{
	t_cmplx	result;

	result.real = (z.real * z.real) - (z.not_real * z.not_real);
	result.not_real = 2 * z.real * z.not_real;
	return (result);
}
