/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:23:45 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/19 00:56:01 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	complex_abs(t_complex c)
{
	return (sqrt(c.x * c.x + c.y * c.y));
}

t_complex	complex_square(t_complex c)
{
	t_complex	result;

	result.x = c.x * c.x - c.y * c.y;
	result.y = 2 * c.x * c.y;
	return (result);
}

t_complex	complex_square2(t_complex a, t_complex b)
{
	t_complex	result;

	result.x = a.x * b.x - a.y * b.y;
	result.y = a.x * b.y + a.y * b.x;
	return (result);
}

t_complex	complex_pow(t_complex c, int n)
{
	t_complex	result;
	t_complex	base;

	result.x = 1.0;
	result.y = 0.0;
	base = c;
	while (n > 0)
	{
		if (n % 2 == 1)
			result = complex_square2(result, base);
		base = complex_square2(base, base);
		n /= 2;
	}
	return (result);
}
