/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:07:37 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/19 00:13:30 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ar_error(void)
{
	ft_printf("fract-ol: error: the following arguments are required\n\n");
	ft_printf("ex)\t./fract-ol h\n\t./fract-ol m\n\t./fract-ol j -0.8 0.15\n");
	ft_printf("\t./fract-ol b 2 2\n");
	return (1);
}

int	no_match(void)
{
	ft_printf("fract-ol: error: no match arguments\n\n");
	ft_printf("ex)\t./fract-ol h\n\t./fract-ol m\n\t./fract-ol j -0.8 0.15\n");
	ft_printf("\t./fract-ol b 2 2\n");
	return (1);
}

int	float_error(void)
{
	ft_printf("fract-ol: error: ");
	ft_printf("your input not float or Incorrect number of arguments\n\n");
	ft_printf("ex)\t./fract-ol h\n\t./fract-ol m\n\t./fract-ol j -0.8 0.15\n");
	ft_printf("\t./fract-ol b 2 2\n");
	return (1);
}

int	int_error(void)
{
	ft_printf("fract-ol: error: ");
	ft_printf("your input not int or Incorrect number of arguments\n\n");
	ft_printf("ex)\t./fract-ol h\n\t./fract-ol m\n\t./fract-ol j -0.8 0.15\n");
	ft_printf("\t./fract-ol b 2 2\n");
	return (1);
}

int	mandelbrot_error(void)
{
	ft_printf("fract-ol: error: Incorrect number of arguments\n\n");
	ft_printf("ex)\t./fract-ol h\n\t./fract-ol m\n\t./fract-ol j -0.8 0.15\n");
	ft_printf("\t./fract-ol b 2 2\n");
	return (1);
}
