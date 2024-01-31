/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_messages.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:28:37 by eltouma           #+#    #+#             */
/*   Updated: 2024/01/30 11:49:19 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_help_event(void)
{
	ft_printf("\n\n  ________________________________________");
	ft_printf("______________________\n");
	ft_printf(" |\t\t\t\t\t\t\t\t|\n");
	ft_printf(" | How does it work?\t\t\t\t\t\t|\n");
	ft_printf(" |\t1 - If you want to see Mandelbrot fractol\t\t|\n");
	ft_printf(" |\t\033[%dm\e[1m%s\e\033[0m", 32, ARROW);
	ft_printf("%s\t\t\t\t|\n", MANDELBROT);
	ft_printf(" |\t2 - Or if you want to see Julia fractol\t\t\t|\n");
	ft_printf(" |\t\033[%dm\e[1m%s\e\033[0m%s", 32, ARROW, JULIA);
	ft_printf("\033[%dm\e[1m%s\e\033[0m", 34, JULIA_ARGV);
	ft_printf(" \t\t|\n");
	ft_printf(" |\t\t\t\t\t\t\t\t|\n");
	ft_printf(" | Scroll \033[%dm\e[1mdown\e\033[0m", 35);
	ft_printf(" to zoom in\t\t\t\t\t|\n");
	ft_printf(" | Scroll \033[%dm\e[1mup\e\033[0m", 36);
	ft_printf(" to zoom out\t\t\t\t\t|\n");
	ft_printf(" |________________________________________");
	ft_printf("______________________|\n\n");
}

void	ft_print_julia_examples(void)
{
	ft_printf(" (⚠️  names \033[%dmare not\033[0m arguments)\n\n", 31);
	ft_print_julia_classiques_examples();
	ft_print_julia_animals_examples();
	ft_print_julia_psychedelics_examples();
	ft_print_footer();
}

void	ft_print_help(void)
{
	ft_print_header();
	ft_printf("\033[%dm\e[1m%s\e\033[0m %s", 31, WARNING, CORRECT_ARGV);
	ft_printf("\033[%dm\e[1m%s\e\033[0m%s", 32, ARROW, MANDELBROT);
	ft_printf("\n\033[%dm\e[1m%s\e\033[0m%s", 32, ARROW, JULIA);
	ft_printf("\033[%dm\e[1m%s\e\033[0m", 34, JULIA_ARGV);
	ft_print_help_event();
	ft_printf("\n For julia, see the examples below:");
	ft_print_julia_examples();
}
