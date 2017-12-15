/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 13:40:35 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/15 13:50:39 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libft.h>
# include <stdarg.h>

typedef struct		s_format
{
	unsigned int	parameter_field;
	unsigned int	flag_minus:1;
	unsigned int	flag_plus:1;
	unsigned int	flag_space:1;
	unsigned int	flag_zero:1;
	unsigned int	flag_hash:1;
	unsigned int	width_field;
	unsigned int	precision_field;
	enum			e_length
	{
		hh = 1, h, l, ll, L, z, j,
	}				t_length;
}					t_format;

enum				e_type
{
	none, percent, d, i, u, f, F, e, E, g, G, x, X, o, s, S, c, C, p, a, A, n,
}					t_type;

int					ft_printf(const char *format, ...);
void				ft_pf_print_unicode(unsigned int b);

#endif
