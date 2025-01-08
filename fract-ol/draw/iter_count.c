/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:50:29 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/19 22:07:34 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	iter_count_m(t_complex c)
{
	t_complex	z;
	int			i;

	i = 0;
	z.x = 0;
	z.y = 0;
	while (i < MAX_ITER && complex_abs(z) < 2.0)
	{
		z = complex_square(z);
		z.x += c.x;
		z.y += c.y;
		i++;
	}
	return (i);
}

int	iter_count_j(t_complex c, t_display d)
{
	int	i;

	i = 0;
	while (i < MAX_ITER && complex_abs(c) < 2.0)
	{
		c = complex_square(c);
		c.x += d.julia_v.x;
		c.y += d.julia_v.y;
		i++;
	}
	return (i);
}

int	iter_count_b(t_complex c, t_display d)
{
	t_complex	z;
	t_complex	c_pow;
	int			i;

	i = 0;
	z.x = 0;
	z.y = 0;
	while (i < MAX_ITER && complex_abs(z) < 2.0)
	{
		z = complex_pow(z, d.bonus_v.zn);
		c_pow = complex_pow(c, d.bonus_v.cn);
		z.x += c_pow.x;
		z.y += c_pow.y;
		i++;
	}
	return (i);
}

int	iter_count_b2(t_complex c)
{
	t_complex	z;
	int			i;

	i = 0;
	z.x = 0;
	z.y = 0;
	while (i < MAX_ITER && complex_abs(z) < 2.0)
	{
		z.x = fabs(z.x);
		z.y = fabs(z.y);
		z = complex_square(z);
		z.x += c.x;
		z.y += c.y;
		i++;
	}
	return (i);
}
