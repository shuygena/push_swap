/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 20:12:59 by mskeleto          #+#    #+#             */
/*   Updated: 2021/10/06 19:17:17 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

void	ft_rra(t_stack *a, int val)
{
	ft_reverse_rotate(a, val);
}

void	ft_rrb(t_stack *b, int val)
{
	ft_reverse_rotate(b, val);
}

void	ft_rrr(t_stack *a, t_stack *b, int val)
{
	ft_reverse_rotate(a, val);
	ft_reverse_rotate(b, val);
}

void	ft_reverse_rotate(t_stack *src, int val)
{
	t_stack	tmp;
	int		i;

	i = 0;
	if (src[0].str != NULL && src[1].str != NULL)
	{
		tmp.str = src[i].str;
		tmp.number = src[i].number;
		tmp.id = src[i].id;
		while (i < val - 1 && src[i + 1].str != NULL)
		{
			src[i].str = src[i + 1].str;
			src[i].number = src[i + 1].number;
			src[i].id = src[i + 1].id;
			i++;
		}
		src[i].str = tmp.str;
		src[i].number = tmp.number;
		src[i].id = tmp.id;
	}
}
