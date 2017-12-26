/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:13:33 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/26 19:06:10 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		ft_pf_parse_width_elif(const char **format, t_format *all, \
				va_list ap, int i)
{
	int			param;
	int			tmp;
	va_list		bp;

	*format = *format + 1;
	va_copy(bp, ap);
	param = ft_pf_parse_parameter(format);
	while (i < param)
	{
		tmp = va_arg(bp, int);
		if (i == (param - 1))
			(*all).width_field = tmp;
		i++;
	}
}

void			ft_pf_parse_width(const char **format, t_format *all, \
				va_list ap)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_strnew(9);
	if (!(*all).parameter_field && **format == '*')
	{
		(*all).width_field = va_arg(ap, int);
		*format = *format + 1;
	}
	else if ((*all).parameter_field && !ft_pf_check_for_type(**format) && \
			!ft_pf_check_for_t_size(**format) && **format == '*')
		ft_pf_parse_width_elif(format, all, ap, i);
	else
	{
		while (!ft_pf_check_for_type(**format) && **format != '.' && \
	!ft_pf_check_for_t_size(**format) && !ft_pf_check_for_big_sdouxc(**format))
		{
			res[i] = **format;
			i++;
			*format = *format + 1;
		}
		(*all).width_field = ft_atoi(res);
	}
	ft_strdel(&res);
}
