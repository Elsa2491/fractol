#include "fractol.h"

double	ft_to_scale(double unscaled_n, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_n / old_max + new_min);
}

t_complex	ft_sum(t_complex z, t_complex c)
{
	t_complex	result;

	result.real = z.real + c.real;
	result.not_real = z.not_real + c.not_real;
	return (result);
}

t_complex	ft_square(t_complex z)
{
	t_complex	result;

	result.real = (z.real * z.real) - (z.not_real * z.not_real);
	result.not_real = 2 * z.real * z.not_real;
	return (result);
}
