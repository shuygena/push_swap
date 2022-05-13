/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:20:22 by mskeleto          #+#    #+#             */
/*   Updated: 2021/10/07 19:43:16 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H

# define PS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		id;
	char	*str;
	int		number;
}				t_stack;

typedef struct s_utils
{
	int	bit;
	int	counter;
}				t_utils;

int		main(int argc, char **argv);
int		ft_strlen(const char *s);
int		ft_strdgt(char *str);
int		ft_isint(char *str);
int		ft_isdouble(char **argv, char *str, int index);
int		ft_check_arg(char **argv);
t_stack	*ft_parser(int argc, char **argv);
void	ft_sort(int *arr, int val);
void	ft_define_id(int *arr, t_stack *a, int val);
void	ft_null(t_stack *b, int val);
void	ft_pa(t_stack *a, t_stack *b, int val);
void	ft_pb(t_stack *a, t_stack *b, int val);
void	ft_push(t_stack *dest, t_stack *src, int val);
void	ft_go_to_swap_party(t_stack *a, t_stack *b, int val);
int		ft_check_sorted(t_stack *a, int val);
void	ft_resort(int *arr, int val);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_error(void);
int		ft_radix_sort(t_stack *a, t_stack *b, int val);
int		ft_find_mb(int val);
int		ft_put_elems_to_b(t_stack *a, t_stack *b, int val, t_utils utils);
void	ft_rra(t_stack *a, int val);
void	ft_rrb(t_stack *b, int val);
void	ft_rrr(t_stack *a, t_stack *b, int val);
void	ft_reverse_rotate(t_stack *src, int val);
void	ft_ra(t_stack *src, int val);
int		ft_rb(t_stack *src, int val);
void	ft_rr(t_stack *a, t_stack *b, int val);
void	ft_rotate(t_stack *src, int val);
int		ft_small_sort(t_stack *a, t_stack *b, int val);
void	ft_small_sb(t_stack *b, int val);
void	ft_small_pb(t_stack *a, t_stack *b, int val);
void	ft_sa(t_stack *src, int val);
void	ft_sb(t_stack *src, int val);
void	ft_ss(t_stack *a, t_stack *b, int val);
void	ft_swap(t_stack *source, int val);
int		ft_check_exec(char *line, t_stack *a, t_stack *b, int val);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_zero(char *buffer, int i);
void	ft_free(char ***remain);
int		ft_result(int status);
int		ft_check_remain(char ***line, char **remain);
int		get_next_line(int fd, char **line);
void	*ft_calloc(size_t number, size_t size);
char	*ft_dup(const char *str);
int		ft_nsymbol(char *str);
char	*ft_strjon(char *s1, char *s2);

#endif
