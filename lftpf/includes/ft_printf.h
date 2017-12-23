/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 13:40:35 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/22 17:03:53 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libft.h>
# include <stdarg.h>

typedef struct		s_format
{
	unsigned int	parameter_field;
	unsigned int	flag_apostrophe:1;
	unsigned int	flag_minus:1;
	unsigned int	flag_plus:1;
	unsigned int	flag_space:1;
	unsigned int	flag_zero:1;
	unsigned int	flag_hash:1;
	unsigned int	precision_field_identifier:1;
	int				width_field;
	int				precision_field;
	enum			e_size
	{
		hh = 1, h, l, ll, L, z, j,
	}				t_size;
	int				len_of_raw_s;
}					t_format;

/*
** Main functions
*/

int					ft_printf(const char *format, ...);
void				ft_pf_the_center(const char **format, t_format *all, \
					va_list ap, unsigned int *len);
void				ft_pf_put_everything_together(const char **format, \
					t_format *all, va_list ap, unsigned int *len);
void				ft_pf_deal_with_d_i(t_format *all, va_list ap, \
					unsigned int *len);

/*
** Parsing
*/

int					ft_pf_parse_parameter(const char **format);
void				ft_pf_parse_flags(const char **format, t_format *all);
void				ft_pf_parse_width(const char **format, t_format *all, \
					va_list ap);
void				ft_pf_parse_precision(const char **format, t_format *all, \
					va_list ap);
void				ft_pf_parse_size(const char **format, t_format *all);

/*
** >d and i types dealing
*/

char				*ft_pf_res_d_i_raw(t_format *all, va_list ap);
int					ft_pf_normal_d_i(t_format *all, va_list ap);
char				ft_pf_short_short(t_format *all, va_list ap);
short				ft_pf_short(t_format *all, va_list ap);
long long int		ft_pf_long_long(t_format *all, va_list ap);
char				*ft_pf_res_d_i_precision(char *s, t_format *all);
char				*ft_pf_res_d_i_width(char *s, t_format *all);

/*
** >>d and i types flags dealing
*/

char				*ft_pf_res_d_i_flags(char *s, t_format *all);
char				*ft_pf_res_d_i_flags_apostrophe(char *s, t_format *all);
char				*ft_pf_res_d_i_flags_zero(char *s, t_format *all);
char				*ft_pf_res_d_i_flags_plus(char *s, t_format *all);
char				*ft_pf_res_d_i_flags_space(char *s, t_format *all);
char				*ft_pf_res_d_i_flags_minus(char *s, t_format *all);

/*
** Other functions
*/

void				ft_pf_print_unicode(unsigned int b);
void				ft_pf_set_zeros_to_struct_fields(t_format *all);
char				*ft_pf_itoa_long_long(long long int ll);
char				*ft_pf_itoa_unsigned_int(unsigned int ui);
char				*ft_pf_itoa_unsigned_long_long(unsigned long long int ui);
int					ft_pf_check_for_type(char c);
int					ft_pf_check_for_t_size(char c);
int					ft_pf_check_for_flag(char c);
int					ft_pf_find_minus(char *s);
int					ft_pf_find_digit_index(char *s);

#endif
