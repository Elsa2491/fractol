#include "fractol.h"

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
		fractal->shift_real += 1.5;
	else if (key_code == XK_Right)
		fractal->shift_real -= 1.5;
	else if (key_code == XK_Up)
		fractal->shift_not_real -= 1.5;
	else if (key_code == XK_Down)
		fractal->shift_not_real += 1.5;
	else if (key_code == 97)
		fractal->max_iteration += 15;
	else if (key_code == XK_minus)
		fractal->max_iteration -= 15;
	ft_render_fractal(fractal);
}

int	ft_handle_mouse(int btn, int real, int not_real, t_fractal *fractal)
{
	if (btn == 4)
		fractal->zoom += 0.5;
	else if (btn == 5)
		fractal->zoom -= 0.5;
	ft_render_fractal(fractal);
	return (0);
}

void	ft_init_events(t_fractal *fractal)
{
	mlx_hook(fractal->window, 2, (1L << 0), ft_handle_key, fractal);
	mlx_hook(fractal->window, 4, (1L << 2), ft_handle_mouse, fractal);
	mlx_hook(fractal->window, 17, (1L << 17), ft_handle_close, fractal);
}
