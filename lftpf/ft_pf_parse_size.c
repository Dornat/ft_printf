/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:16:58 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/23 11:41:25 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_pf_parse_size(const char **format, t_format *all)
{
	if (ft_pf_check_for_type(**format))
		return ;
	if ((*format)[0] == 'h' && (*format)[1] == 'h')
	{
		(*all).t_size = hh;
		*format = *format + 2;
		return ;
	}
	else if ((*format)[0] == 'l' && (*format)[1] == 'l')
	{
		(*all).t_size = ll;
		*format = *format + 2;
		return ;
	}
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
	*format = *format + 1;
}
