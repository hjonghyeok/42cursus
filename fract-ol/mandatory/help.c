/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:21:40 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/18 21:56:26 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	help(void)
{
	ft_printf("ex)\t./fract-ol h\n\t./fract-ol m\n\t./fract-ol j -0.8 0.15");
	ft_printf("\n\t./fract-ol b\n\noption:\n");
	ft_printf("\th\tshow this help message and exit\n");
	ft_printf("\tm\tshow Mandelbrot set fractal\n");
	ft_printf("\tj\tshow Julia set fractal\n");
	return (1);
}
