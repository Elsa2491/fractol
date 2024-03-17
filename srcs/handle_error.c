/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:31:18 by eltouma           #+#    #+#             */
/*   Updated: 2024/01/28 03:37:43 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_handle_malloc_error(void)
{
	ft_print_header();
	ft_printf("\033[%dm\e[1m%s\e\033[0m", 31, WARNING);
	ft_printf("\033[%dm\e[1m Failure.\e\033[0m", 33);
	ft_printf(" Please, check:\n");
	ft_printf("\tYour connexion to minilibX\n");
	ft_printf("\tThat your window has been created correctly\n");
	ft_printf("\tThat your image has been created correctly\n");
	ft_print_footer();
}

static double	ft_atob(char *str, int i)
{
	double		j;
	double		after_comma;

	j = 1;
	after_comma = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		j /= 10;
		after_comma = after_comma + (str[i] - 48) * j;
		i += 1;
	}
	return (after_comma);
}

double	ft_atoi(char *str)
{
	double		before_comma;
	double		after_comma;
	int			sign;
	int			i;

	before_comma = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		str += 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i += 1;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		before_comma = before_comma * 10 + str[i] - 48;
		i += 1;
	}
	if (str[i] == '.')
		i += 1;
	after_comma = ft_atob(str, i);
	return (sign * (before_comma + after_comma));
}

void	ft_to_lower(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i += 1;
	}
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (!s1 || !s2 || n <= 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n)
		i += 1;
	return (s1[i] - s2[i]);
}
