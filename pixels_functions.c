#include "fractol.h"

int	ft_print_pixel(t_img *img, int x, int y, int color)
{
	char	*dest;

	dest = img->address
		+ (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dest = color);
}

void	ft_handle_pixel(int x, int y, t_fractal *fractal)
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_complex	square;
	int			color;

	i = 0;
	z.real = 0.0;
	z.not_real = 0.0;
	c.real = (ft_to_scale(x, -2, 2, WIDTH) * fractal->zoom)
		+ fractal->shift_real;
	c.not_real = (ft_to_scale(y, 2, -2, HEIGHT) * fractal->zoom)
		+ fractal->shift_not_real;
	while (i < fractal->max_iteration)
	{
		square = ft_square(z);
		z = ft_sum(square, c);
		if ((z.real * z.real) + (z.not_real * z.not_real)
				> fractal->hypothenuse)
		{
			color = ft_to_scale(i, 0xFBF8CC, 0x9d8189, fractal->max_iteration);
			ft_print_pixel(&fractal->img, x, y, color);
			return ;
		}
		i += 1;
	}
	ft_print_pixel(&fractal->img, x, y, 0x000000);
}
