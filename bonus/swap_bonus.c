/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:06:05 by mskeleto          #+#    #+#             */
/*   Updated: 2021/10/07 20:16:57 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

void	ft_sa(t_stack *src, int val)
{
	ft_swap(src, val);
}

void	ft_sb(t_stack *src, int val)
{
	ft_swap(src, val);
}

void	ft_ss(t_stack *a, t_stack *b, int val)
{
	ft_swap(a, val);
	ft_swap(b, val);
}

void	ft_swap(t_stack *source, int val)
{
	t_stack	tmp;
	int		i;

	i = 0;
	if (source[0].str != NULL && source[1].str != NULL)
	{
		while (source[i + 1].str != NULL && i < val)
			i++;
		tmp.number = source[i].number;
		tmp.id = source[i].id;
		tmp.str = source[i].str;
		source[i].number = source[i - 1].number;
		source[i].id = source[i - 1].id;
		source[i].str = source[i - 1].str;
		source[i - 1].number = tmp.number;
		source[i - 1].id = tmp.id;
		source[i - 1].str = tmp.str;
	}
}
