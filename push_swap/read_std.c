/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_std.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:23:30 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/27 21:38:02 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*read_std(void)
{
	t_list	*list;
	char	*buf;
	char	*tmp;
	size_t	ret;

	list = NULL;
	while (1)
	{
		buf = (char *)malloc(sizeof(char) * BUF_SIZE);
		if (!buf)
			return (NULL);
		ret = read(0, buf, BUF_SIZE);
		if (ret <= 0)
		{
			free(buf);
			break ;
		}
		buf[ret - 1] = 0;
		tmp = ft_strdup(buf);
		if (!tmp)
			return (NULL);
		ft_lstadd_back(&list, ft_lstnew(tmp));
		free(buf);
	}
	return (list);
}
