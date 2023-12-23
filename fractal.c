#include "fractol.h"

void	ft_init_data(t_fractal *fractal)
{
	fractal->hypothenuse = 4;
	fractal->max_iteration = 300;
	fractal->shift_real = 0.0;
	fractal->shift_not_real = 0.0;
	fractal->zoom = 1.0;
}

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
		fractal->shift_real += 0.2;
	else if (key_code == XK_Right)
		fractal->shift_real -= 0.2;
	else if (key_code == XK_Up)
		fractal->shift_not_real -= 0.2;
	else if (key_code == XK_Down)
		fractal->shift_not_real += 0.2;
	else if (key_code == 97)
		fractal->max_iteration += 10;
	else if (key_code == XK_minus)
		fractal->max_iteration -= 10;
	ft_render_fractal(fractal);
	if (key_code == XK_space)
	{
		ft_init(fractal);
		ft_render_fractal(fractal);
		mlx_loop(fractal->connexion);
	}
}

int	ft_round(double num)
{
	int	rounded;

	rounded = (int)num;
	if (num - rounded >= 0.5)
		rounded += 1;
	return (rounded);
}

int	ft_gradient(int start_color, int end_color, int len, int pix)
{
	double	increment[3];
	int	new[3];
	int	new_color;

	increment[0] = (double)((R(end_color)) - (R(start_color))) / (double)len;
	increment[1] = (double)((G(end_color)) - (G(start_color))) / (double)len;
	increment[2] = (double)((B(end_color)) - (B(start_color))) / (double)len;
	
	new[0] = (R(start_color)) + ft_round(pix * increment[0]);
	new[1] = (G(start_color)) + ft_round(pix * increment[1]);
	new[2] = (B(start_color)) + ft_round(pix * increment[2]);

	new_color = RGB(new[0], new[1], new[2]);

	return (new_color);
}

int	ft_handle_mouse(int btn, int real, int not_real, t_fractal *fractal)
{
	if (btn == 4)
		fractal->zoom += 0.5;
	else if (btn == 5)
		fractal->zoom -= 0.9;
	printf("%d\n", btn);
	ft_render_fractal(fractal);
	return (0);
}

void	ft_init_events(t_fractal *fractal)
{
	mlx_hook(fractal->window, 2, (1L<<0), ft_handle_key, fractal); 
	mlx_hook(fractal->window, ButtonPress, ButtonPressMask, ft_handle_mouse, fractal); 
	mlx_hook(fractal->window, 17, (1L<<17), ft_handle_close, fractal); 
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
	c.real = (ft_to_scale(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_real;
	c.not_real = (ft_to_scale(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_not_real;
	while (i < fractal->max_iteration)
	{
		square = ft_square(z);
		z = ft_sum(square, c);
		if ((z.real * z.real) + (z.not_real * z.not_real) > fractal->hypothenuse)
		{
			color = ft_to_scale(i, ft_gradient(0xC6DAF8, 0xBDE0FE, fractal->img.line_length, fractal->img.bits_per_pixel), ft_gradient(0xBDE0FE, 0xA2D2FF, fractal->img.line_length, fractal->img.bits_per_pixel),  fractal->max_iteration);
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
