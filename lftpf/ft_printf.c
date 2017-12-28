/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 13:42:09 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/28 16:29:33 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_pf_put_everything_together(const char **format, t_format *all, \
		va_list ap, unsigned int *len)
{
	if (!ft_pf_check_for_every_type(**format))
		ft_pf_deal_with_shitty_type(format, all, ap, len);
	if (**format == '%')
		ft_pf_deal_with_percent(format, all, ap, len);
	if (**format == 'd' || **format == 'i' || **format == 'D')
		ft_pf_deal_with_d_i(all, ap, len);
	if (**format == 'u' || **format == 'U')
		ft_pf_deal_with_u(all, ap, len);
	if (**format == 'o' || **format == 'O')
		ft_pf_deal_with_o(all, ap, len);
	if (**format == 'x' || **format == 'X')
	{
		if (**format == 'X')
			(*all).big_x = 1;
		ft_pf_deal_with_x(all, ap, len);
	}
	if (**format == 'p')
		ft_pf_deal_with_p(all, ap, len);
	if (**format == 'c' || **format == 'C')
		ft_pf_deal_with_c(all, ap, len);
	if (**format)
		*format = *format + 1;
}

int		ft_pf_check_for_the_center(char c)
{
	if ((!ft_isdigit(c) && !ft_pf_check_for_flag(c) && c != '.' && \
		!ft_pf_check_for_t_size(c) && !ft_pf_check_for_big_sdouxc(c) && \
		c != '*') || ft_pf_check_for_every_type(c))
		return (0);
	return (1);
}

int		ft_cfbt(char c)
{
	if (c == 'D' || c == 'U' || c == 'O' || c == 'C' || c == 'S')
		return (1);
	return (0);
}

void	ft_pf_the_center(const char **format, t_format *all, va_list ap, \
		unsigned int *len)
{
	ft_pf_set_zeros_to_struct_fields(all);
	while (ft_pf_check_for_the_center(**format))
	{
		(*all).parameter_field = ft_pf_parse_parameter(format);
		ft_pf_parse_flags(format, all);
		ft_pf_parse_width(format, all, ap);
		ft_pf_parse_precision(format, all, ap);
		ft_pf_parse_size(format, all);
	}
	if (ft_cfbt(**format))
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
