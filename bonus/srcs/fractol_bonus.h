/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:31:07 by eltouma           #+#    #+#             */
/*   Updated: 2024/02/02 19:48:51 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H

# define FRACTOL_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../../printf/srcs/ft_printf.h"
# include "../../minilibx-linux/mlx.h"
# include "X11/X.h"
# include "X11/keysym.h"

# define WARNING      " → Warning\n"
# define CORRECT_ARGV		" Please enter correct arguments:\n"
# define ARROW	"\t→ "
# define MANDELBROT	"./fractol_bonus mandelbrot"
# define JULIA_MSG	" julia needs 3 parameters:\n"
# define JULIA	"./fractol_bonus julia "
# define JULIA_ARGV "[float_1] [float_2]"
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

void	ft_check_param(char **argv);
void	ft_to_lower(char *str);
int		ft_strncmp(const char *s1, const char *s2, int n);
double	ft_atoi(char *str);
void	ft_init_fractal(t_fractal *fractal);
void	ft_init_img(t_fractal *fractal);
void	ft_init_complex(t_cmplx complex_nb);
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
void	ft_handle_pixel(double x, double y, t_fractal *fractal);

void	ft_print_header(void);
void	ft_print_footer(void);
void	ft_print_julia_error(char **argv);
void	ft_print_julia_missing_param(void);
void	ft_print_julia_examples(void);
void	ft_print_julia_classiques_examples(void);
void	ft_print_julia_animals_examples(void);
void	ft_print_julia_psychedelics_examples(void);
void	ft_print_help(void);

void	ft_print_incrementation_msg(t_fractal *fractal);
void	ft_print_decrementation_msg(t_fractal *fractal);
void	ft_print_msg_to_stop_zoom(t_fractal *fractal);
void	ft_press_left(t_fractal *fractal);
void	ft_press_right(t_fractal *fractal);
void	ft_press_up(t_fractal *fractal);
void	ft_press_down(t_fractal *fractal);
#endif
