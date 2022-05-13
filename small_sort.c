/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:10:20 by mskeleto          #+#    #+#             */
/*   Updated: 2021/10/07 00:26:36 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_small_sort(t_stack *a, t_stack *b, int val)
{
	int	i;

	i = 0;
	ft_small_pb(a, b, val);
	ft_small_sb(b, val);
	if (a[1].id == val - 1)
		ft_rra(a, val);
	else if (a[0].id != val - 1)
		ft_ra(a, val);
	if ((val == 2 || val == 3) && ft_check_sorted(a, val))
		return (0);
	if (!ft_check_sorted(a, 3))
		ft_sa(a, val);
	while (i < val - 3)
	{
		ft_pa(a, b, val);
		i++;
	}
	return (0);
}

void	ft_small_sb(t_stack *b, int val)
{
	if (val == 5 && b[0].id != 0)
		ft_sb(b, val);
}

void	ft_small_pb(t_stack *a, t_stack *b, int val)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	while (i < val && count < val - 3)
	{
		j = 0;
		while (a[j + 1].str != NULL)
			j++;
		if (a[j].id < val - 3)
		{
			ft_pb(a, b, val);
			count++;
		}
		else
			ft_ra(a, val);
		i++;
	}
}
