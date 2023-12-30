/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:31:07 by eltouma           #+#    #+#             */
/*   Updated: 2023/12/30 19:00:31 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
//# include <math.h>
# include "minilibx-linux/mlx.h"
# include "X11/X.h"
# include "X11/keysym.h"

# define ERROR_MSG      "Please enter correct arguments : \n\t\t\t\t→ \"./fractol mandelbrot\", or\n\t\t\t\t→ \"./fractol julia argv_2 argv_3\"\n"
# define WIDTH	1000
# define HEIGHT	1000

typedef struct s_img
{
	void	*img_ptr;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_img;

typedef struct s_fractal
{
	void	*connexion;
	void	*window;
	char	*name;
	int		hypothenuse;
	double	max_iteration;
	double	shift_real;
	double	shift_not_real;
	double	zoom;
	double	julia_real;
	double	julia_not_real;
	t_img	img;
}		t_fractal;

typedef struct s_complex
{
	double	real;
	double	not_real;
}		t_cmplx;

void	ft_to_lower(char *str);
int		ft_strncmp(const char *s1, const char *s2, int n);
double	ft_atoi(char *str);
void	ft_init(t_fractal *fractal);
void	ft_handle_malloc_error(void);
void	ft_render_fractal(t_fractal *fractal);
double	ft_to_scale(double n, double new_min, double new_max, double old_max);
t_cmplx	ft_sum(t_cmplx z, t_cmplx c);
t_cmplx	ft_square(t_cmplx z);
void	ft_init_events(t_fractal *fractal);
int		ft_handle_mouse(int btn, int x, int y, t_fractal *fractal);
int		ft_handle_clode(t_fractal *fractal);
int		ft_handle_key(int key_code, t_fractal *fractal);
void	ft_handle_pixel(int x, int y, t_fractal *fractal);
int	key_hook(int keycode, t_fractal *fractal);
#endif
