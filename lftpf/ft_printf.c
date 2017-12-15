/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 13:42:09 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/15 13:50:39 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

int		ft_type(const char *format, va_list ap)
{
	if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(ap, int));
	else if (*format == 'c')
		ft_putchar((char)va_arg(ap, int));
	else if (*format == 's')
		ft_putstr(va_arg(ap, char*));
	else if (*format == '%')
		ft_putchar('%');
	return (1);
}

int		ft_pf_check_for_type(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'f' || c == 'F' || c == 'e' \
	|| c == 'E' || c == 'g' || c == 'G' || c == 'x' || c == 'X' || c == 'o' \
	|| c == 's' || c == 'S' || c == 'c' || c == 'C' || c == 'p' || c == 'a' \
	|| c == 'A' || c == 'n')
		return (1);
	else
		return (0);

}

int		ft_pf_parse_parameter(const char **format)
{
	char	params[3];
	int		i;

	i = 0;
	while ((*format)[i] != '$')
	{
		if (ft_pf_check_for_type((*format)[i]))
			return (0);
		params[i] = (*format)[i];
		i++;
	}
	*format = *format + i + 1;
	return (ft_atoi(params));
}

/*
int		ft_pf_parse(const char *format, va_list ap)
{

}
 * */

int		ft_pf_parse_type(va_list ap, unsigned int parameter_field)
{
	unsigned int		i;
	int					tmp;

	i = 0;
	tmp = 0;
	while (i < parameter_field)
	{
		if (i == (parameter_field - 1))
			ft_putnbr(va_arg(ap, int));
		tmp += va_arg(ap, int);
	}
	return (1);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	t_format	all;

	va_start(ap, format);
	i = 1;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			all.parameter_field = ft_pf_parse_parameter(&format);
			if ((all.parameter_field = ft_pf_parse_parameter(&format)))
				ft_pf_parse_type(ap, all.parameter_field);
			ft_putnbr(all.parameter_field);
			ft_putendl("<--its parameter");
			ft_type(format, ap);
			format++;
		}
		ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (42);
}
