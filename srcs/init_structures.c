/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:44:42 by eltouma           #+#    #+#             */
/*   Updated: 2024/03/18 00:51:18 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    *ft_memset(void *s, int c, unsigned int n)
{
        unsigned char   *fractol;

        fractol = s;
        while (n > 0)
        {
                *(fractol + n - 1) = c;
                n -= 1;
        }
        return (fractol);
}
