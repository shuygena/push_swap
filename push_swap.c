/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 00:33:23 by mskeleto          #+#    #+#             */
/*   Updated: 2021/10/07 00:15:03 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_go_to_swap_party(t_stack *a, t_stack *b, int val)
{
	if (!ft_check_sorted(a, val))
	{
		if (val <= 5)
			ft_small_sort(a, b, val);
		else
			ft_radix_sort(a, b, val);
	}
}

int	ft_check_sorted(t_stack *a, int val)
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * (val));
	while (i < val && a[i].str != NULL)
	{
		arr[i] = a[i].number;
		i++;
	}
	ft_resort(arr, val);
	i = 0;
	while (i < val && a[i].str != NULL)
	{
		if (arr[i] != a[i].number)
			return (0);
		i++;
	}
	return (1);
}

void	ft_resort(int *arr, int val)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < val - 1)
	{
		j = 0;
		while (j < val - 1 - i)
		{
			if (arr[j] < arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
