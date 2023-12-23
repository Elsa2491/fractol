#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	ft_to_lower(argv[1]);
//	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) ||
//			(argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
//	{
		fractal.name = argv[1];

		printf("%f\n" , ft_atoi(argv[2]));
		/*	ft_init(&fractal);
			ft_render_fractal(&fractal);
			mlx_loop(fractal.connexion);
			*/
//	}
//	{
//		printf("%s", ERROR_MSG);
//:		exit(EXIT_FAILURE);
//	}
}
