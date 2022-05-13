/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 20:12:17 by mskeleto          #+#    #+#             */
/*   Updated: 2021/10/06 19:15:22 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

void	ft_ra(t_stack *src, int val)
{
	ft_rotate(src, val);
}

int	ft_rb(t_stack *src, int val)
{
	ft_rotate(src, val);
	return (1);
}

void	ft_rr(t_stack *a, t_stack *b, int val)
{
	ft_rotate(a, val);
	ft_rotate(b, val);
}

void	ft_rotate(t_stack *src, int val)
{
	t_stack	tmp;
	int		i;

	i = 0;
	if (src[0].str != NULL && src[1].str != NULL)
	{
		while (i < val && src[i].str != NULL)
			i++;
		tmp.str = src[i - 1].str;
		tmp.id = src[i - 1].id;
		tmp.number = src[i - 1].number;
		while (i-- > 1)
		{
			src[i].str = src[i - 1].str;
			src[i].id = src[i - 1].id;
			src[i].number = src[i - 1].number;
		}
		src[0].str = tmp.str;
		src[0].id = tmp.id;
		src[0].number = tmp.number;
	}
}
