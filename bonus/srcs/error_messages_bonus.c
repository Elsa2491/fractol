/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:29:09 by eltouma           #+#    #+#             */
/*   Updated: 2024/01/28 04:38:28 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_print_julia_classiques_examples(void)
{	
	ft_printf("\033[%dm  Classique\t\033[0m", 33);
	ft_printf("\033[%dm\e[1m%s\e\033[0m%s", 32, ARROW, JULIA);
	ft_printf("\033[%dm\e[1m 0.285\t0.01\e\033[0m\n", 36);
	ft_printf("\033[%dm  Siegel disk\t\033[0m", 33);
	ft_printf("\033[%dm\e[1m%s\e\033[0m%s", 32, ARROW, JULIA);
	ft_printf("\033[%dm\e[1m -0.4\t\t0.6\e\033[0m\n", 36);
	ft_printf("\033[%dm  Sun\t\t\033[0m", 33);
	ft_printf("\033[%dm\e[1m%s\e\033[0m%s", 32, ARROW, JULIA);
	ft_printf("\033[%dm\e[1m -1.476\t0\e\033[0m\n", 36);
	ft_printf("\033[%dm  Whirlwind\t\033[0m", 33);
	ft_printf("\033[%dm\e[1m%s\e\033[0m%s", 32, ARROW, JULIA);
	ft_printf("\033[%dm\e[1m 0.37\t\t-0.13\e\033[0m\n", 36);
}

void	ft_print_julia_psychedelics_examples(void)
{	
	ft_printf("\033[%dm  Virus\t\t\033[0m", 33);
	ft_printf("\033[%dm\e[1m%s\e\033[0m%s", 32, ARROW, JULIA);
	ft_printf("\033[%dm\e[1m -1.769110\t0.009020\e\033[0m\n", 36);
	ft_printf("\033[%dm  La grande vadrouille\033[0m", 33);
	ft_printf("\033[%dm\e[1m%s\e\033[0m%s", 32, ARROW, JULIA);
	ft_printf("\033[%dm\e[1m -1.74856\t0.00075\e\033[0m\n", 36);
	ft_printf("\033[%dm  Devil's hand\t\033[0m", 33);
	ft_printf("\033[%dm\e[1m%s\e\033[0m%s", 32, ARROW, JULIA);
	ft_printf("\033[%dm\e[1m 0.38\t\t-0.12\e\033[0m\n", 36);
	ft_printf("\033[%dm  Spiral void\t\033[0m", 33);
	ft_printf("\033[%dm\e[1m%s\e\033[0m%s", 32, ARROW, JULIA);
	ft_printf("\033[%dm\e[1m 0.37\t\t-0.14\e\033[0m\n", 36);
	ft_printf("\033[%dm  Pink Paradise\t\033[0m", 33);
	ft_printf("\033[%dm\e[1m%s\e\033[0m%s", 32, ARROW, JULIA);
	ft_printf("\033[%dm\e[1m 0.37\t\t-0.1\e\033[0m\n", 36);
}

void	ft_print_julia_animals_examples(void)
{	
	ft_printf("\033[%dm  Elephant valley\033[0m", 33);
	ft_printf("\033[%dm\e[1m%s\e\033[0m%s", 32, ARROW, JULIA);
	ft_printf("\033[%dm\e[1m 0.285\t0.0\e\033[0m\n", 36);
	ft_printf("\033[%dm  Sea horse\t\033[0m", 33);
	ft_printf("\033[%dm\e[1m%s\e\033[0m%s", 32, ARROW, JULIA);
	ft_printf("\033[%dm\e[1m -0.75\t0.1\e\033[0m\n", 36);
	ft_printf("\033[%dm  Snail\t\t\033[0m", 33);
	ft_printf("\033[%dm\e[1m%s\e\033[0m%s", 32, ARROW, JULIA);
	ft_printf("\033[%dm\e[1m -1.74831\t0.00046\e\033[0m\n", 36);
	ft_printf("\033[%dm  Dragon\t\033[0m", 33);
	ft_printf("\033[%dm\e[1m%s\e\033[0m%s", 32, ARROW, JULIA);
	ft_printf("\033[%dm\e[1m -0.8\t\t0.156\e\033[0m\n", 36);
	ft_printf("\033[%dm  Rabbit\t\033[0m", 33);
	ft_printf("\033[%dm\e[1m%s\e\033[0m%s", 32, ARROW, JULIA);
	ft_printf("\033[%dm\e[1m -0.12\t0.75\e\033[0m\n", 36);
	ft_printf("\033[%dm  Snake\t\t\033[0m", 33);
	ft_printf("\033[%dm\e[1m%s\e\033[0m%s", 32, ARROW, JULIA);
	ft_printf("\033[%dm\e[1m 0.0\t\t0.8\e\033[0m\n", 36);
}

void	ft_print_julia_missing_param(void)
{
	ft_print_header();
	ft_printf("\033[%dm\e[1m%s\e\033[0m", 31, WARNING);
	ft_printf(" It seems something went wrong.");
	ft_printf(" Please check you enter floats as arguments:\n");
	ft_printf("\033[%dm\e[1m%s\e\033[0m%s", 32, ARROW, JULIA);
	ft_printf("\033[%dm\e[1m%s\e\033[0m", 34, JULIA_ARGV);
	ft_printf("\n\n See the examples below:");
	ft_print_julia_examples();
}
