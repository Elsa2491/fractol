/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 02:39:21 by eltouma           #+#    #+#             */
/*   Updated: 2024/01/30 11:31:30 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_is_double(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i += 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] <= 57) && !(str[i] == '.'))
			return (0);
		i += 1;
	}
	return (1);
}

static int	ft_check_doublon(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j] && !(str[i] >= 48 && str[i] <= 57))
				return (0);
			j += 1;
		}
		i += 1;
	}
	return (1);
}

void	ft_check_param(char **argv)
{
	if (!ft_is_double(argv[2]) || !ft_is_double(argv[3]))
		ft_print_julia_missing_param();
	if (!ft_check_doublon(argv[2]) || !ft_check_doublon(argv[3]))
		ft_print_julia_missing_param();
}
