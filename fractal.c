#include "fractol.h"

void	ft_init_data(t_fractal *fractal)
{
	fractal->hypothenuse = 4;
	fractal->max_iteration = 300;
	fractal->shift_real = 0.0;
	fractal->shift_not_real = 0.0;
}

void	ft_handle_close(t_fractal *fractal)
{
	mlx_destroy_image(fractal->connexion, fractal->img.img_ptr);
	mlx_destroy_window(fractal->connexion, fractal->window);
	mlx_destroy_display(fractal->connexion);
	free(fractal->connexion);
}

int	ft_handle_key(int key_code, t_fractal *fractal)
{
	if (key_code == XK_Escape)
		ft_handle_close(fractal);
	else if (key_code == XK_Left)
		fractal->shift_real += 0.2;
	else if (key_code == XK_Right)
		fractal->shift_real -= 0.2;
	else if (key_code == XK_Up)
		fractal->shift_not_real -= 0.2;
	else if (key_code == XK_Down)
		fractal->shift_not_real += 0.2;
	else if (key_code == 97)
		fractal->max_iteration += 0.5;
	else if (key_code == XK_minus)
		fractal->max_iteration -= 0.5;
//	else if (key_code == XK_space)
	ft_render_fractal(fractal);
}

void	ft_init_events(t_fractal *fractal)
{
	mlx_hook(fractal->window, 2, (1L<<0), ft_handle_key, fractal); 
//	mlx_hook(fractal->window, 4, (1L<<2), ft_handle_btn, fractal); 
//	mlx_hook(fractal->window, 17, (1L<<17), ft_handle_close, fractal); 
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
	ft_init_events(fractal);
	ft_init_data(fractal);
} 

int	ft_print_pixel(t_img *img, int x, int y, int color)
{
	char	*dest;

	dest = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return	(*(unsigned int*)dest = color);
}

void	ft_handle_pixel(int x, int y, t_fractal *fractal)
{
	int		i;
	t_complex	z;
	t_complex	c;
	t_complex	square;
	int		color;

	i = 0;
	z.real = 0.0;
	z.not_real = 0.0;
	c.real = ft_to_scale(x, -2, 2, WIDTH) + fractal->shift_real;
	c.not_real = ft_to_scale(y, 2, -2, HEIGHT) + fractal->shift_not_real;
	while (i < fractal->max_iteration)
	{
		square = ft_square(z);
		z = ft_sum(square, c);
		if ((z.real * z.real) + (z.not_real * z.not_real) > fractal->hypothenuse)
		{
			color = ft_to_scale(i, 0xF5EBE0, 0xE3D5CA, fractal->max_iteration);
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
