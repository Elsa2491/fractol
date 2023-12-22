#include "fractol.h"

void	ft_init_data(t_fractal *fractal)
{
	fractal->hypothenuse = 4;
	fractal->max_iteration = 1500;
}

void	ft_init(t_fractal *fractal)
{
	fractal->connexion = mlx_init();
	if (!fractal->connexion)
		ft_handle_malloc_error();
	fractal->window = mlx_new_window(fractal->connexion, WIDTH, HEIGHT, fractal->name);
	if (!fractal->window)
	{
		mlx_destroy_window(fractal->connexion, fractal->window);
		free(fractal->connexion);
		ft_handle_malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->connexion, WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_image(fractal->connexion, fractal->img.img_ptr);
		mlx_destroy_window(fractal->connexion, fractal->window);
		free(fractal->connexion);
		ft_handle_malloc_error();
	}
	fractal->img.address = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bits_per_pixel, &fractal->img.line_length, &fractal->img.endian);
	// ft_init_events(fractal);
	ft_init_data(fractal);
} 

double	ft_to_scale(double unscaled_n, double new_min, double new_max, double old_max)
{
	return (new_max - new_min) * unscaled_n / old_max + new_min;
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


int	ft_print_pixel(t_img *img, int x, int y, int color)
{
	char	*dest;

	dest = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}

void	ft_handle_pixel(int x, int y, t_fractal *fractal)
{
	int		i;
	t_complex	z;
	t_complex	c;
//	t_complex	square;
	int		color;

	i = 0;
	z.real = 0.0;
	z.not_real = 0.0;
	c.real = ft_to_scale(x, -2, 2, WIDTH);
	c.not_real = ft_to_scale(y, 2, -2, HEIGHT);
	while (i < fractal->max_iteration)
	{
	//	square = ft_square(z);
		z = ft_sum(ft_square(z), c);
	/*	z.real = tmp_real;
		z.not_real = 2 * z.real * z.not_real;
		z.real = tmp_real;
		z.real += c.real;
		c.not_real += c.not_real;*/
		if ((z.real * z.real) + (z.not_real * z.not_real) > fractal->hypothenuse)
		{
			color = ft_to_scale(i, 0xFBF8CC, 0xB9FBC0, fractal->max_iteration);
			ft_print_pixel(&fractal->img, x, y, color);
			return ;
		}
		i += 1;
	}
	ft_print_pixel(&fractal->img, x, y, 0x000000);
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
	mlx_put_image_to_window(fractal->connexion, fractal->window, fractal->img.img_ptr, 0, 0);
}
