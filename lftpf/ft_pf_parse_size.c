/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:16:58 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/25 20:10:49 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		ft_pf_parse_size_hh(const char **format, t_format *all)
{
	if ((*format)[1] == 'U' || (*format)[1] == 'D')
	{
		(*all).t_size = l;
		*format = *format + 1;
		return ;
	}
	if ((*format)[2] == 'U' || (*format)[2] == 'D')
	{
		(*all).t_size = l;
		*format = *format + 2;
		return ;
	}
	(*all).t_size = hh;
	*format = *format + 2;
}

static void		ft_pf_parse_size_ll(const char **format, t_format *all)
{
	(*all).t_size = ll;
	*format = *format + 2;
}

static void		ft_pf_parse_size_big_sdouxc(const char **format, t_format *all)
{
	(*all).t_size = l;
	*format = *format - 1;
}

static void		ft_pf_parse_size_ifs(const char **format, t_format *all)
{
	if ((*format)[0] == 'h')
		(*all).t_size = h;
	if ((*format)[0] == 'l')
		(*all).t_size = l;
	if ((*format)[0] == 'L')
		(*all).t_size = L;
	if ((*format)[0] == 'z')
		(*all).t_size = z;
	if ((*format)[0] == 'j')
		(*all).t_size = j;
}

void			ft_pf_parse_size(const char **format, t_format *all)
{
	if (ft_pf_check_for_type(**format))
		return ;
	if ((*format)[0] == 'h' && ((*format)[1] == 'h' || \
				(*format)[1] == 'U' || (*format)[1] == 'D'))
	{
		ft_pf_parse_size_hh(format, all);
		return ;
	}
	else if ((*format)[0] == 'l' && (*format)[1] == 'l')
	{
		ft_pf_parse_size_ll(format, all);
		return ;
	}
	ft_pf_parse_size_ifs(format, all);
	if (ft_pf_check_for_big_sdouxc((*format)[0]))
		ft_pf_parse_size_big_sdouxc(format, all);
	*format = *format + 1;
}
