/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_messages_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:16:52 by eltouma           #+#    #+#             */
/*   Updated: 2024/01/28 04:38:55 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_print_incrementation_msg(t_fractal *fractal)
{
	fractal->max_iteration += 2;
	ft_printf(" You pressed k, you");
	ft_printf("\033[%dm increase\033[0m the number of iteration\n", 32);
}

void	ft_print_decrementation_msg(t_fractal *fractal)
{
	if (fractal->max_iteration > 20.000000)
	{
		fractal->max_iteration -= 2;
		ft_printf(" You pressed l, you");
		ft_printf("\033[%dm decrease\033[0m the number of iteration\n", 33);
	}
	else
		ft_printf(" Too few iterations, press \033[%dmk\003[0m to get back\n", 32);
}

void	ft_print_msg_to_stop_zoom(t_fractal *fractal)
{
	ft_printf("\n Sorry, \033[%dmyou can't\033[0m", 31);
	ft_printf(" zoom in more.");
	ft_printf(" But, you can zoom out! ");
	ft_printf("Scroll \033[%dm\e[1mup\033[0m: ⬆️ \n", 36);
	fractal->zoom = 0.0;
}
