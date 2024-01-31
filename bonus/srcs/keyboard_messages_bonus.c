/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_messages_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 01:07:32 by eltouma           #+#    #+#             */
/*   Updated: 2024/01/30 11:42:47 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_press_left(t_fractal *fractal)
{
	fractal->shift_real += (0.5 * fractal->zoom);
	ft_printf(" You press left ⬅️ \n");
}

void	ft_press_right(t_fractal *fractal)
{
	fractal->shift_real -= (0.5 * fractal->zoom);
	ft_printf(" You press right ➡️\n");
}

void	ft_press_up(t_fractal *fractal)
{
	fractal->shift_not_real -= (0.5 * fractal->zoom);
	ft_printf(" You press up ⬆️\n");
}

void	ft_press_down(t_fractal *fractal)
{
	fractal->shift_not_real += (0.5 * fractal->zoom);
	ft_printf(" You press down ⬇️ \n");
}
