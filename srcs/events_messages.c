/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_messages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:16:52 by eltouma           #+#    #+#             */
/*   Updated: 2024/01/30 11:50:19 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_msg_to_stop_zoom(t_fractal *fractal)
{
	ft_printf("\n Sorry, \033[%dmyou can't\033[0m", 31);
	ft_printf(" zoom in more.");
	ft_printf(" But, you can zoom out! ");
	ft_printf("Scroll \033[%dm\e[1mup\033[0m: ⬆️ \n", 36);
	fractal->zoom = 0.0;
}
