#ifndef FRACTOL_H

# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
//# include <math.h>
# include "minilibx-linux/mlx.h"
# include "X11/X.h"
# include "X11/keysym.h"

# define ERROR_MSG      "Please enter correct arguments : \n\t\t\t\t→ \"./fractol mandelbrot\", or\n\t\t\t\t→ \"./fractol julia argv_2 argv_3\"\n"
# define WIDTH	800
# define HEIGHT	800

typedef struct	s_img
{
	void	*img_ptr;
	char	*address;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_img;

typedef struct	s_fractal
{
	void	*connexion;
	void	*window;
	char	*name;
	int	hypothenuse;
	double	max_iteration;
	double	shift_real;
	double	shift_not_real;
	double	zoom;
	t_img	img;
}		t_fractal;


typedef struct	s_complex
{
	double	real;
	double	not_real;
}		t_complex;

void	ft_to_lower(char *str);
int		ft_strncmp(const char *s1, const char *s2, int n);
void	ft_init(t_fractal *fractal);
void	ft_handle_malloc_error(void);
void	ft_render_fractal(t_fractal *fractal);
double		ft_to_scale(double unscaled_n, double new_min, double new_max, double old_max);
t_complex	ft_sum(t_complex z, t_complex c);
t_complex	ft_square(t_complex z);
void	ft_init_events(t_fractal *fractal);
int		ft_handle_mouse(int btn, int real, int not_rel, t_fractal *fractal);
int		ft_handle_clode(t_fractal *fractal);
int		ft_handle_key(int key_code, t_fractal *fractal);
double		ft_atoi(char *str);
#endif
