/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_messages_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:29:09 by eltouma           #+#    #+#             */
/*   Updated: 2024/01/28 04:41:46 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_print_header(void)
{
	ft_printf("\n\e[2m ####################################\e[0m");
	ft_printf("\e[2m####################################\n\n\e[0m");
}

void	ft_print_footer(void)
{
	ft_print_header();
	exit(EXIT_FAILURE);
}
