/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 13:42:09 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/22 18:16:15 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

void	ft_pf_set_zeros_to_struct_fields(t_format *all)
{
	(*all).parameter_field = 0;
	(*all).flag_apostrophe = 0;
	(*all).flag_minus = 0;
	(*all).flag_plus = 0;
	(*all).flag_space = 0;
	(*all).flag_zero = 0;
	(*all).flag_hash = 0;
	(*all).precision_field_identifier = 0;
	(*all).width_field = 0;
	(*all).precision_field = 0;
	(*all).t_size = 0;
	(*all).len_of_raw_s = 0;
}

void	ft_pf_put_everything_together(const char **format, t_format *all, \
		va_list ap, unsigned int *len)
{
	if (**format == 'd' || **format == 'i')
		ft_pf_deal_with_d_i(all, ap, len);
	*format = *format + 1;
}

void	ft_pf_the_center(const char **format, t_format *all, va_list ap, \
		unsigned int *len)
{
	ft_pf_set_zeros_to_struct_fields(all);
	(*all).parameter_field = ft_pf_parse_parameter(format);
	ft_pf_parse_flags(format, all);
	ft_pf_parse_width(format, all, ap);
	ft_pf_parse_precision(format, all, ap);
	ft_pf_parse_size(format, all);
	ft_pf_put_everything_together(format, all, ap, len);
}

int		ft_printf(const char *format, ...)
{
	va_list					ap;
	t_format				all;
	unsigned int			len;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		while (*format == '%')
		{
			format++;
			ft_pf_the_center(&format, &all, ap, &len);
		}
		if (!*format)
			break ;
		ft_putchar(*format);
		format++;
		len++;
	}
	va_end(ap);
	return (len);
}
