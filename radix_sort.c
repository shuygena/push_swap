/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:32:38 by mskeleto          #+#    #+#             */
/*   Updated: 2021/10/07 00:22:40 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_radix_sort(t_stack *a, t_stack *b, int val)
{
	int		max_bit;
	t_utils	utils;
	int		i;

	max_bit = ft_find_mb(val - 1);
	utils.bit = -1;
	while (++(utils.bit) < max_bit)
	{
		i = 0;
		while (i++ < val)
			ft_put_elems_to_b(a, b, val, utils);
		while (b[0].str != NULL)
			ft_pa(a, b, val);
	}
	return (0);
}

int	ft_find_mb(int val)
{
	int	max_bit;

	max_bit = 0;
	while (val >> max_bit != 0)
		++max_bit;
	return (max_bit);
}

int	ft_put_elems_to_b(t_stack *a, t_stack *b, int val, t_utils utils)
{
	int	j;
	int	tmp;

	j = 0;
	while (a[j + 1].str != NULL)
		j++;
	tmp = a[j].id;
	if (((tmp >> utils.bit) & 1) == 1)
		ft_ra(a, val);
	else
		ft_pb(a, b, val);
	return (0);
}
