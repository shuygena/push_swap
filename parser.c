/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:17:48 by mskeleto          #+#    #+#             */
/*   Updated: 2021/10/06 19:21:31 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_stack	*ft_parser(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	int		*arr;
	int		j;

	i = 0;
	j = argc - 1;
	a = (t_stack *)malloc((argc) * sizeof(t_stack));
	arr = (int *)malloc(sizeof(int) * (argc - 1));
	while (i < argc - 1)
	{
		a[i].str = argv[j];
		a[i].number = ft_atoi(argv[j]);
		arr[i] = a[i].number;
		i++;
		j--;
	}
	a[i].str = NULL;
	ft_sort(arr, argc - 1);
	ft_define_id(arr, a, argc - 1);
	free(arr);
	return (a);
}

void	ft_sort(int *arr, int val)
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
			if (arr[j] > arr[j + 1])
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

void	ft_define_id(int *arr, t_stack *a, int val)
{
	int	i;
	int	j;

	i = 0;
	while (i < val)
	{
		j = 0;
		while (j < val)
		{
			if (arr[i] == a[j].number)
				a[j].id = i;
			j++;
		}
		i++;
	}
}

void	ft_null(t_stack *b, int val)
{
	int	i;

	i = 0;
	while (i < val)
	{
		b[i].str = NULL;
		b[i].id = -1;
		i++;
	}
	b[i].str = NULL;
	b[i].id = -1;
}
