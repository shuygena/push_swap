/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:06:17 by mskeleto          #+#    #+#             */
/*   Updated: 2021/10/07 20:16:15 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

void	ft_pa(t_stack *a, t_stack *b, int val)
{
	ft_push(a, b, val);
}

void	ft_pb(t_stack *a, t_stack *b, int val)
{
	ft_push(b, a, val);
}

void	ft_push(t_stack *dest, t_stack *src, int val)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (src[0].str != NULL)
	{
		while (src[i + 1].str != NULL && i < val)
			i++;
		while (dest[j].str != NULL)
			j++;
		dest[j].str = src[i].str;
		dest[j].id = src[i].id;
		dest[j].number = src[i].number;
		src[i].str = NULL;
		src[i].id = -1;
	}
}
