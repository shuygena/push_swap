/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:40:10 by mskeleto          #+#    #+#             */
/*   Updated: 2021/10/06 23:41:15 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

int	ft_check_exec(char *line, t_stack *a, t_stack *b, int val)
{
	if (!ft_strncmp(line, "ra", 3))
		ft_ra(a, val);
	else if (!ft_strncmp(line, "rb", 3))
		ft_rb(b, val);
	else if (!ft_strncmp(line, "rr", 3))
		ft_rr(a, b, val);
	else if (!ft_strncmp(line, "pa", 3))
		ft_pa(a, b, val);
	else if (!ft_strncmp(line, "pb", 3))
		ft_pb(a, b, val);
	else if (!ft_strncmp(line, "sa", 3))
		ft_sa(a, val);
	else if (!ft_strncmp(line, "sb", 3))
		ft_sb(b, val);
	else if (!ft_strncmp(line, "ss", 3))
		ft_ss(a, b, val);
	else if (!ft_strncmp(line, "rra", 4))
		ft_rra(a, val);
	else if (!ft_strncmp(line, "rrb", 4))
		ft_rrb(b, val);
	else if (!ft_strncmp(line, "rrr", 4))
		ft_rrr(a, b, val);
	else
		return (1);
	return (0);
}

int	ft_check_sorted(t_stack *a, int val)
{
	int		i;
	int		*arr;

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

void	ft_grade(t_stack *a, int val)
{
	if (!ft_check_sorted(a, val))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	int		error_count;

	if (argc == 1)
		return (0);
	error_count = 0;
	if (ft_check_arg(argv) == 1)
		ft_error();
	else
	{
		a = ft_parser(argc, argv);
		b = (t_stack *)malloc((argc) * sizeof(t_stack));
		ft_null(b, argc - 1);
		while (get_next_line(0, &line) == 1)
			error_count += ft_check_exec(line, a, b, argc - 1);
		if (error_count > 0)
			ft_error();
		else
			ft_grade(a, argc - 1);
	}
	return (0);
}
